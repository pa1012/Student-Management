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