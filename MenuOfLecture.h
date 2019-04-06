#pragma once

#include"Base.h"
#include"LoadData.h"
#include"Account.h"
#include"ArrayOfClass.h"
#include"Update.h"
#include "ArrayOfAccount.h"
#include"RenderTable.h"
#include"Time.h"
#include"ArrayOfCourse.h"

using namespace std;

class MenuOfLecturer {
private:
	sf::Texture CourseTexture, AttendanceListTexture, ScoreBoardTexture, viewTexture, editTexture, importTexture;
	sf::Sprite course, Attendance_List, Score_Board, viewStudent, editAttendance, editScore, importScore;
	sf::Font font;
	sf::Text instruction;
	sf::Text LecturerText;
	string LecturerEnter;
	string year, courseName, courseID, studentID, what, grade;
	int term;
public:
	void initGraphics();

	void render(sf::RenderWindow &window, string nowStudent, vector<CourseGraphic> & courseGraphic, vector<ScoreGraphic> & scoreGraphic, 
		vector<AttendanceGraphic> &attendanceGraphic, vector<StudentGraphic> &studentGraphic);

	string handleEvent(sf::Event event, string &nowLecturer,vector<CourseGraphic> & courseGraphic);

	void logic(Time time, Account&Acc, string & nowLecturer, ArrayOfCourse& course, vector<AttendanceList> &attendanceList, 
		vector<ScoreBoard> &score, vector<CourseGraphic> & courseGraphic, vector<ScoreGraphic> & scoreGraphic, vector<AttendanceGraphic> & attendanceGraphic, 
		vector<StudentGraphic> & studentGraphic, ArrOfAccount &account);
};
