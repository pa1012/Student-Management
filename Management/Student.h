#include<iostream>
#include<fstream>
#include<sstream>
#include"ArrayOfAccount.h"

using namespace std;

class Student {
private:
	long long ID;
	string lastName;
	string firstName;
	int gender;
	string date;
public:
	void inputAStudent(int id, string last, string first, int gen, string d);
	void clear();
};