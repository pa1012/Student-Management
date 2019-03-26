#pragma once

#include"Course.h"
#include<vector>
#include<sstream>
#include<fstream>
#include"Convert.h"

using namespace std;

class ArrayOfCourse {
private:
	vector <Course> Arr;
public:
	void loadCourse();
	bool isExisted(Course C);
	void tryOutput();
	Course findACourse(string id);
	vector<Course> returnCourses();
};