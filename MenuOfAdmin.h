#pragma once

#include"Base.h"
#include"LoadData.h"
#include"Account.h"
#include"ArrayOfClass.h"
#include"Update.h"
#include "ArrayOfAccount.h"
#include"RenderTable.h"

using namespace std;

class MenuOfAdmin {
private:
	sf::Texture classTexture, courseTexture, scoreBoardTexture, attendanceListTexture,importAClassTexture;
	sf::Sprite classes, course, scoreBoard, attendanceList, importAClass;
	vector <sf::Text> nameOfClass;
	sf::Font font;
	string nameAddClass;
	sf::Text nameNewClass;
public:
	void initGraphics(ArrayOfClass Classes);
	void render(sf::RenderWindow &window, string nowAdmin,ArrOfAccount Acc, ArrayOfClass Classes);
	string handleEvent(sf::Event event,ArrOfAccount Acc);
	void logic(string &nowAdmin, ArrayOfClass &Classes, ArrOfAccount &Acc, ArrayOfCourse C);
};