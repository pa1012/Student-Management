#include"Course.h"



void Course::inputACourse(string id, string nam, string lec, string year, int se, string startDt, string endDt, string inDay, string st, string en, string ro) {
	ID = id;
	name = nam;
	lecture = lec;
	inYear = year;
	semester = se;
	startDate = startDt;
	endDate = endDt;
	dayOfWeek = inDay;
	start = st;
	end = en;
	room = ro;
}

bool Course::isMatched(Course C)
{
	if (ID == C.getID() && semester == C.getSemester() && inYear == C.getYear()) return true;
	return false;
}

string Course::getID() {
	return ID;
}
int Course::getSemester() {
	return semester;
}
string Course::getYear() {
	return inYear;
}

bool Course::isMatchedID(string id) {
	return (ID == id);
}

void Course::printName() {
	cout << name<<endl;
}

string Course::getLecture()
{
	return lecture;
}

string Course::getStartDate()
{
	return startDate;
}

string Course::getEndDate()
{
	return endDate;
}

string Course::getDayOfWeek()
{
	return dayOfWeek;
}

string Course::getStart()
{
	return start;
}

string Course::getEnd()
{
	return end;
}

string Course::getRoom()
{
	return room;
}

string Course::getName() {
	return name;
}

void Course::save(int i) {
	ofstream fout;
	fout.open("Data/Course.csv", ios::app);
	fout << i << ',' << ID << ',' << name << ',' << lecture << ',' << inYear << ',' << semester << ',' << startDate << ',' << endDate << ',' << dayOfWeek << ',' << start << ',' << end << ',' << room << endl;
	fout.close();
}

void Course::updateCourseName(string s) {
	name = s;
}
void Course::updateDayOfWeek(string s) {
	dayOfWeek = s;

}
void Course::updateStart(string s) {
	start = s;
}
void Course::updateEnd(string s) {
	end = s;
}
void Course::updateRoom(string s) {
	room = s;
}