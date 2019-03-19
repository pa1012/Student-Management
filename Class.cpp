#include"Class.h"

void Class::inputAClass(int n, string c, ArrOfAccount &Acc,ArrayOfCourse C) {
	numberOfStudent = n;
	name = c;
	loadStudents(Acc,C);
}

void Class::loadStudents(ArrOfAccount &Acc,ArrayOfCourse C) {
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
		getline(fin, firstName, ',');
		getline(fin, gender, ',');
		getline(fin, date, '\n');

		int number;
		int sId;
		string pass;
		convertStringToInt(no, number);
		convertStringToInt(id, sId);
		convertDateToPass(date, pass);
		int tmp = 0;
		if (gender[0] == 'F') tmp = 1;
		if (number != -1) {
			Student S;
			S.inputAStudent(id, lastName, firstName, tmp, date);
			if (!Acc.isValid(id)) Acc.input(id, pass, 1,id,lastName,firstName,date,tmp,name,"",C);
			students.push_back(S);
			S.clear();
		}

	}
	fin.close();
}

void Class::clear() {
	
}

string Class::getName() {
	return name;
}

void Class::save() {
	ofstream fout;
	fout.open("Data/Class.txt",ios::app);
	fout << students.size() << " " << name<<endl;
	fout.close();
}

void Class::inputName(string c) {
	name = c;
}

void Class::pushStudent(Student S) {
	students.push_back(S);
}