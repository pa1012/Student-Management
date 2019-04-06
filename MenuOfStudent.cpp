#include"MenuStudent.h"

void MenuOfStudent::initGraphics() {
	loadTexture("checkIn.png", checkInTexture);
	loadTexture("schedule.png", scheduleTexture);
	loadTexture("score.png", scoreTexture);
	

	checkIn.setTexture(checkInTexture);
	checkIn.setPosition(40, 117);

	schedule.setTexture(scheduleTexture);
	schedule.setPosition(40, 224);

	score.setTexture(scoreTexture);
	score.setPosition(40, 318);

	loadFont("VNI-Avo.TTF", font);
	updateText(instruction, font, sf::Color::White, 408, 170, 30);
	updateText(studentText, font, sf::Color::White, 408, 220, 30);
}

void MenuOfStudent::render(sf::RenderWindow &window,string nowStudent, vector<CourseGraphic> & courseGraphic, vector<ScoreGraphic> & scoreGraphic, vector<AttendanceGraphic> &attendanceGraphic) {
	window.draw(checkIn);
	window.draw(schedule);
	window.draw(score);
	if (nowStudent == "schedule view") {
		renderTableCourse(window, courseGraphic);
		return;
	}
	if (nowStudent == "score view") {
		renderTableScore(window, scoreGraphic);
		return;
	}
	if (nowStudent == "check-in" || nowStudent == "checkin view" || nowStudent == "courseID") {
		window.draw(instruction);
		window.draw(studentText);
		renderTableAttendance(window, attendanceGraphic);
		return;
	}
}

string MenuOfStudent::handleEvent(sf::Event event,string nowStudent) {
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		if (checkIn.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
			return "check-in";
		}
		if (schedule.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
		{
			return "schedule";
		}
		if (score.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
			return "score";
		}
		return "anywhere";
	}
	if (event.type == sf::Event::TextEntered) {
		if (nowStudent == "courseID") {
			if (event.text.unicode == 13) {
			 studentText.setString(studentEnter);
				return "courseID done";
			}
			updateString(studentEnter, event);
			studentText.setString(studentEnter + "|");
			return "courseID";
		}
	}
	
}

void MenuOfStudent::logic(Time time,Account&Acc,string & nowStudent,ArrayOfCourse &course, vector<AttendanceList> & attendanceList,vector<ScoreBoard> &score, vector<CourseGraphic> & courseGraphic, vector<ScoreGraphic> & scoreGraphic,vector<AttendanceGraphic> & attendanceGraphic)
{
	if (nowStudent == "schedule")
	{

		courseGraphic.clear();
		initTableCourse(font, courseGraphic, Acc);
		nowStudent = "schedule view";
		return;
	}
	if (nowStudent == "score")
	{
		scoreGraphic.clear();
		initTableScore(font, scoreGraphic, score, Acc);
		nowStudent = "score view";
		return;
	}
	if (nowStudent == "check-in")
	{
		attendanceGraphic.clear();
		initTableAttendance(font, attendanceGraphic, attendanceList, Acc);
		instruction.setString("Enter courseID: ");
		studentEnter = "";
		studentText.setString("|");
		nowStudent = "courseID";
		return;
	}
	
	if (nowStudent == "courseID done")
	{
		courseID = studentEnter;
		if (!Acc.isMatchCourse(courseID)) {
			instruction.setString("Enter courseID: ");
			studentEnter = "";
			studentText.setString("|");
			nowStudent = "courseID";
			return;
		}
		string week = "";
		convertIntToString(time.getWeek(),week);
		instruction.setString("You checked in week " + week+ " of course " + courseID);
		studentEnter = "";
		studentText.setString("");
		updateAttendance(attendanceList, Acc.getID(), courseID, time.getWeek(),time);
		attendanceGraphic.clear();
		initTableAttendance(font, attendanceGraphic, attendanceList, Acc);
		nowStudent = "checkin view";
	}
}