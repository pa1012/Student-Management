#pragma once

#include<iostream>
#include<fstream>
#include<sstream>


using namespace std;

class Student {
private:
	string ID;
	string lastName;
	string firstName;
	int gender;
	string date;
public:
	void inputAStudent(string id, string last, string first, int gen, string d);
	void clear();
};