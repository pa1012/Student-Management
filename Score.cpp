#include "Score.h"



void Score::inputScore(string id, float mid, float lb, float fi,float bo, string inCl,string couID)
{
	studentID = id;
	midterm = mid;
	lab = lb;
	final = fi;
	bonus = bo;
	inClass = inCl;
	courseID = couID;
}

void Score::clear() {
}

void Score::printOut() {
	cout << studentID << " ";
	cout << setprecision(2) << midterm << " ";
	cout << setprecision(2) << lab << " ";
	cout << setprecision(2) << final << " ";
	cout << inClass << endl;
}

string Score::getStudentID() {
	return studentID;
}
string Score::getMidterm() {
	stringstream s;
	s << midterm;
	return s.str();
}
string Score::getLab() {
	stringstream s;
	s << lab;
	return s.str();
}
string Score::getFinal() {
	stringstream s;
	s << final;
	return s.str();
}
string Score::getBonus() {
	stringstream s;
	s << bonus;
	return s.str();
}
string Score::getClass() {
	return inClass;
}

bool Score::isMatchID(string ID) {
	return (ID == studentID);
}

string Score::getCourseID() {
	return courseID;
}

void Score::save() {
	ofstream fout;
	string fileName = "Data/score/" + courseID + ".csv";
	fout.open(fileName, ios::app);
	fout << studentID << ',';
	fout <<fixed<<setprecision(1)<< midterm << ',';
	fout <<fixed<<setprecision(1)<< lab << ',';
	fout <<fixed<<setprecision(1)<< final << ',';
	fout <<fixed<<setprecision(1)<< bonus << ',';
	fout << inClass << '\n';
	fout.close();
}

void Score::updateScore(string what, float grade) {
	if (grade > 10 || grade < 0) return;
	if (what == "Midterm") {
		midterm = grade;
	}
	else 
		if (what == "Lab") {
			lab = grade;
	}
		else if (what == "Final") {
			final = grade;
		}
		else bonus = grade;
}
