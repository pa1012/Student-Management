#pragma once

#include<iostream>
#include<fstream>
#include<sstream>
#include"ArrayOfAccount.h"


using namespace std;

class Lecturer {
private:
	string ID;
	string lastName;
	string firstName;
	int gender;
	string date;
	vector <Course> course;
public:
	void inputALecturer(string id, string last, string first, int gen, string d);
	void clear();
};

