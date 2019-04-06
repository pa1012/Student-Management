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
			a.inputAttendance(id, week,courseName);
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

bool AttendanceList::isMatchCourse(string courseID) {
	return courseID == courseName;
}

vector<Attendance> AttendanceList::returnAttendance() {
	return Arr;
}
vector<Attendance> returnAttendance(vector<AttendanceList> attend, Account Acc) {
	vector<Course> course = Acc.returnCourses();
	vector<Attendance> At;
	for (int i =0; i < course.size(); i++)
	{
		for (int j = 0; j < attend.size(); j++) {
			if (attend[j].isMatchCourse(course[i].getID())) {
				At.push_back(attend[j].getAttendance(Acc.getID()));
			}
		}

	}
	return At;
}

Attendance AttendanceList::getAttendance(string stID) {
	for (int i = 0; i < Arr.size(); i++)
		if (Arr[i].isMatchStudentID(stID))
	{
			return Arr[i];
	}
}

void AttendanceList::updateAttendance(string studentID, int week,Time time) {
	for (int i = 0 ; i < Arr.size(); i++)
		if (Arr[i].isMatchStudentID(studentID)) {
			Arr[i].update(week,time);
		}
}

void updateAttendance(vector<AttendanceList> &attendanceList, string studentID, string courseID, int week,Time time) {
	for (int i = 0 ; i < attendanceList.size();  i++)
		if (attendanceList[i].isMatchCourse(courseID)) {
			attendanceList[i].updateAttendance(studentID, week,time);
			break;
		}
}

void initTableAttendance(vector<AttendanceList> &attendanceList, Time  time) {
	for (int i = 0; i < attendanceList.size(); i++)
		attendanceList[i].initData(time);

}

void AttendanceList::initData(Time time) {
	for (int i = 0; i < Arr.size(); i++) {
		Arr[i].initData(time);
	}
}

void saveAttendance(vector<AttendanceList> &attendanceList) {
	for (int i = 0; i < attendanceList.size(); i++) {
		attendanceList[i].save();
	}
}

void AttendanceList::save() {
	ofstream fout;
	string fileName = "Data/attendance/" + courseName + ".csv";

	fout.open(fileName);
	fout << "StudentID,Week 1,Week 2,Week 3,Week 4,Week 5" << endl;
	for (int i = 0; i < Arr.size(); i++) {
		Arr[i].save();
	}

	fout.close();
}

void removeAttendance(vector<AttendanceList> & attendanceList, Account account) {
	vector <Course> course = account.returnCourses();
	for (int i = 0; i < course.size(); i++)
		for (int j = 0; j < attendanceList.size(); j++)
			if (attendanceList[j].isMatchCourse(course[i].getID()))
			{
				attendanceList[j].removeAttendance(account.getID());
			}
}

void AttendanceList::removeAttendance(string studentID) {
	for (int i = 0; i < Arr.size(); i++)
		if (Arr[i].getStudentID() == studentID) {
			Arr.erase(Arr.begin() + i);
			break;
		}
}

void addToAttendance(vector <AttendanceList> & attendanceList, Account account) {
	vector <Course> course = account.returnCourses();
	for (int i = 0; i < course.size(); i++)
		for (int j = 0; j < attendanceList.size();j++)
			if (attendanceList[j].isMatchCourse(course[i].getID()))
			{
				attendanceList[j].addAttendance(account.getID());
			}
}

void AttendanceList::addAttendance(string studentID) {
	Attendance at;
	at.init(studentID,courseName);
	Arr.push_back(at);
}