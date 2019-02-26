#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

class Account {
private:
	string username;
	string password;
	int role;
public:
	void createAccount(const string name, string pass, int r);
	bool checkUsername(string id);
	void output();
	bool isMatchName(string c);
	bool isMatchPass(string c);
	void tryOutput();
	void clear();
	int getRole();
};