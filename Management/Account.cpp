#include"Account.h"

void Account::createAccount(char name[], char pass[], int r) {
	username = new char[strlen(name) + 1];
	strcpy(username, name);

	password = new char[strlen(pass) + 1];
	strcpy(password, pass);

	role = r;
}

bool Account::checkUsername(char id[]) {
	if (strcmp(id, username) == 0) return true;
	return false;
}

void Account::output() {
	ofstream fout;
	fout.open("Data/Account.csv",ios::app);
	fout << username << ',' << password << ',' << role << '\n';
	fout.close();
}