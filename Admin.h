#pragma once

#include<iostream>
#include<fstream>
#include<sstream>
#include"ArrayOfAccount.h"

using namespace std;

class Admin {
private:
	string ID;
	string lastName;
	string firstName;
	int gender;
	string date;
	int role;
public:
	void inputAAdmin(string id, string last, string first, int gen, string d);
	void clear();
	int getRole();
};


