
#pragma once
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

class Course {
private:
	string name;
	string ID;
	string lecture;
	string lectureID;
	string inYear;
	string startDate, endDate;
	string dayOfWeek;
	string start, end;
	string room;
	
	int semester;
public:
	void inputACourse(string id, string nam,string lec, string lecid, string year, int se, string startDt, string endDt, string inDay, string st, string en, string room);
	bool isMatched(Course C);
	string getID();
	int getSemester();
	string getYear();
	bool isMatchedID(string id);
	void printName();
};