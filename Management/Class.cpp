#include"Class.h"

void Class::inputAClass(int n, string c, ArrOfAccount &Acc) {
	numberOfStudent = n;
	name = c;
	inputStudents(Acc);
}

void Class::inputStudents(ArrOfAccount &Acc) {
	stringstream str;
	str << "Data/" << name << "-Students.csv";
	string fileName = str.str();

	ifstream fin;
	
	fin.open(fileName.c_str());
	string no, id, lastName, firstName, gender, date;
	
	while (!fin.eof())
	{
		
		
		getline(fin, no, ',');
		
		getline(fin, id, ',');
		
		getline(fin, lastName, ',');
	;
		getline(fin, firstName, ',');
	
		getline(fin, gender, ',');
		
		getline(fin, date, '\n');

		int number;
		int sId;
		string pass;
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
			S.clear();
		}

	}
	fin.close();
}

void Class::clear() {
	
}