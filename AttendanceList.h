#pragma once
#include"Attendance.h"
#include"ArrayOfCourse.h"
#include"ArrayOfAccount.h"

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
	bool isMatchCourse(string courseID);
	vector<Attendance> returnAttendance();
	Attendance getAttendance(string stID);
	void updateAttendance(string studentID, int week, Time time);
	void initData(Time time);
	void save();
	void removeAttendance(string studentID);
	void addAttendance(string studentID);
};
void loadfileAttendance(vector<AttendanceList> &attendanceList, ArrayOfCourse course);
vector<Attendance> returnAttendance(vector<AttendanceList> attend, Account Acc);
void updateAttendance(vector<AttendanceList> &attendanceList, string studentID,string courseID, int week, Time time);
void initTableAttendance(vector<AttendanceList> &attendanceList,Time  time);
void saveAttendance(vector<AttendanceList> &attendanceList);
void removeAttendance(vector<AttendanceList> & attendanceList, Account account);
void addToAttendance(vector <AttendanceList> & attendanceList, Account account);

void removeAttendance(vector<AttendanceList> &attendanceList, Account account, string courseID);
void addToAttendance(vector<AttendanceList> &attendanceList, Account account, string courseID);