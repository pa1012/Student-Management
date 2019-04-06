#pragma once

#include"Base.h"
#include"LoadData.h"
#include"Account.h"
#include"RenderTable.h"
#include"Update.h"

using namespace std;

class MenuOfStudent{
private:
	sf::Texture checkInTexture, scoreTexture, scheduleTexture;
	sf::Sprite checkIn, score, schedule;
	sf::Font font;
	sf::Text instruction, studentText;
	string studentEnter,courseID;
public:
	void initGraphics();
	void render(sf::RenderWindow &window, string nowStudent, vector<CourseGraphic> & courseGraphic, vector<ScoreGraphic> & scoreGraphic, vector<AttendanceGraphic> &attendanceGraphic);
	string handleEvent(sf::Event event, string nowStudent);
	void logic(Time time, Account&Acc, string & nowStudent, ArrayOfCourse &course, vector<AttendanceList> &attendanceList, vector<ScoreBoard>& score, vector<CourseGraphic> & courseGraphic, vector<ScoreGraphic> & scoreGraphic, vector<AttendanceGraphic> & attendanceGraphic);
};
