#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include "Score.h"
#include"ArrayOfCourse.h"
using namespace std;

class ScoreBoard {
private:
	string courseName;
	vector <Score> scoreBoard;
public:
	void loadScore();
	void printOut();
	void inputCourseName(string name);
	void clear();
	bool isMatchCourse(string courseID);
	vector<Score> returnScore();

};
void loadfileScore(vector<ScoreBoard> &score, ArrayOfCourse course);