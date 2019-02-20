#include"Student.h"


void Student::inputAStudent(int id, char last[], char first[], int gen, char d[]) {
	ID = id;

	lastName = new char[strlen(last) + 1];
	strcpy(lastName, last);

	firstName = new char[strlen(first) + 1];
	strcpy(firstName, first);

	gender = gen;

	date = new char[strlen(d) + 1];
	strcpy(date, d);
}

