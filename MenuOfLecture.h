#pragma once

#include"Base.h"
#include"LoadData.h"
#include"Account.h"

using namespace std;

class MenuOfLecturer {
private:
	sf::Texture CourseTexture, AttendanceListTexture, ScoreBoardTexture;
	sf::Sprite Course, AttendanceList, ScoreBoard;
	
public:
	void initGraphics();
	void render(sf::RenderWindow &window);
	string handleEvent(sf::Event event);
	
};