#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include"ArrayOfCourse.h"

using namespace std;

class Account {
private:
	string id;
	string lastName, firstName;
	string username;
	string password;
	string doB;
	string inClass;
	int role,gender;
	vector<Course> courses;
public:
	void createAccount(const string name, string pass, int r, string ID, string last, string first, string date, int gen,string clas,string course,ArrayOfCourse C);
	bool checkUsername(string id);
	void output();
	bool isMatchName(string c);
	bool isMatchPass(string c);
	void tryOutput();
	void clear();
	int getRole();
	string getLastName();
	string getFirstName();
	int getGender();
	string getDate();
	string getUsername();
	string getID();
	string getPassword();
	void printCourse();
	string mergeCourses();
	void updatePassword(string passwordForChange);
	bool isMatchClass(string name);
	bool isMatchRole(int role);
	bool isMatchCourse(string name);
	string getinClass();
	void changePassword(string toChange);
	void changeLastName(string toChange);
	void changeFirstName(string toChange);
	void changeGender(string toChange);
	void changeDoB(string toChange);
	void changeClass(string toChange);
};

