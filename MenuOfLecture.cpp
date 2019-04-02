#include"MenuOfLecture.h"

void MenuOfLecturer::initGraphics() {
	loadTexture("course.png", CourseTexture);
	loadTexture("attendanceList.png", AttendanceListTexture);
	loadTexture("scoreBoard.png", ScoreBoardTexture);
	

	Course.setTexture(CourseTexture);
	Course.setPosition(40, 224);

	AttendanceList.setTexture(AttendanceListTexture);
	AttendanceList.setPosition(40, 318);

	ScoreBoard.setTexture(ScoreBoardTexture);
	ScoreBoard.setPosition(40, 415);

	
}

void MenuOfLecturer::render(sf::RenderWindow &window, string &nowLecturer, ArrOfAccount Acc, vector<AccountGraphic> &accountGraphic) {
	window.draw(Course);
	window.draw(AttendanceList);
	window.draw(ScoreBoard);

}

string MenuOfLecturer::handleEvent(sf::Event event, string &nowLecturer, ArrOfAccount Acc, vector<AccountGraphic> &accountGraphic) {
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		if(nowLecturer == "anywhere")
		if (Course.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
		{
			return "course";
		}
		if (AttendanceList.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
			return "attendancelist";
		}
		if (ScoreBoard.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
			return "scoreboard";
		}
	}
	return "anywhere";


}

void logic(string &nowAdmin, ArrOfAccount &Acc, vector<AccountGraphic> &accountGraphic)
{

}
