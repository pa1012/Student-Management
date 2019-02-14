#include<iostream>
#include<fstream>
#include"Date.h"

using namespace std;

class Student {
private:
	long long ID;
	char* lastName;
	char* firstName;
	int gender;
	Date birthday;
public:
	void inputAStudent();
	void outputAStudent();
	void createAcount();
};