#include "ArrayOfAccount.h"


void ArrOfAccount::loadAccountStudent() {
	stringstream str;
	str << "Data/Account.csv";
	string fileName = str.str();

	ifstream fin;

	fin.open(fileName.c_str());
	char name[100], pass[100];
	char role[3];
	n = 0;
	A.clear();
	bool firstTime = true;
	while (fin.eof())
	{
		if (!firstTime) {
			fin.ignore();
			
		}
		firstTime = false;
		fin.get(name,100, ',');
		fin.ignore();
		fin.get(pass,100, ',');
		fin.ignore();
		fin.get(role, 3, '\n');
		Account a;
		if (strcmp(name, "") != 0) {
			a.createAccount(name, pass, role[0] - '0');
			A.push_back(a);
			n++;
		}
	}
}

bool ArrOfAccount::isValid(char id[]) {
	for (int i = 0; i < A.size(); i++)
		if (A[i].checkUsername(id)) return true;
	return false;
}

void ArrOfAccount::input(char name[], char pass[], int role) {
	Account a;
	a.createAccount(name, pass, role);
	A.push_back(a);
	n++;
}

void ArrOfAccount::saveAccount() {
	ofstream fout;
	fout.open("Data/Account.csv");
	fout.clear();
	fout.close();
	for (int i = 0; i < A.size(); i++) {
		A[i].output(); 
	}

}

ArrOfAccount::ArrOfAccount() {
	n = 0;
	A.clear();
}