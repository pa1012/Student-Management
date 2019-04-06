#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<iomanip>
#include<string>

using namespace std;
class Score {
private:
	int n;
	string studentID;
	float midterm;
	float lab;
	float final;
	float bonus;
	string inClass;
	string courseID;

public:
	void inputScore(string id, float mid, float lb, float fi, float bo, string inCl,string couID);
	void printOut();
	void clear();
	string getStudentID();
	string getMidterm();
	string getLab();
	string getFinal();
	string getBonus();
	string getClass();
	string getCourseID();
	bool isMatchID(string ID);
	void save();
	void updateScore(string what, float grade);
};
