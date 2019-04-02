#include "Score.h"



void Score::inputScore(string id, float mid, float lb, float fi,float bo, string inCl)
{
	studentID = id;
	midterm = mid;
	lab = lb;
	final = fi;
	bonus = bo;
	inClass = inCl;
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