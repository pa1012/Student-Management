#include"MenuOfAdmin.h"

void MenuOfAdmin::initGraphics(ArrayOfClass Classes) {
	loadTexture("class.png", classTexture);
	loadTexture("course.png", courseTexture);
	loadTexture("scoreBoard.png", scoreBoardTexture);
	loadTexture("attendanceList.png", attendanceListTexture);
	loadFont("VNI-Avo.TTF", font);
	loadTexture("importAClass.png", importAClassTexture);

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

void MenuOfAdmin::render(sf::RenderWindow &window, string nowAdmin, ArrOfAccount Acc, ArrayOfClass Classes) {
	window.draw(classes);
	window.draw(course);
	window.draw(scoreBoard);
	window.draw(attendanceList);
	if (nowAdmin == "class" || nowAdmin == "import a class" || nowAdmin == "import success") {
		for (int i = 0; i < nameOfClass.size(); i++)
			window.draw(nameOfClass[i]);
		window.draw(importAClass);
		window.draw(nameNewClass);
	}
	/*for (int i = 0; i < nameOfClass.size(); i++) {
		if (nowAdmin == nameOfClass[i].getString()) {
			renderTableClass(window,nowAdmin, Acc);
		}
	}*/
}

string MenuOfAdmin::handleEvent(sf::Event event,ArrOfAccount Acc) {
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
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
			return "attendancelist";
		}
		if (importAClass.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
			nameNewClass.setString("|");
			return "import a class";
		}
		/*for (int  i = 0 ; i < nameOfClass.size() ; i++)
			if (nameOfClass[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				initTableClass(nameOfClass[i].getString(), Acc);
				return nameOfClass[i].getString();
			}*/
		return "anywhere";
	}
	if (event.type == sf::Event::TextEntered) {
		if (event.text.unicode == 13) {
			nameNewClass.setString(nameAddClass);
			return "import success";
		}
		updateString(nameAddClass, event);
		nameNewClass.setString(nameAddClass + "|");
		return "import a class";
	}
}

void MenuOfAdmin::logic(string &nowAdmin,ArrayOfClass &Classes,ArrOfAccount &Acc, ArrayOfCourse course) {
	if (nowAdmin == "import success") {
		Class C;
		C.inputAClass(0, nameAddClass, Acc, course);
		Classes.pushClass(C);
		Classes.save();
		nameOfClass.push_back(nameNewClass);
		nameAddClass = "";
		nameNewClass.setString("");
		nameNewClass.setPosition(432, nameOfClass[nameOfClass.size() - 1].getPosition().y + 60);
		nowAdmin = "class";
	}
	
}