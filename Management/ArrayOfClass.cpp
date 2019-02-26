#include"ArrayOfClass.h"

void ArrayOfClass::load(ArrOfAccount &Acc) {
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
		C.inputAClass(numberOfStudent, c, Acc);
		Arr.push_back(C);
		C.clear();
	}
	fin.close();
}

void ArrayOfClass::clear() {
	
}