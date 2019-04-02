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

public:
	void inputScore(string id, float mid, float lb, float fi, float bo, string inCl);
	void printOut();
	void clear();
	string getStudentID();
	string getMidterm();
	string getLab();
	string getFinal();
	string getBonus();
	string getClass();
};
