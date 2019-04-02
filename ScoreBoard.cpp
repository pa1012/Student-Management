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
			a.inputScore(id, mid, lb, fi,bo, inCl,courseName);
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

vector<Score> returnScore(vector<ScoreBoard> &score, Account Acc) {
	vector<Course> course = Acc.returnCourses();
	vector<Score> Sc;
	for (int i = 0; i < course.size(); i++) {
		for (int j = 0 ; j < score.size(); j++)
			if (score[j].isMatchCourse(course[i].getID())) {
				Sc.push_back(score[j].getScore(Acc.getID()));
			}
	}
	return Sc;
}

Score ScoreBoard::getScore(string studentID) {
	for (int i = 0; i < scoreBoard.size(); i++)
		if (scoreBoard[i].isMatchID(studentID)) return scoreBoard[i];

}

void saveScoreBoard(vector<ScoreBoard> scoreboard) {
	for (int i = 0; i < scoreboard.size(); i++)
		scoreboard[i].save();
}

void ScoreBoard::save() {
	ofstream fout;
	string fileName;
	fileName = "Data/score/" + courseName + ".csv";
	fout.open(fileName);
	fout << "StudentID,Midterm,Lab,Final,Bonus,Class" << endl;
	for (int i = 0; i < scoreBoard.size(); i++)
		scoreBoard[i].save();
	fout.close();
}