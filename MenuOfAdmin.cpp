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

	updateText(instruction, font, sf::Color::White, 408, 170, 30);
	updateText(adminText, font, sf::Color::White, 408, 220, 30);

	add.setTexture(addTexture);
	add.setPosition(408, 100);

	edit.setTexture(editTexture);
	edit.setPosition(595,100);

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

	scoreBoard.setTexture(scoreBoardTexture);
	scoreBoard.setPosition(40, 318);

	attendanceList.setTexture(attendanceListTexture);
	attendanceList.setPosition(40, 415);

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

void MenuOfAdmin::render(sf::RenderWindow &window, string nowAdmin, ArrOfAccount Acc, ArrayOfClass Classes, vector<AccountGraphic> &accountGraphic, vector<CourseGraphic> &courseGraphic, vector<StudentGraphic> & studentGraphic) {
	window.draw(classes);
	window.draw(course);
	window.draw(scoreBoard);
	window.draw(attendanceList);
	if (nowAdmin == "class" || nowAdmin == "import a class" || nowAdmin == "import success") {
		for (int i = 0; i < nameOfClass.size(); i++)
			window.draw(nameOfClass[i]);
		window.draw(importAClass);
		window.draw(adminText);
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
	}


	/*for (int i = 0; i < nameOfClass.size(); i++) {
		if (nowAdmin == nameOfClass[i].getString()) {
			renderTableClass(window, accountGraphic);
			break;
		}
	}*/
	if (nowAdmin == "course") {
		renderTableCourse(window, courseGraphic);
	}
	if (nowAdmin == "view student") {
		
		renderTableCourse_Student(window, studentGraphic);
	}
}

string MenuOfAdmin::handleEvent(sf::Event event,string nowAdmin, ArrOfAccount Acc, vector<AccountGraphic> & accountGraphic, ArrayOfCourse courses, vector<CourseGraphic> & courseGraphic, vector<StudentGraphic> & studentGraphic) {
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		if (nowAdmin == "anywhere") {
			if (classes.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				return "class";
			}
			if (course.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			{
				initTableCourse(font, courseGraphic, courses);
				return "course";
			}
			if (scoreBoard.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				return "scoreboard";
			}
			if (attendanceList.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				return "attendancelist";
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
		
		if (nowAdmin == "course") {
			for (int i = 0; i < courseGraphic.size(); i++)
			{
				if (courseGraphic[i].ID.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					initTableCourse_Student(font, studentGraphic, courseGraphic[i].ID.getString(), Acc);
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
	}
}

void MenuOfAdmin::logic(string &nowAdmin,ArrayOfClass &Classes,ArrOfAccount &Acc, ArrayOfCourse course, vector<AccountGraphic>  &accountGraphic) {
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
		Acc.input(a[0], pass, 1, a[0], a[1], a[2], a[4], gen, classNow, "", course);
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
		initTableClass(font, accountGraphic, classNow, Acc);
		return;
	}
	if (nowAdmin == "remove student done") {
		Acc.removeAccount(adminEnter);
		adminEnter = "";
		adminText.setString("");
		instruction.setString("");
		nowAdmin = "view class";
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
		acc.changeClass(adminEnter);
		Acc.removeAccount(studentID);
		Acc.pushAccount(acc);
		initTableClass(font, accountGraphic, classNow, Acc);
		adminEnter = "";
		adminText.setString("");
		instruction.setString("");
		nowAdmin = "view class";
		return;
	}
}