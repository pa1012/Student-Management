
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
	string inYear;
	string startDate, endDate;
	string dayOfWeek;
	string start, end;
	string room;
	int semester;
public:
	void inputACourse(string id, string nam,string lec, string year, int se, string startDt, string endDt, string inDay, string st, string en, string room);
	bool isMatched(Course C);
	bool isMatchedID(string id);
	void printName();
	string getName();
	int getSemester();
	string getID();
	string getYear();
	string getLecture();
	string getStartDate();
	string getEndDate();
	string getDayOfWeek();
	string getStart();
	string getEnd();
	string getRoom();
};