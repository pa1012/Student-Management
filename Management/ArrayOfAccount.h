#include"Account.h"
#include<vector>

using namespace std;

class ArrOfAccount {
private:
	int n;
	vector <Account> A;
public:
	void loadAccount();
	void loadAccountLecturer();
	void loadAccountAdmin();
	bool isValid(string id);
	void input(string name, string pass, int role);
	void saveAccount();
	int findUsername(string c);
	bool checkPassword(string c, int k);
	Account getAccount(int k);
	ArrOfAccount();
	void clear();
};