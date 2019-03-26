#pragma once

#include"Base.h"
#include"ArrayOfAccount.h"
#include"ArrayOfClass.h"
#include"ArrayOfCourse.h"
#include"Update.h"
#include"LoadData.h"

class AccountGraphic
{
public:
	sf::Text no, userName, password,ID,lastName, firstName,doB,gender,inClass;
};

class CourseGraphic
{
public:
	sf::Text no, name, ID, lecture, inYear, startDate, endDate, dayOfWeek, start, end, room, semester;
};

class StudentGraphic
{
public:
	sf::Text no, firstName, lastName, ID,  Class;
};

void renderTableClass(sf::RenderWindow &window, vector<AccountGraphic> A);
void initTableClass(sf::Font & font, vector<AccountGraphic> &A, string className, ArrOfAccount Acc);

void renderTableCourse(sf::RenderWindow &window,  vector<CourseGraphic> A);
void initTableCourse(sf::Font & font, vector<CourseGraphic> &A, ArrayOfCourse Arr);

void renderTableCourse_Student(sf::RenderWindow &window, vector<StudentGraphic> A);
void initTableCourse_Student(sf::Font & font, vector<StudentGraphic> &A, string courseName, ArrOfAccount Std);
