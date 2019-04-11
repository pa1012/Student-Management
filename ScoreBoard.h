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
	void save0();
	void updateScore(string studentID, string what, float grade);
	void removeScore(string studentID);
	void addScore(string studentID, string inClass);
	void addClass(vector<Account> acc, string courseID);
	bool isExisted(string studentID);
	void push(Score s);
};
void loadfileScore(vector<ScoreBoard> &score, ArrayOfCourse course);
void loadfileScore(vector<ScoreBoard> &score, string courseID);
vector<Score> returnScore(vector<ScoreBoard> &score, Account Acc);
void saveScoreBoard(vector<ScoreBoard> scoreboard);
void updateScore(vector<ScoreBoard> &score, string courseID, string studentID, string what, float grade);
void removeScore(vector<ScoreBoard> &scoreBoard, Account account);
void addToScore(vector<ScoreBoard> &scoreBoard, Account acc);

void removeScore(vector<ScoreBoard> &scoreBoard, Account account, string courseID);
void addToScore(vector<ScoreBoard> &scoreBoard,Account account, string courseID);
void addClassToScore(vector<ScoreBoard> &scoreBoard, string inClass,string courseID,ArrOfAccount Acc);
void exportScoreBoard(vector<ScoreBoard> scoreboard,string courseID);
