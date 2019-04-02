#include "ScoreBoard.h"


void ScoreBoard::printOut() {
	for (int i = 0; i < scoreBoard.size(); i++) {
		scoreBoard[i].printOut();
	}
}

void ScoreBoard::loadScore()
{
	ifstream fin;
	string nameFile = "Data/score/" + courseName + ".csv";
	fin.open(nameFile);
	string id, inCl;
	float mid, lb, fi,bo;
	fin.ignore(1000, '\n');
	while (!fin.eof())
	{
		getline(fin, id, ',');
		fin >> mid;
		fin.ignore(10, ',');
		fin >> lb;
		fin.ignore(10, ',');
		fin >> fi;
		fin.ignore(10, ',');
		fin >> bo;
		fin.ignore(10, ',');
		getline(fin, inCl, '\n');
		Score a;
		if (id != "") {
			a.inputScore(id, mid, lb, fi,bo, inCl);
			scoreBoard.push_back(a);
			a.clear();
		}
	}
	fin.close();
}

void ScoreBoard::clear() {
	scoreBoard.clear();
	courseName = "";
}

void loadfileScore(vector<ScoreBoard> &score, ArrayOfCourse course) {
	int n = course.size();
	ScoreBoard A;
	for (int i = 0; i < n; i++)
	{
		string courseName = course.nameOfCourse(i);
		A.clear();
		A.inputCourseName(courseName);
		A.loadScore();
		score.push_back(A);
	}
}

void ScoreBoard::inputCourseName(string name) {
	courseName = name;
}

bool ScoreBoard::isMatchCourse(string courseID) {
	return(courseName == courseID);
}

vector<Score> ScoreBoard::returnScore() {
	return scoreBoard;
}