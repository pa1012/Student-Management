#include "ArrayOfAccount.h"


void ArrOfAccount::loadAccount() {
	stringstream str;
	str << "Data/Account.csv";
	string fileName = str.str();

	ifstream fin;

	fin.open(fileName.c_str());
	string name, pass, role;
	n = 0;
	A.clear();
	
	while (fin.eof())
	{
		getline(fin, name, ',');
		getline(fin, pass, ',');
		getline(fin, role, '\n');
		Account a;
		if (name != "") {
			a.createAccount(name, pass, role[0] - '0');
			A.push_back(a);
			n++;
		}
		a.clear();
	}
}

bool ArrOfAccount::isValid(string id) {
	for (int i = 0; i < A.size(); i++)
		if (A[i].checkUsername(id)) return true;
	return false;
}

void ArrOfAccount::input(string name, string pass, int role) {
	Account a;
	a.createAccount(name, pass, role);
	A.push_back(a);
	n++;
	a.clear();
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

int ArrOfAccount::findUsername(string c) {
	for (int i = 0; i < A.size(); i++)
		if (A[i].isMatchName(c)) return i;
	return -1;
}

bool ArrOfAccount::checkPassword(string c, int k) {
	return A[k].isMatchPass(c);
}

Account ArrOfAccount::getAccount(int k) {
	return A[k];
}

void ArrOfAccount::clear() {
	for (int i = 0; i < A.size(); i++)
		A[i].clear();
	A.clear();
}