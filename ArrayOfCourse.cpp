#include"ArrayOfCourse.h"

void ArrayOfCourse::loadCourse() {
	stringstream str;
	str << "Data/Course.csv";
	string fileName = str.str();

	ifstream fin;

	fin.open(fileName.c_str());
	string no, id,name, clas,lecture,lectureID,year,semester,startDate,endDate,dayOfWeek,start,end,room;

	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, id, ',');
		getline(fin, name, ',');
		getline(fin, lecture, ',');
		getline(fin, lectureID, ',');
		getline(fin, year, ',');
		getline(fin, semester, ',');
		getline(fin, startDate, ',');
		getline(fin, endDate, ',');
		getline(fin, dayOfWeek, ',');
		getline(fin, start, ',');
		getline(fin, end, ',');
		getline(fin, room, '\n');

		int number;
		int se = semester[0] - '0';
		string pass;
		convertStringToInt(no, number);

		if (number != -1) {
			Course S;
			S.inputACourse(id, name,lecture, lectureID,year, se, startDate, endDate, dayOfWeek, start, end, room);
			if (!isExisted(S)) Arr.push_back(S);
		}

	}
	fin.close();
}

bool ArrayOfCourse::isExisted(Course C) {
	for (int i = 0; i < Arr.size(); i++)
		if (Arr[i].isMatched(C)) return true;

	return false;
}

void ArrayOfCourse::tryOutput() {
	for (int i = 0; i < Arr.size(); i++)
		cout << Arr[i].getID() << endl;
}

Course ArrayOfCourse::findACourse(string id) {
	for (int i = 0; i < Arr.size(); i++)
		if (Arr[i].isMatchedID(id)) return Arr[i];
	Course c;
	c.inputACourse("", "", "", "", "", 0, "", "", "", "", "", "" );
	return c;
}