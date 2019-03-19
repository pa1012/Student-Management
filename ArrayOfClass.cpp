#include"ArrayOfClass.h"

void ArrayOfClass::load(ArrOfAccount &Acc,ArrayOfCourse course) {
	ifstream fin;
	fin.open("Data/Class.txt");
	fin >> numberOfClass;
	for (int i = 0; i < numberOfClass; i++) {
		int numberOfStudent;
		string c;
		fin >> numberOfStudent;
		fin.ignore();
		fin >> c;
		Class C;
		C.inputAClass(numberOfStudent, c, Acc,course);
		Arr.push_back(C);
		C.clear();
	}
	fin.close();
}

void ArrayOfClass::clear() {
	
}

int ArrayOfClass::getSize() {
	return Arr.size();
}

string ArrayOfClass::getName(int i) {
	return Arr[i].getName();
}

void ArrayOfClass::pushClass(Class C) {
	Arr.push_back(C);
	
}

void ArrayOfClass::save() {
	ofstream fout;
	fout.open("Data/Class.txt");
	fout.clear();
	fout << Arr.size() << endl;
	fout.close();
	for (int i = 0; i < Arr.size(); i++)
		Arr[i].save();
}

void ArrayOfClass::initData(ArrOfAccount &Acc) {
	vector <Account> acc;
	for (int i = 0; i < Arr.size(); i++) {
		acc.clear();
		acc = Acc.returnClass(Arr[i].getName());
		for (int j = 0; j < acc.size(); j++) {
			Student S;
			S.inputAStudent(acc[j].getID(), acc[j].getLastName(), acc[j].getFirstName(), acc[j].getGender(), acc[j].getDate());
			Arr[i].pushStudent(S);
		}
	}
	
}

void ArrayOfClass::loadList() {
	ifstream fin;
	fin.open("Data/Class.txt");
	fin >> numberOfClass;
	for (int i = 0; i < numberOfClass; i++) {
		int numberOfStudent;
		string c;
		fin >> numberOfStudent;
		fin.ignore();
		fin >> c;
		Class C;
		C.inputName(c);
		Arr.push_back(C);
		C.clear();
	}
	fin.close();
}