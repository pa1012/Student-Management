#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class Attendance {
private:
	string ID;
	char w[5];
public:
	void inputAttendance(string id, string week[5]);
	void printOut();
	void clear();
};