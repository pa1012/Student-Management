#pragma once

#include"Base.h"
#include"ArrayOfAccount.h"
#include"ArrayOfClass.h"
#include"ArrayOfCourse.h"
#include"Update.h"
#include"LoadData.h"
#include"ScoreBoard.h"
#include"AttendanceList.h"

class AccountGraphic
{
public:
	sf::Text no, userName, password, ID, lastName, firstName, doB, gender, inClass;
};

class CourseGraphic
{
public:
	sf::Text no, name, ID, lecture, inYear, startDate, endDate, dayOfWeek, start, end, room, semester;
};

class StudentGraphic
{
public:
	sf::Text no, firstName, lastName, ID, Class;
};

class ScoreGraphic {
public:
	sf::Text no,stID, mid, lab, fin, bonus, inclass;
};

class AttendanceGraphic {
public:
	sf::Text no,stID, w[5];
};
void renderTableClass(sf::RenderWindow &window, vector<AccountGraphic> A);
void initTableClass(sf::Font & font, vector<AccountGraphic> &A, string className, ArrOfAccount Acc);

void renderTableCourse(sf::RenderWindow &window, vector<CourseGraphic> A);
void initTableCourse(sf::Font & font, vector<CourseGraphic> &A, ArrayOfCourse Arr, string year, int term); //
void initTableCourse(sf::Font & font, vector<CourseGraphic> &A, ArrayOfCourse Arr);
void initTableCourse(sf::Font & font, vector<CourseGraphic> &A, Account Acc);

void renderTableCourse_Student(sf::RenderWindow &window, vector<StudentGraphic> A);
void initTableCourse_Student(sf::Font & font, vector<StudentGraphic> &A, string courseName, ArrOfAccount Std);

void renderTableLecturer(sf::RenderWindow &window, vector<AccountGraphic> A); //
void initTableLecturer(sf::Font & font, vector<AccountGraphic> &A, ArrOfAccount Acc); //

void initTableScore(sf::Font & font, vector<ScoreGraphic> &A, vector<ScoreBoard> score, ArrayOfCourse course, string courseID);
void initTableScore(sf::Font & font, vector<ScoreGraphic> &A, vector<ScoreBoard> score, Account Acc);
void renderTableScore(sf::RenderWindow &window, vector<ScoreGraphic>  A);

void initTableAttendance(sf::Font & font, vector <AttendanceGraphic> & A, vector<AttendanceList> attend, ArrayOfCourse course,string courseID);
void initTableAttendance(sf::Font & font, vector<AttendanceGraphic> &A, vector<AttendanceList> attend, Account Acc);
void renderTableAttendance(sf::RenderWindow & window, vector<AttendanceGraphic> A);
