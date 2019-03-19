#pragma once

#include<iostream>
#include"Class.h"
#include<vector>


using namespace std;

class ArrayOfClass {
private:
	int numberOfClass;
	vector <Class> Arr;
public:
	void load(ArrOfAccount &Acc,ArrayOfCourse course);
	void clear();
	int getSize();
	string getName(int i);
	void pushClass(Class C);
	void save();
	void initData(ArrOfAccount &Acc);
	void loadList();
};

