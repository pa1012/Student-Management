#pragma once
#include"Attendance.h"
#include"ArrayOfCourse.h"

using namespace std;

class AttendanceList {
private:
	string courseName;
	vector< Attendance> Arr;
public:
	void loadAttendance();
	void printOut();
	void inputCourseName(string name);
	void clear();
};
void loadfileAttendance(vector<AttendanceList> &attendanceList, ArrayOfCourse course);
