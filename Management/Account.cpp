#include"Account.h"

void Account::createAccount(const string name, string pass, int r) {
	username = name;

	password = pass;

	role = r;
}

bool Account::checkUsername(string id) {
	if (id == username) return true;
	return false;
}

void Account::output() {
	ofstream fout;
	fout.open("Data/Account.csv",ios::app);
	fout << username << ',' << password << ',' << role << '\n';
	fout.close();
}

bool Account::isMatchName(string c) {
	return (c == username);
}

bool Account::isMatchPass(string c) {
	return (c== password);
}

void Account::tryOutput() {
	cout << username << endl;
	cout << password << endl;
	cout << role << endl;
}

void Account::clear() {
}

int Account::getRole() {
	return role;
}