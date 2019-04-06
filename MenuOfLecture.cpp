#include"MenuOfLecture.h"

void MenuOfLecturer::initGraphics() {
	loadTexture("course.png", CourseTexture);
	loadTexture("attendanceList.png", AttendanceListTexture);
	loadTexture("scoreBoard.png", ScoreBoardTexture);
	loadFont("VNI-Avo.TTF", font);
	loadTexture("view.png", viewTexture);
	loadTexture("edit.png", editTexture);
	
	course.setTexture(CourseTexture);
	course.setPosition(40, 224);

	Attendance_List.setTexture(AttendanceListTexture);
	Attendance_List.setPosition(40, 318);

	Score_Board.setTexture(ScoreBoardTexture);
	Score_Board.setPosition(40, 415);

	viewStudent.setTexture(viewTexture);
	viewStudent.setPosition(408, 100);

	updateText(instruction, font, sf::Color::White, 408, 100, 30);
	updateText(LecturerText, font, sf::Color::White, 408, 140, 30);

}

void MenuOfLecturer::render(sf::RenderWindow &window, string nowLecturer, vector<CourseGraphic> & courseGraphic, vector<ScoreGraphic> & scoreGraphic, 
	vector<AttendanceGraphic> &attendanceGraphic, vector<StudentGraphic> &studentGraphic) {
	window.draw(course);
	window.draw(Attendance_List);
	window.draw(Score_Board);
	if (nowLecturer == "course")
	{
		renderTableCourse(window, courseGraphic);
		//window.draw(viewStudent);
		return;
	}
	if (nowLecturer == "student view")
	{
		renderTableCourse_Student(window, studentGraphic);
		return;
	}
	if (nowLecturer == "score view" || nowLecturer == "score" || nowLecturer == "scorecourseID" || nowLecturer == "scorestudentID" || nowLecturer == "what" || nowLecturer == "grade") {
		window.draw(instruction);
		window.draw(LecturerText);
		renderTableScore(window, scoreGraphic);
		return;
	}
	if (nowLecturer == "attendancelist view" || nowLecturer == "attendancelist" || nowLecturer == "courseID" || nowLecturer == "studentID") {
		window.draw(instruction);
		window.draw(LecturerText);
		renderTableAttendance(window, attendanceGraphic);
		return;
	}
}

string MenuOfLecturer::handleEvent(sf::Event event, string &nowLecturer, vector<CourseGraphic> & courseGraphic) {
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		if (course.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
			courseID = "";
			return "course";
		}
		if (Attendance_List.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
		{
			return "attendancelist";
		}
		if (Score_Board.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
			return "scoreboard";
		}
		if (nowLecturer == "course") {
			for (int i = 0; i < courseGraphic.size(); i++) {
				if (courseGraphic[i].ID.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					courseID = courseGraphic[i].ID.getString();
					return "student";
				}
			}
		}
		return "anywhere";
	}
	if (event.type == sf::Event::TextEntered)
	{
		if (nowLecturer == "courseID") {
			if (event.text.unicode == 13) {
				LecturerText.setString(LecturerEnter);
				return "courseID done";
			}
			updateString(LecturerEnter, event);
			LecturerText.setString(LecturerEnter + "|");
			return "courseID";
		}
		if (nowLecturer == "studentID") {
			if (event.text.unicode == 13) {
				LecturerText.setString(LecturerEnter);
				return "studentID done";
			}
			updateString(LecturerEnter, event);
			LecturerText.setString(LecturerEnter + "|");
			return "studentID";
		}
		if (nowLecturer == "scorecourseID") {
			if (event.text.unicode == 13) {
				LecturerText.setString(LecturerEnter);
				return "scorecourseID done";
			}
			updateString(LecturerEnter, event);
			LecturerText.setString(LecturerEnter + "|");
			return "scorecourseID";
		}
		if (nowLecturer == "scorestudentID") {
			if (event.text.unicode == 13) {
				LecturerText.setString(LecturerEnter);
				return "scorestudentID done";
			}
			updateString(LecturerEnter, event);
			LecturerText.setString(LecturerEnter + "|");
			return "scorestudentID";
		}
		if (nowLecturer == "what") {
			if (event.text.unicode == 13) {
				LecturerText.setString(LecturerEnter);
				return "what done";
			}
			updateString(LecturerEnter, event);
			LecturerText.setString(LecturerEnter + "|");
			return "what";
		}
		if (nowLecturer == "grade") {
			if (event.text.unicode == 13) {
				LecturerText.setString(LecturerEnter);
				return "grade done";
			}
			updateString(LecturerEnter, event);
			LecturerText.setString(LecturerEnter + "|");
			return "grade";
		}
	}
	
}

void MenuOfLecturer::logic(Time time, Account&Acc, string & nowLecturer, ArrayOfCourse &course, vector<AttendanceList> &attendanceList,
	vector<ScoreBoard>& score, vector<CourseGraphic> & courseGraphic, vector<ScoreGraphic> & scoreGraphic, vector<AttendanceGraphic> & attendanceGraphic, 
	vector<StudentGraphic> & studentGraphic, ArrOfAccount &account)
{
	if (nowLecturer == "course")
	{
		courseGraphic.clear();
		initTableCourse(font, courseGraphic, Acc);
		nowLecturer == "course view";
		return;
	}
	if (nowLecturer == "student")
	{
		vector<Course> arr;
		arr = Acc.returnCourses();
		studentGraphic.clear();
		for (int i = 0; i < arr.size(); i++)
			initTableCourse_Student(font, studentGraphic, arr[i].getID(), account);
		nowLecturer = "student view";
		return;
	}
	if (nowLecturer == "scoreboard")
	{
		instruction.setString("Enter courseID: ");
		LecturerEnter = "";
		LecturerText.setString("|");
		nowLecturer = "scorecourseID";
		courseID = "";
		scoreGraphic.clear();
		studentID = "";
		return;
	}
	if (nowLecturer == "scorecourseID done")
	{
		courseID = LecturerEnter;
		scoreGraphic.clear();
		initTableScore(font, scoreGraphic, score, course, courseID); //
		instruction.setString("Enter studentID: ");
		LecturerEnter = "";
		LecturerText.setString("|");
		nowLecturer = "scorestudentID";
		return;
	}
	if (nowLecturer == "scorestudentID done")
	{
		studentID = LecturerEnter;
		if (!Acc.isMatchCourse(courseID)) {
			instruction.setString("Enter courseID: ");
			LecturerEnter = "";
			LecturerText.setString("|");
			nowLecturer = "scorestudentID";
			return;
		}
		//initTableScore(font, scoreGraphic, score, course, courseID);
		instruction.setString("Enter what to change: ");
		LecturerEnter = "";
		LecturerText.setString("|");
		nowLecturer = "what";
		return;
	}
	if (nowLecturer == "what done") {
		what = LecturerEnter;
		//initTableScore(font, scoreGraphic, score, course, courseID);
		instruction.setString("Enter grade: ");
		LecturerEnter = "";
		LecturerText.setString("|");
		nowLecturer = "grade";
		return;
	}
	if (nowLecturer == "grade done") {
		grade = LecturerEnter;
		float pp = stof(grade);
		//initTableScore(font, scoreGraphic, score, course, courseID);//
		updateScore(score, courseID, studentID, what, pp);
		LecturerEnter = "";
		LecturerText.setString("");
		scoreGraphic.clear();
		initTableScore(font, scoreGraphic, score, course, courseID); //
		nowLecturer = "score view";
		instruction.setString("");
		return;
	}
	if (nowLecturer == "attendancelist")
	{
		//initTableAttendance(font, attendanceGraphic, attendanceList, course, courseID); //
		instruction.setString("Enter courseID: ");
		courseID = "";
		attendanceGraphic.clear();
		LecturerEnter = "";
		LecturerText.setString("|");
		nowLecturer = "courseID";
		return;
	}
	if (nowLecturer == "courseID done")
	{
		courseID = LecturerEnter;
		attendanceGraphic.clear();
		initTableAttendance(font, attendanceGraphic, attendanceList, course, courseID); //
		instruction.setString("Enter studentID: ");
		LecturerEnter = "";
		LecturerText.setString("|");
		nowLecturer = "studentID";
		return;
	}
	if (nowLecturer == "studentID done")
	{
		studentID = LecturerEnter;
		if (!Acc.isMatchCourse(courseID)) {
			instruction.setString("Enter studentID: ");
			LecturerEnter = "";
			LecturerText.setString("|");
			nowLecturer = "studentID";
			return;
		}
		string week = "";
		convertIntToString(time.getWeek(), week);
		LecturerEnter = "";
		LecturerText.setString("|");
		updateAttendance(attendanceList, studentID, courseID, time.getWeek(), time);
		attendanceGraphic.clear();
		initTableAttendance(font, attendanceGraphic, attendanceList, course, courseID); //
		nowLecturer = "studentID";
	}
}
