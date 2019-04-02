#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include"Time.h"
using namespace std;

class Attendance {
private:
	string ID;
	char w[5];
	string courseID;
public:
	void inputAttendance(string id, string week[5],string courseName);
	void printOut();
	void clear();
	string getStudentID();
	string getWeek1();
	string getWeek2();
	string getWeek3();
	string getWeek4();
	string getWeek5();
	string getCourseID();
	bool isMatchStudentID(string stID);
	void update(int week,Time time);
	void initData(Time time);
	void save();
};