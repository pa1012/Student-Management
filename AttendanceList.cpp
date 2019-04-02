#include"AttendanceList.h"

void AttendanceList::inputCourseName(string name) {
	courseName = name;
}

void AttendanceList::loadAttendance() {
	ifstream fin;
	string nameFile = "Data/attendance/" + courseName + ".csv";
	fin.open(nameFile);
	string id, week[5];
	fin.ignore(1000, '\n');
	while (!fin.eof()) {
		getline(fin, id, ',');
		getline(fin, week[0], ',');
		getline(fin, week[1], ',');
		getline(fin, week[2], ',');
		getline(fin, week[3], ',');
		getline(fin, week[4], '\n');

		Attendance a;
		if (id != "") {
			a.inputAttendance(id, week);
			Arr.push_back(a);
			a.clear();
		}
	}
	fin.close();
}
void AttendanceList::printOut() {
	for (int i = 0; i < Arr.size(); i++) {
		Arr[i].printOut();
	}
}
void AttendanceList::clear() {
	Arr.clear();
	courseName = "";
}

void loadfileAttendance(vector<AttendanceList> &attendanceList, ArrayOfCourse course) {
	int n = course.size();
	AttendanceList A;
	for (int i = 0; i < n; i++)
	{
		string courseName = course.nameOfCourse(i);
		A.clear();
		A.inputCourseName(courseName);
		A.loadAttendance();
		attendanceList.push_back(A);
	}
}