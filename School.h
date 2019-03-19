#pragma once

#include "Lecturer.h"
#include<vector>
#include"Convert.h"
#include"Admin.h"
#include"ArrayOfCourse.h"

using namespace std;

class School {
private:
	int numberOfLecturer;
	vector <Lecturer> lecturers;
	vector <Admin> admins;
	string name;
	int role;
public:
	void loadLecturers(ArrOfAccount &Acc,ArrayOfCourse C);
	void loadAdmins(ArrOfAccount &Acc,ArrayOfCourse C);
	void clear();
	void initDataLecturer(ArrOfAccount &Acc);
	void initDataAdmin(ArrOfAccount &Acc);
	
	/*void saveAdmins();
	void saveLectures();*/
};

