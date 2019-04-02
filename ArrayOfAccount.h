#pragma once


#include<vector>
#include"Account.h"

using namespace std;

class ArrOfAccount {
private:
	int n;
	vector <Account> A;
public:
	void loadAccount(ArrayOfCourse C);
	bool isValid(string id);
	void input(string name, string pass, int role, string ID, string last, string first, string date, int gen,string clas,string course, ArrayOfCourse C);
	void saveAccount();
	int findUsername(string c);
	bool checkPassword(string c, int k);
	Account getAccount(int k);
	Account getAccount(string ID);
	ArrOfAccount();
	void clear();
	void updatePassword(string ID, string pass);
	vector<Account> returnClass(string name);
	vector<Account> returnRole(int role);
	vector<Account> returnStudent(string couseName);
	void pushAccount(Account a);
	void removeAccount(string ID);
	void updateCourse(ArrayOfCourse course, string year, int term);
	string returnCourse(string className);
	void removeCourseInAccount(string courseID);
	void addCourse(string ID, string courseName, ArrayOfCourse course);
	void removeCourseInAccount(string ID, string courseID);
	void addCourseToClass(string cl, string courseID, ArrayOfCourse course);
};

