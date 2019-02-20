#include "Student.h"
#include<vector>
#include"Convert.h"


using namespace std;

class Class {
private:
	int numberOfStudent;
	vector <Student> students;
	char* name;
public:
	void inputAClass(int n, char c[], ArrOfAccount &Acc);
	void outputAClass();
	void inputStudents(ArrOfAccount &Acc);
};