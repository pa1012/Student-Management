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
	sf::Texture classTexture, courseTexture, scoreBoardTexture, attendanceListTexture,importAClassTexture,addTexture,editTexture,removeTexture,changeClassTexture;
	sf::Sprite classes, course, scoreBoard, attendanceList, importAClass,add,edit,remove,changeClass;
	vector <sf::Text> nameOfClass;
	sf::Font font;
	string nameAddClass;
	sf::Text nameNewClass;
	sf::Text instruction;
	sf::Text adminText;
	string adminEnter;
	string classNow;
	string studentID,whatToEdit,informEdit;
public:
	void initGraphics(ArrayOfClass Classes);
	void render(sf::RenderWindow &window, string nowAdmin,ArrOfAccount Acc, ArrayOfClass Classes, vector<AccountGraphic> &accountGraphic,vector<CourseGraphic> &courseGraphic, vector<StudentGraphic> & studentGraphic);
	string handleEvent(sf::Event event,string nowAdmin, ArrOfAccount Acc, vector<AccountGraphic> & accountGraphic,ArrayOfCourse courses, vector<CourseGraphic> & courseGraphic, vector<StudentGraphic> & studentGraphic);
	void logic(string &nowAdmin, ArrayOfClass &Classes, ArrOfAccount &Acc, ArrayOfCourse C, vector<AccountGraphic>& accountGraphic);
};