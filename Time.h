#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

class  Time
{
private:
	string year;
	int term;
public:
	void input(string y, int t);
	void printOut();
	string getYear();
	int getTerm();
};

void loadTime(vector<Time> &time);
