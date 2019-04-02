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
	int week;
public:
	void input(string y, int t, int w);
	void printOut();
	string getYear();
	int getTerm();
	int getWeek();
};

void loadTime(vector<Time> &time);
