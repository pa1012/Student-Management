#include"Attendance.h"

void Attendance::inputAttendance(string id, string week[5], string courseName) {
	ID = id;
	for (int i = 0; i < 5; i++)
		w[i] = week[i];
	courseID = courseName;
}
void Attendance::printOut() {
	cout << ID;
	for (int i = 0; i < 5; i++)
		cout << w[i];
	cout << endl;
}
void Attendance::clear() {

}
string Attendance::getStudentID() {
	return ID;
}
string Attendance::getWeek1() {
	
	return w[0];
}
string Attendance::getWeek2() {
	return w[1];
}
string Attendance::getWeek3() {
	return w[2];
}
string Attendance::getWeek4() {
	return w[3];
}
string Attendance::getWeek5() {
	return w[4];
}
string Attendance::getCourseID() {
	return courseID;
}
bool Attendance::isMatchStudentID(string stID) {
	return ID == stID;
}

void Attendance::update(int week ,Time time) {
	if (time.getWeek() == week )
		w[week - 1] = "X";
}

void Attendance::initData(Time time) {
	int week = time.getWeek()-1;
	for(int i=0; i<week; i++)
		if (w[i] != "X") {
			w[i] = "A";
		}
}

void Attendance::save() {
	ofstream fout;
	string fileName = "Data/attendance/" + courseID + ".csv";
	fout.open(fileName, ios::app);
	fout << ID << ',' << w[0] << ',' << w[1] << ',' << w[2] << ',' << w[3] << ',' << w[4] << endl;
	fout.close();
}

void Attendance::save0() {
	ofstream fout;
	string fileName = "export/attendance/" + courseID + ".csv";
	fout.open(fileName, ios::app);
	fout << ID << ',' << w[0] << ',' << w[1] << ',' << w[2] << ',' << w[3] << ',' << w[4] << endl;
	fout.close();
}

void Attendance::init(string std, string course) {
	ID = std;
	courseID = course;
	for (int i = 0; i < 5; i++) w[i] = "";
}

