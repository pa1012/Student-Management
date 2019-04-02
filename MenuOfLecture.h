#pragma once

#include"Base.h"
#include"LoadData.h"
#include"Account.h"
#include "ArrayOfAccount.h"
#include"RenderTable.h"
#include"Update.h"

using namespace std;

class MenuOfLecturer {
private:
	sf::Texture CourseTexture, AttendanceListTexture, ScoreBoardTexture;
	sf::Sprite Course, AttendanceList, ScoreBoard;
	sf::Font font;
	sf::Text instruction;
	sf::Text adminText;
	string adminEnter;
public:
	void initGraphics();
	void render(sf::RenderWindow &window, string &nowLecturer, ArrOfAccount Acc, vector<AccountGraphic> &accountGraphic);
	string handleEvent(sf::Event event, string &nowLecturer, ArrOfAccount Acc, vector<AccountGraphic> &accountGraphic);
	void logic(string &nowLecturer, ArrOfAccount &Acc, vector<AccountGraphic> &accountGraphic);
};
