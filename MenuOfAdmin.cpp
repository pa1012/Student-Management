#include"MenuOfAdmin.h"

void MenuOfAdmin::initGraphics(ArrayOfClass Classes) {
	loadTexture("class.png", classTexture);
	loadTexture("course.png", courseTexture);
	loadTexture("scoreBoard.png", scoreBoardTexture);
	loadTexture("attendanceList.png", attendanceListTexture);
	loadFont("VNI-Avo.TTF", font);
	loadTexture("importAClass.png", importAClassTexture);
	loadTexture("add.png", addTexture);
	loadTexture("edit.png", editTexture);
	loadTexture("remove.png", removeTexture);
	loadTexture("changeClass.png", changeClassTexture);
	loadTexture("create.png", createTexture);
	loadTexture("delete.png", deleteTexture);
	loadTexture("view.png", viewTexture);
	loadTexture("update.png", updateTexture);
	loadTexture("lecturer.png", lecturerTexture);
	loadTexture("addClass.png", addClassTexture);

	addClass.setTexture(addClassTexture);

	updateText(instruction, font, sf::Color::White, 408, 170, 30);
	updateText(adminText, font, sf::Color::White, 408, 220, 30);

	add.setTexture(addTexture);
	add.setPosition(408, 100);

	edit.setTexture(editTexture);
	edit.setPosition(595, 100);

	remove.setTexture(removeTexture);
	remove.setPosition(782, 100);

	changeClass.setTexture(changeClassTexture);
	changeClass.setPosition(971, 100);

	importAClass.setTexture(importAClassTexture);
	importAClass.setPosition(432, 126);

	classes.setTexture(classTexture);
	classes.setPosition(40, 126);

	course.setTexture(courseTexture);
	course.setPosition(40, 224);
	
	create.setTexture(createTexture);
	create.setPosition(408, 100);

	deleteS.setTexture(deleteTexture);
	deleteS.setPosition(595, 100);

	view.setTexture(viewTexture);
	view.setPosition(782, 100);

	update.setTexture(updateTexture);
	update.setPosition(971, 100);

	scoreBoard.setTexture(scoreBoardTexture);
	scoreBoard.setPosition(40, 318);

	attendanceList.setTexture(attendanceListTexture);
	attendanceList.setPosition(40, 415);

	lecturer.setTexture(lecturerTexture);
	lecturer.setPosition(40, 514);

	createLecturer.setTexture(addTexture);
	createLecturer.setPosition(408, 100);

	deleteLecturer.setTexture(removeTexture);
	deleteLecturer.setPosition(595, 100);

	updateLecturer.setTexture(editTexture);
	updateLecturer.setPosition(782, 100);

	sf::Text newText;

	newText.setPosition(432, 200);
	newText.setCharacterSize(30);
	newText.setFillColor(sf::Color::White);
	newText.setFont(font);
	newText.setString(Classes.getName(0));

	nameOfClass.push_back(newText);

	for (int i = 1; i < Classes.getSize(); i++) {
		newText.setPosition(nameOfClass[i - 1].getPosition().x, nameOfClass[i - 1].getPosition().y + 60);
		newText.setString(Classes.getName(i));
		nameOfClass.push_back(newText);
	}

	nameAddClass = "";

	nameNewClass.setPosition(432, nameOfClass[nameOfClass.size() - 1].getPosition().y + 60);
	nameNewClass.setFillColor(sf::Color::White);
	nameNewClass.setCharacterSize(30);
	nameNewClass.setFont(font);
	nameNewClass.setString(nameAddClass);
}

void MenuOfAdmin::render(sf::RenderWindow &window, string nowAdmin, ArrOfAccount Acc, ArrayOfClass Classes, vector<AccountGraphic> &accountGraphic, vector<CourseGraphic> &courseGraphic, vector<StudentGraphic> & studentGraphic , vector<ScoreGraphic> & scoreGraphic, vector <AttendanceGraphic> &attendanceGraphic) {
	window.draw(classes);
	window.draw(course);
	window.draw(scoreBoard);
	window.draw(attendanceList);
	window.draw(lecturer);
	if (nowAdmin == "class" || nowAdmin == "import a class" || nowAdmin == "import success") {
		for (int i = 0; i < nameOfClass.size(); i++)
			window.draw(nameOfClass[i]);
		window.draw(importAClass);
		window.draw(adminText);
		return;
	}

	if (nowAdmin == "view class" || nowAdmin == "add student" || nowAdmin == "student ID class" || nowAdmin == "what to change" ||
		nowAdmin == "enter inform" || nowAdmin == "edit done" || nowAdmin == "remove student" || nowAdmin == "remove student done" ||
		nowAdmin == "change class" || nowAdmin == "class to change" || nowAdmin == "change class done") {
		window.draw(add);
		window.draw(edit);
		window.draw(remove);
		window.draw(changeClass);
		{
			window.draw(instruction);
			window.draw(adminText);
		}
		renderTableClass(window, accountGraphic);
		return;
	}

	if (nowAdmin == "course term done" || nowAdmin == "course" || nowAdmin == "course year" || nowAdmin == "course term" || nowAdmin == "course year done") {
		window.draw(instruction);
		window.draw(adminText);
		return;
	}
	if (nowAdmin == "course options" || nowAdmin =="enter course" || nowAdmin == "remove course" || nowAdmin == "remove course ID"  ||
		nowAdmin == "edit course?" || nowAdmin =="edit course ID" || nowAdmin =="course what?"  ) {
		window.draw(create);
		window.draw(deleteS);
		window.draw(edit);
		window.draw(add);
		window.draw(remove);
		window.draw(instruction);
		window.draw(adminText);
		renderTableCourse(window, courseGraphic);
		return;
	}
	
	

	if (nowAdmin == "lecturer" || nowAdmin == "create Lecturer" || nowAdmin == "create Lecturer success" || nowAdmin == "change Lecturer" ||
		nowAdmin == "enter Lecturer inform" || nowAdmin == "edit Lecturer done" || nowAdmin == "delete Lecturer" || nowAdmin == "delete Lecturer success" ||
		nowAdmin == "update Lecturer" || nowAdmin == "update Lecturer success")
	{
		window.draw(createLecturer);
		window.draw(deleteLecturer);
		window.draw(updateLecturer);
		window.draw(instruction);
		window.draw(adminText);
		renderTableLecturer(window, accountGraphic);
		return;
	}

	if (nowAdmin == "view student" || nowAdmin == "add st -> course" || nowAdmin == "remove st fr course" || nowAdmin == "add a class" ||
		nowAdmin == "+ st ID" || nowAdmin == "- st ID" || nowAdmin == "+ class") {
		window.draw(instruction);
		window.draw(adminText);
		window.draw(add);
		window.draw(remove);
		window.draw(addClass);
		renderTableCourse_Student(window, studentGraphic);
		return;
	}
	if (nowAdmin == "score" || nowAdmin == "score course ID" || nowAdmin == "scoreboard view") {
		window.draw(instruction);
		window.draw(adminText);
		renderTableScore(window, scoreGraphic);
	}
	if (nowAdmin == "attendance" || nowAdmin == "attend course ID" || nowAdmin == "attend view") {
		window.draw(instruction);
		window.draw(adminText);
		renderTableAttendance(window, attendanceGraphic);
	}
}

string MenuOfAdmin::handleEvent(sf::Event event, string nowAdmin, ArrOfAccount Acc, vector<AccountGraphic> & accountGraphic, ArrayOfCourse courses, vector<CourseGraphic> & courseGraphic, vector<StudentGraphic> & studentGraphic) {
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		if (nowAdmin == "anywhere") {
			if (classes.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				return "class";
			}
			if (course.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			{
				return "course";
			}
			if (scoreBoard.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				return "scoreboard";
			}
			if (attendanceList.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				return "attendance";
			}
			if (lecturer.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				accountGraphic.clear();
				initTableLecturer(font, accountGraphic, Acc);
				return "lecturer";
			}
		}

		if (nowAdmin == "class") {
			adminText.setString("");
			updateText(adminText, font, sf::Color::White, 432, nameOfClass[nameOfClass.size() - 1].getPosition().y + 60, 30);
			if (importAClass.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				adminEnter = "";
				adminText.setString("|");
				return "import a class";
			}
			for (int i = 0; i < nameOfClass.size(); i++)
				if (nameOfClass[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					initTableClass(font, accountGraphic, nameOfClass[i].getString(), Acc);
					classNow = nameOfClass[i].getString();
					return "view class";
				}
		}

		if (nowAdmin == "course options") {
			if (create.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				return "create course";
			}
			if (deleteS.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				return "delete course";
			}
			if (add.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				return "add course";
			}
			if (remove.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				return "remove course";
			}
			if (edit.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				return "edit course";
			}
			for (int i = 0; i < courseGraphic.size(); i++)
			{
				if (courseGraphic[i].ID.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					initTableCourse_Student(font, studentGraphic, courseGraphic[i].ID.getString(), Acc);
					courseID = courseGraphic[i].ID.getString();
					return "view student";
				}
			}
		}

		if (nowAdmin == "view class") {
			updateText(instruction, font, sf::Color::White, 408, 170, 30);
			updateText(adminText, font, sf::Color::White, 408, 220, 30);
			instruction.setString("");
			adminText.setString("");
			if (add.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				instruction.setString("Enter information: ID,Last name,First name,Gender,DoB: ");
				adminEnter = "";
				adminText.setString("|");
				return "add student";
			}
			if (edit.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				instruction.setString("Enter student ID you want to edit: ");
				adminEnter = "";
				adminText.setString("|");
				return "student ID class";
			}
			if (remove.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				instruction.setString("Enter student ID you want to remove: ");
				adminEnter = "";
				adminText.setString("|");
				return "remove student";
			}
			if (changeClass.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				instruction.setString("Enter student ID you want to change class: ");
				adminEnter = "";
				adminText.setString("|");
				return "change class";
			}
		}

		if (nowAdmin == "lecturer")
		{
			updateText(instruction, font, sf::Color::White, 408, 170, 30);
			updateText(adminText, font, sf::Color::White, 408, 220, 30);
			instruction.setString("");
			adminText.setString("");
			if (createLecturer.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				instruction.setString("Enter information: ID,Last name,First name,Gender,DoB: ");
				adminEnter = "";
				adminText.setString("|");
				cout << instruction.getString().toAnsiString() << endl;
				return "create Lecturer";
			}
			if (updateLecturer.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				instruction.setString("Enter lecturer ID you want to edit: ");
				adminEnter = "";
				adminText.setString("|");
				return "update Lecturer";
			}
			if (deleteLecturer.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				instruction.setString("Enter lecturer ID you want to remove: ");
				adminEnter = "";
				adminText.setString("|");
				return "delete Lecturer";
			}
		}

		if (nowAdmin == "view student") {
			if (add.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			{
				return "add st -> course";
			}
			if (remove.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				return "remove st fr course";
			}
			if (addClass.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				return "add a class";
			}
		}
		return "anywhere";
	}
	if (event.type == sf::Event::TextEntered) {

		if (nowAdmin == "import a class") {
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				return "import class success";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "import a class";
		}
		if (nowAdmin == "add student") {
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				return "add student success";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "add student";
		}
		if (nowAdmin == "student ID class") {
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				return "student ID class success";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "student ID class";
		}
		if (nowAdmin == "what to change") {
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				return "edit";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "what to change";
		}
		if (nowAdmin == "enter inform") {
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				return "edit done";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "enter inform";
		}
		if (nowAdmin == "remove student") {
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				return "remove student done";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "remove student";
		}
		if (nowAdmin == "change class") {
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				return "ID change class";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "change class";
		}
		if (nowAdmin == "class to change") {
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				return "change class done";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "class to change";
		}
		if (nowAdmin == "course year") {
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				return "course year done";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "course year";
		}
		if (nowAdmin == "course term") {
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				cout << adminEnter << endl;
				return "course term done";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "course term";
		}
		if (nowAdmin == "enter course") {
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				cout << adminEnter << endl;
				return "enter course success";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "enter course";
		}
		if (nowAdmin == "create Lecturer")
		{
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				return "create Lecturer success";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "create Lecturer";
		}
		if (nowAdmin == "update Lecturer")
		{
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				return "update Lecturer success";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "update Lecturer";
		}
		if (nowAdmin == "delete Lecturer")
		{
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				return "delete Lecturer success";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "delete Lecturer";
		}
		if (nowAdmin == "change Lecturer")
		{
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				return "edit Lecturer";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "change Lecturer";
		}
		if (nowAdmin == "enter Lecturer inform")
		{
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				return "edit Lecturer done";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "enter Lecturer inform";
		}
		if (nowAdmin == "remove course ID") {
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				return "remove course done";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "remove course ID";
		}
		if (nowAdmin == "edit course ID") {
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				return "course ID done";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "edit course ID";
		}
		if (nowAdmin == "edit course?") {
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				return "course ? done";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "edit course?";
		}
		if (nowAdmin == "course what?") {
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				return "course what? done";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "course what?";
		}
		if (nowAdmin == "+ st ID") {
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				return "+ st ID done";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "+ st ID";
		}
		if (nowAdmin == "- st ID") {
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				return "- st ID done";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "- st ID";
		}
		if (nowAdmin == "+ class") {
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				return "+ class done";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "+ class";
		}
		if (nowAdmin == "score course ID") {
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				return "score done";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "score course ID";
		}
		if (nowAdmin == "attend course ID") {
			if (event.text.unicode == 13) {
				adminText.setString(adminEnter);
				return "attend done";
			}
			updateString(adminEnter, event);
			adminText.setString(adminEnter + "|");
			return "attend course ID";
		}
	}
}

void MenuOfAdmin::logic(string &nowAdmin,Time time, ArrayOfClass &Classes, ArrOfAccount &Acc, ArrayOfCourse &course,vector<ScoreBoard> &scoreBoard,vector<AttendanceList> &attendanceList, vector<AccountGraphic>  &accountGraphic,vector<CourseGraphic> &courseGraphic, vector<StudentGraphic> &studentGraphic , vector<ScoreGraphic> &scoreGraphic , vector<AttendanceGraphic> &attendanceGraphic) {
	if (nowAdmin == "class") {
		adminEnter = "";
		adminText.setString("");
		adminText.setPosition(432, nameOfClass[nameOfClass.size() - 1].getPosition().y + 30 + 10);
		add.setPosition(408, 100);
		edit.setPosition(595, 100);
		remove.setPosition(782, 100);
		return;
	}
	if (nowAdmin == "import class success") {
		Class C;
		C.inputAClass(0, adminEnter, Acc, course);
		Classes.pushClass(C);
		Classes.save();
		nameOfClass.push_back(adminText);
		adminEnter = "";
		adminText.setString("");
		adminText.setPosition(432, nameOfClass[nameOfClass.size() - 1].getPosition().y + 60);
		nowAdmin = "class";
		return;
	}
	if (nowAdmin == "add student success") {
		if (adminEnter == "") {
			nowAdmin = "view class";
			return;
		}
		string a[5];
		for (int i = 0; i < 5; i++) a[i] = "";
		int j = 0;
		for (int i = 0; i < adminEnter.length(); i++) {
			if (adminEnter[i] != ',') {
				a[j] = a[j] + adminEnter[i];
			}
			else j++;
		}
		adminEnter = "";
		adminText.setString("");
		instruction.setString("");
		string pass;
		int gen;
		if (a[3][0] == 'M') gen = 0;
		else gen = 1;
		convertDateToPass(a[4], pass);
		string cou = Acc.returnCourse(classNow);
		Account acc;
		acc.createAccount(a[0], pass, 1, a[0], a[1], a[2], a[4], gen, classNow, cou, course);
		Acc.pushAccount(acc);
		addToScore(scoreBoard,acc);
		addToAttendance(attendanceList,acc);
		initTableClass(font, accountGraphic, classNow, Acc);
		nowAdmin = "view class";
		return;
	}
	if (nowAdmin == "student ID class success") {
		studentID = adminEnter;
		instruction.setString("What information you want to edit?(Password/Last name/First name/DoB/Gender)");
		adminText.setString("|");
		adminEnter = "";
		nowAdmin = "what to change";
		return;
	}
	if (nowAdmin == "edit") {
		whatToEdit = adminEnter;
		adminText.setString("|");
		instruction.setString("Enter information to change " + whatToEdit + " for " + studentID);
		adminEnter = "";
		nowAdmin = "enter inform";
		return;
	}
	if (nowAdmin == "edit done") {
		informEdit = adminEnter;
		adminText.setString("");
		instruction.setString("");
		adminEnter = "";
		nowAdmin = "view class";
		Account acc = Acc.getAccount(studentID);
		if (whatToEdit == "Password") {
			acc.changePassword(informEdit);
		}
		if (whatToEdit == "Last name") {
			acc.changeLastName(informEdit);
		}
		if (whatToEdit == "First name") {
			acc.changeFirstName(informEdit);
		}
		if (whatToEdit == "Gender") {
			acc.changeGender(informEdit);
		}
		if (whatToEdit == "DoB") {
			acc.changeDoB(informEdit);
		}
		Acc.removeAccount(studentID);
		Acc.pushAccount(acc);
		accountGraphic.clear();
		initTableClass(font, accountGraphic, classNow, Acc);
		return;
	}
	if (nowAdmin == "remove student done") {
		Account a = Acc.getAccount(adminEnter);
		Acc.removeAccount(adminEnter);
		removeScore(scoreBoard, a);
		removeAttendance(attendanceList, a);
		adminEnter = "";
		adminText.setString("");
		instruction.setString("");
		nowAdmin = "view class";
		accountGraphic.clear();
		initTableClass(font, accountGraphic, classNow, Acc);
		return;
	}
	if (nowAdmin == "ID change class") {
		studentID = adminEnter;
		adminEnter = "";
		adminText.setString("|");
		instruction.setString("Change student " + studentID + " to class:");
		nowAdmin = "class to change";
		return;
	}
	if (nowAdmin == "change class done") {
		Account acc = Acc.getAccount(studentID);
		vector <Course> cou;
		cou = Acc.getCourse(adminEnter);
		acc.changeClass(adminEnter,cou);

		Acc.removeAccount(studentID);
		Acc.pushAccount(acc);
		removeScore(scoreBoard, acc);
		removeAttendance(attendanceList, acc);
		
		addToScore(scoreBoard, acc);
		addToAttendance(attendanceList, acc);
		accountGraphic.clear();
		initTableClass(font, accountGraphic, classNow, Acc);
		adminEnter = "";
		adminText.setString("");
		instruction.setString("");
		nowAdmin = "view class";
		return;
	}
	if (nowAdmin == "course") {
		edit.setPosition(deleteS.getPosition().x + 147 + 50,100);
		add.setPosition(edit.getPosition().x + 127 + 50, 100);
		remove.setPosition(add.getPosition().x + 127 + 50, 100);
		instruction.setString("Enter year: ");
		adminEnter = "";
		adminText.setString("|");
		adminText.setPosition(432, instruction.getPosition().y + 30 + 10);
		nowAdmin = "course year";
		return;
	}
	if (nowAdmin == "course year done") {
		year = adminEnter;
		adminEnter = "";
		adminText.setString("|");
		instruction.setString("Enter term: ");
		nowAdmin = "course term";
		return;
	}
	if (nowAdmin == "course term done") {
		term = adminEnter[0] - '0';
		cout << adminEnter[0] << endl;
		cout << term << endl;
		instruction.setString("Academic Year: " + year + ", term " + adminEnter);
		adminEnter = "";
		adminText.setString("");
		courseGraphic.clear();
		initTableCourse(font, courseGraphic, course, year, term);
		nowAdmin = "course options";
		return;
	}
	if (nowAdmin == "create course") {
		course.loadCourse(year, term);
		courseGraphic.clear();
		initTableCourse(font, courseGraphic, course, year, term);
		Acc.updateCourse(course,year,term);
		nowAdmin = "course options";
		return;
	}
	if (nowAdmin == "delete course") {

		course.deleteAll(year,term);
		year = "";
		term = 0;
		nowAdmin = "course";
		return;
	}
	if (nowAdmin == "add course") {
		adminEnter = "";
		adminText.setString("|");
		instruction.setString("Enter course (Course ID,Course Name,Lecture ID,Start Date,End Date,Day,Start,End,Room): ");
		nowAdmin = "enter course";
		return;
	}
	if (nowAdmin == "enter course success") {
		if (adminEnter == "") {
			adminText.setString("");
			instruction.setString("");
			nowAdmin = "course options";
			return;
		}
		string s[9];
		int j = 0;
		for (int i = 0; i < adminEnter.length(); i++)
		{
			if (adminEnter[i] != ',') {
				s[j] = s[j] + adminEnter[i];
			}
			else j++;
		}
		Account lecturer = Acc.getAccount(s[2]);
		Acc.removeAccount(s[2]);
		string lecturerName = lecturer.getLastName() + " " + lecturer.getFirstName();
		Course C;
		C.inputACourse(s[0], s[1], lecturerName, year, term, s[3], s[4], s[5], s[6], s[7], s[8]);
		course.pushCourse(C);
		lecturer.addCourse(C);
		Acc.pushAccount(lecturer);
		courseGraphic.clear();
		initTableCourse(font, courseGraphic, course, year, term);
		nowAdmin = "course options";
		return;
	}
	if (nowAdmin == "create Lecturer success") {
		if (adminEnter == "") {
			nowAdmin = "lecturer";
			return;
		}
		string a[5];
		for (int i = 0; i < 5; i++) a[i] = "";
		int j = 0;
		for (int i = 0; i < adminEnter.length(); i++) {
			if (adminEnter[i] != ',') {
				a[j] = a[j] + adminEnter[i];
			}
			else j++;
		}
		adminEnter = "";
		adminText.setString("");
		instruction.setString("");
		string pass;
		int gen;
		if (a[3][0] == 'M') gen = 0;
		else gen = 1;
		convertDateToPass(a[4], pass);
		Acc.input(a[0], pass, 2, a[0], a[1], a[2], a[4], gen, "", "", course);
		accountGraphic.clear();
		initTableLecturer(font, accountGraphic, Acc);
		nowAdmin = "lecturer";
		return;
	}
	if (nowAdmin == "update Lecturer success") {
		lecturerID = adminEnter;
		instruction.setString("What information you want to edit?(Password/Last name/First name/DoB/Gender)");
		adminText.setString("|");
		adminEnter = "";
		nowAdmin = "change Lecturer";
		return;
	}
	if (nowAdmin == "delete Lecturer success")
	{
		Acc.removeAccount(adminEnter);
		adminEnter = "";
		adminText.setString("");
		instruction.setString("");
		nowAdmin = "lecturer";
		accountGraphic.clear();
		initTableLecturer(font, accountGraphic, Acc);
		return;
	}
	if (nowAdmin == "edit Lecturer")
	{
		whatToEdit = adminEnter;
		adminText.setString("|");
		instruction.setString("Enter information to change " + whatToEdit + " for " + lecturerID);
		adminEnter = "";
		nowAdmin = "enter Lecturer inform";
		return;
	}
	if (nowAdmin == "edit Lecturer done") {
		informEdit = adminEnter;
		adminText.setString("");
		instruction.setString("");
		adminEnter = "";
		nowAdmin = "lecturer";
		Account acc = Acc.getAccount(lecturerID);
		if (whatToEdit == "Password") {
			acc.changePassword(informEdit);
		}
		if (whatToEdit == "Last name") {
			acc.changeLastName(informEdit);
		}
		if (whatToEdit == "First name") {
			acc.changeFirstName(informEdit);
		}
		if (whatToEdit == "Gender") {
			acc.changeGender(informEdit);
		}
		if (whatToEdit == "DoB") {
			acc.changeDoB(informEdit);
		}
		Acc.removeAccount(lecturerID);
		Acc.pushAccount(acc);
		accountGraphic.clear();
		initTableLecturer(font, accountGraphic, Acc);
		return;
	}
	if (nowAdmin == "remove course") {
		instruction.setString("Enter course ID: ");
		adminEnter = "";
		adminText.setString("|");
		nowAdmin = "remove course ID";
		return;
	}
	if (nowAdmin == "remove course done") {
		Acc.removeCourseInAccount(adminEnter);
		course.removeCourse(adminEnter);
		courseGraphic.clear();
		initTableCourse(font, courseGraphic, course, year, term);
		instruction.setString("");
		adminText.setString("");
		adminEnter = "";
		nowAdmin = "course options";
		return;
	}

	if (nowAdmin == "edit course") {
		instruction.setString("Enter course ID to edit:");
		adminEnter = "";
		adminText.setString("|");
		nowAdmin = "edit course ID";
		return;
	}
	if (nowAdmin == "course ID done") {
		courseID = adminEnter;
		adminEnter = "";
		instruction.setString("What do you want to edit (CourseName/Day/Start/End/Room):");
		adminText.setString("|");
		nowAdmin = "edit course?";
		return;
	}
	if (nowAdmin == "course ? done") {
		whatToEdit = adminEnter;
		adminEnter = "";
		instruction.setString("Enter information: ");
		adminText.setString("|");
		nowAdmin = "course what?";
		return;
	}
	if (nowAdmin == "course what? done") {
		informEdit = adminEnter;
		instruction.setString("");
		adminEnter = "";
		adminText.setString("");
		nowAdmin = "course options";
		course.editCourse(courseID, whatToEdit, informEdit);
		courseGraphic.clear();
		initTableCourse(font, courseGraphic, course, year, term);
		return;
	}
	if (nowAdmin == "view student") {
		add.setPosition(408, 100);
		remove.setPosition(595, 100);
		addClass.setPosition(782, 100);
		instruction.setString("Course ID: " + courseID);
	}
	if (nowAdmin == "add st -> course") {
		instruction.setString("Enter student ID: ");
		adminEnter = "";
		adminText.setString("|");
		nowAdmin = "+ st ID";
		return;
	}
	if (nowAdmin == "+ st ID done") {
		instruction.setString("");
		studentID = adminEnter;
		
		Acc.addCourse(studentID, courseID,course);
		Account a;
		a = Acc.getAccount(studentID);
		addToScore(scoreBoard, a, courseID);
		addToAttendance(attendanceList, a, courseID);

		adminText.setString("");
		adminEnter = "";
		studentGraphic.clear();
		initTableCourse_Student(font, studentGraphic, courseID, Acc);
		nowAdmin = "view student";
		return;
	}
	if (nowAdmin == "remove st fr course") {
		instruction.setString("Enter student ID: ");
		adminEnter = "";
		adminText.setString("|");
		nowAdmin = "- st ID";
		return;
	}
	if (nowAdmin == "- st ID done") {
		instruction.setString("");
		studentID = adminEnter;
		adminEnter = "";
		adminText.setString("");

		Acc.removeCourseInAccount(studentID, courseID);
		Account a = Acc.getAccount(studentID);
		removeAttendance(attendanceList, a, courseID);
		removeScore(scoreBoard, a, courseID);
		studentGraphic.clear();
		initTableCourse_Student(font, studentGraphic, courseID, Acc);
		nowAdmin = "view student";
		return;
	}
	if (nowAdmin == "add a class") {
		instruction.setString("Enter class: ");
		adminEnter = "";
		adminText.setString("|");
		nowAdmin = "+ class";
		return;
	}
	if (nowAdmin == "+ class done") {
		instruction.setString("Course : " + courseID);
		Acc.addCourseToClass(adminEnter, courseID, course);
		//write down here
		adminText.setString("");
		nowAdmin = "view student";
		studentGraphic.clear();
		initTableCourse_Student(font, studentGraphic, courseID, Acc);
		adminEnter = "";
		return;
	}
	if (nowAdmin == "scoreboard") {
		instruction.setString("Course ID: ");
		adminEnter = "";
		adminText.setString("|");
		nowAdmin = "score course ID";
		scoreGraphic.clear();
		courseID = "";
		return;
	}
	if (nowAdmin == "attendance") {
		instruction.setString("Course ID: ");
		adminEnter = "";
		adminText.setString("|");
		nowAdmin = "attend course ID";
		attendanceGraphic.clear();
		courseID = "";
		return;
	}
	if (nowAdmin == "score done") {
		courseID = adminEnter;
		scoreGraphic.clear();
		scoreGraphic.clear();
		initTableScore(font, scoreGraphic, scoreBoard, course, courseID);
		if (scoreGraphic.size() <= 1) {
			instruction.setString("Course ID: ");
			adminEnter = "";
			adminText.setString("|");
			nowAdmin = "score course ID";
			scoreGraphic.clear();
			return;
		}
		instruction.setString("Course ID : " + courseID);
		adminText.setString("");
		nowAdmin = "scoreboard view";
		return;
	}
	if (nowAdmin == "attend done") {
		courseID = adminEnter;
		attendanceGraphic.clear();
		initTableAttendance(font,attendanceGraphic,attendanceList,course,courseID);
		if (attendanceGraphic.size() <= 1) {
			instruction.setString("Course ID: ");
			adminEnter = "";
			adminText.setString("|");
			nowAdmin = "attend course ID";
			scoreGraphic.clear();
			return;
		}
		instruction.setString("Course ID : " + courseID);
		adminText.setString("");
		nowAdmin = "attend view";
		return;
	}
}
