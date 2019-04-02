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
	void loadCourse(string year, int term);
	bool isExisted(Course C);
	bool isExisted(string courseID);
	void tryOutput();
	Course findACourse(string id);
	vector<Course> returnCourses(string y, int term);
	vector<Course> returnCourses();
	void saveCourse();
	void deleteAll(string year, int term);
	void pushCourse(Course C);
	int size();
	string nameOfCourse(int i);
	void removeCourse(string ID);
	void editCourse(string ID, string what, string inform);
};