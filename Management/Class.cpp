#include"Class.h"

void Class::inputAClass(int n, char c[], ArrOfAccount &Acc) {
	numberOfStudent = n;
	name = new char[strlen(c) + 1];
	strcpy(name, c);
	inputStudents(Acc);
}

void Class::inputStudents(ArrOfAccount &Acc) {
	stringstream str;
	str << "Data/" << name << "-Students.csv";
	string fileName = str.str();

	ifstream fin;
	
	fin.open(fileName.c_str());
	char no[100], id[100], lastName[100], firstName[100], gender[100], date[100];
	bool firstTime = true;
	while (!fin.eof())
	{
		if (!firstTime) fin.ignore();
		firstTime = false;
		fin.get(no,100,',');
		fin.ignore();
		fin.get(id,100, ',');
		fin.ignore();
		fin.get(lastName,100, ',');
		fin.ignore();
		fin.get(firstName,100, ',');
		fin.ignore();
		fin.get(gender,100, ',');
		fin.ignore();
		fin.get(date,100, '\n');

		int number;
		int sId;
		char pass[100];
		convertStringToInt(no, number);
		convertStringToInt(id, sId);
		convertDateToPass(date, pass);
		if (number != -1) {
			Student S;
			if (gender[0] = 'M')
				S.inputAStudent(sId, lastName, firstName, 0, date);
			else
				S.inputAStudent(sId, lastName, firstName, 1, date);
			if (!Acc.isValid(id)) Acc.input(id, pass, 1);
		}

	}
	fin.close();
}