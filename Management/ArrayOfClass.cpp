#include"ArrayOfClass.h"

void ArrayOfClass::load(ArrOfAccount &Acc) {
	ifstream fin;
	fin.open("Data/Class.txt");
	fin >> numberOfClass;
	for (int i = 0; i < numberOfClass; i++) {
		int numberOfStudent;
		char c[100];
		fin >> numberOfStudent;
		fin.ignore();
		fin.get(c, 100, '\n');
		Class C;
		C.inputAClass(numberOfStudent, c, Acc);
		Arr.push_back(C);
	}
	fin.close();
}