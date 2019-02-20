#include<iostream>
#include<fstream>
#include<sstream>
#include"ArrayOfAccount.h"

using namespace std;

class Student {
private:
	long long ID;
	char* lastName;
	char* firstName;
	int gender;
	char* date;
public:
	void inputAStudent(int id, char last[], char first[], int gen, char d[]);
};