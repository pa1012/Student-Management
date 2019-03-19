#pragma once

#include "Student.h"
#include<vector>
#include"Convert.h"
#include"ArrayOfAccount.h"
#include"ArrayOfCourse.h"

using namespace std;

class Class {
private:
	int numberOfStudent;
	vector <Student> students;
	string name;
public:
	void inputAClass(int n, string c, ArrOfAccount &Acc,ArrayOfCourse C);
	void outputAClass();
	void loadStudents(ArrOfAccount &Acc,ArrayOfCourse C);
	void clear();
	string getName();
	void save();
	void inputName(string c);
	void pushStudent(Student S);
};