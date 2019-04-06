#pragma once

#include"Base.h"
#include"LoadData.h"
#include"Account.h"
#include"ArrayOfClass.h"
#include"Update.h"
#include "ArrayOfAccount.h"
#include"RenderTable.h"
#include"Time.h"
using namespace std;

class MenuOfAdmin {
private:
	sf::Texture classTexture, courseTexture, scoreBoardTexture, attendanceListTexture, importAClassTexture, addTexture, editTexture, removeTexture, changeClassTexture, createTexture, deleteTexture, viewTexture, updateTexture, lecturerTexture,addClassTexture;
	sf::Sprite classes, course, scoreBoard, attendanceList, importAClass, add, edit, remove, changeClass, create, deleteS, view, update, lecturer, createLecturer, updateLecturer, deleteLecturer, viewLecturer,addClass;
	vector <sf::Text> nameOfClass;
	sf::Font font;
	string nameAddClass;
	sf::Text nameNewClass;
	sf::Text instruction;
	sf::Text adminText;
	string adminEnter;
	string classNow;
	string studentID, whatToEdit, informEdit, lecturerID,courseID;
	int term;
	string year;
public:
	void initGraphics(ArrayOfClass Classes);
	void render(sf::RenderWindow &window, string nowAdmin, ArrOfAccount Acc, ArrayOfClass Classes, vector<AccountGraphic> &accountGraphic, vector<CourseGraphic> &courseGraphic, vector<StudentGraphic> & studentGraphic, vector<ScoreGraphic> & scoreGraphic,vector<AttendanceGraphic> & attendanceGraphic );
	string handleEvent(sf::Event event, string nowAdmin, ArrOfAccount Acc, vector<AccountGraphic> & accountGraphic, ArrayOfCourse courses, vector<CourseGraphic> & courseGraphic, vector<StudentGraphic> & studentGraphic);
	void logic(string &nowAdmin, Time time, ArrayOfClass &Classes, ArrOfAccount &Acc, ArrayOfCourse &course, vector<ScoreBoard> &scoreBoard, vector<AttendanceList>& attendanceList, vector<AccountGraphic>  &accountGraphic, vector<CourseGraphic> &courseGraphic, vector<StudentGraphic> &studentGraphic, vector<ScoreGraphic> &scoreGraphic, vector<AttendanceGraphic> &attendanceGraphic);
};
