#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include "Score.h"
#include"ArrayOfCourse.h"
#include"ArrayOfAccount.h"
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
	Score getScore(string studentID);
	void save();
};
void loadfileScore(vector<ScoreBoard> &score, ArrayOfCourse course);
vector<Score> returnScore(vector<ScoreBoard> &score, Account Acc);
void saveScoreBoard(vector<ScoreBoard> scoreboard);