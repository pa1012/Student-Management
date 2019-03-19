#include"School.h"

void School::loadLecturers(ArrOfAccount &Acc, ArrayOfCourse C) {
	stringstream str;
	str << "Data/Lecturer.csv";
	string fileName = str.str();

	ifstream fin;

	fin.open(fileName.c_str());
	string no, id, lastName, firstName, gender, date,course;

	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, id, ',');
		getline(fin, lastName, ',');
		getline(fin, firstName, ',');
		getline(fin, date, ',');
		getline(fin, gender, ',');
		getline(fin, course, '\n');
		int number;
		int sId;
		string pass;
		convertStringToInt(no, number);
		convertStringToInt(id, sId);
		convertDateToPass(date, pass);
		int gen = 0;
		if (gender[0] == 'F') gen = 1;
		if (number != -1) {
			Lecturer S;
			if (gender[0] == 'M')
				S.inputALecturer(id, lastName, firstName, 0, date);
			else
				S.inputALecturer(id, lastName, firstName, 1, date);
			if (!Acc.isValid(id)) Acc.input(id, pass, 2,id,lastName,firstName,date,gen,"",course,C);
			lecturers.push_back(S);
			S.clear();
		}

	}
	fin.close();
}

void School::loadAdmins(ArrOfAccount &Acc, ArrayOfCourse C) {
	stringstream str;
	str << "Data/Admin.csv";
	string fileName = str.str();

	ifstream fin;

	fin.open(fileName.c_str());
	string no, id, lastName, firstName, gender, date;

	while (!fin.eof())
	{

		getline(fin, no, ',');
		getline(fin, id, ',');
		getline(fin, lastName, ',');
		getline(fin, firstName, ',');
		getline(fin, date, ',');
		getline(fin, gender, '\n');
		

		int number;
		int sId;
		string pass;
		convertStringToInt(no, number);
		convertStringToInt(id, sId);
		convertDateToPass(date, pass);
		int gen = 0;
		if (gender[0] == 'F') gen = 1;
		if (number != -1) {
			Admin S;
			if (gender[0] == 'M')
				S.inputAAdmin(id, lastName, firstName, 0, date);
			else
				S.inputAAdmin(id, lastName, firstName, 1, date);
			if (!Acc.isValid(id)) Acc.input(id, pass, 0, id, lastName, firstName, date, gen,"","",C);
			admins.push_back(S);
			S.clear();
		}

	}
	fin.close();
}

void School::clear()
{

}

void School::initDataLecturer(ArrOfAccount &Acc) {
	vector <Account> acc;
	acc.clear();
	acc = Acc.returnRole(2);
	for (int j = 0; j < acc.size(); j++) {
		Lecturer S;
		S.inputALecturer(acc[j].getID(), acc[j].getLastName(), acc[j].getFirstName(), acc[j].getGender(), acc[j].getDate());
		lecturers.push_back(S);
	}


}

void School::initDataAdmin(ArrOfAccount &Acc) {
	vector <Account> acc;
	acc.clear();
	acc = Acc.returnRole(0);
	for (int j = 0; j < acc.size(); j++) {
		Admin S;
		S.inputAAdmin(acc[j].getID(), acc[j].getLastName(), acc[j].getFirstName(), acc[j].getGender(), acc[j].getDate());
		admins.push_back(S);
	}
}
