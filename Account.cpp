#include"Account.h"

void Account::createAccount(const string name, string pass, int r, string ID, string last, string first, string date, int gen,string clas,string course,ArrayOfCourse C){
	username = name;
	password = pass;
	role = r;
	id = ID;
	lastName = last;
	firstName = first;
	doB = date;
	gender = gen;
	inClass = clas;
	course = course + ' ';
	if (course != "") {
		string c;
		for (int i = 0; i < course.size(); i++)
		{
			if (course[i] != ' ') c = c + course[i];
			else {
				Course co = C.findACourse(c);
				if (co.getID() != "") courses.push_back(co);
				c = "";
			}
		}

	}
}	

bool Account::checkUsername(string id) {
	if (id == username) return true;
	return false;
}

void Account::output() {
	ofstream fout;
	fout.open("Data/Account.csv",ios::app);
	fout << username << ',' << password << ',' << role << ',' << id << ',' << lastName << ',' << firstName << ',' << doB << ',' << gender << ',' << mergeCourses() << ',' << inClass << endl;
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

string Account::getLastName() {
	return lastName;
}
string Account::getFirstName() {

	return firstName;
}

int Account::getGender() {
	return gender;
}

string Account::getDate() {
	return doB;
}

string Account::getUsername() {
	return username;
}

string Account::getID() {
	return id;
}

void Account::printCourse() {
	for (int i = 0; i < courses.size(); i++)
		courses[i].printName();
}

string Account::mergeCourses() {
	string s = "";
	for (int i = 0; i < courses.size(); i++)
	{
		s = s + courses[i].getID() + " ";
	}
	//s.erase(s.end(), s.end());
	return s;
}

string Account::getPassword() {
	return password;
}

void Account::updatePassword(string passwordForChange) {
	password = passwordForChange;
}

bool Account::isMatchClass(string name) {
	return (inClass == name);
}

bool Account::isMatchRole (int r) {
	return (role == r);
}

bool Account::isMatchCourse(string name)
{
	for (int i = 0; i < courses.size(); i++)
	{
		if (courses[i].isMatchedID(name))
			return true;
	}
	return false;
}

string Account::getinClass()
{
	return inClass;
}

void Account::changePassword(string toChange) {
	password = toChange;
}
void Account::changeLastName(string toChange) {
	lastName = toChange;
}
void Account::changeFirstName(string toChange) {
	firstName = toChange;
}
void Account::changeGender(string toChange) {
	if (toChange[0] == 'M') gender = 0;
	else gender = 1;
}
void Account::changeDoB(string toChange) {
	doB = toChange;
}

void Account::changeClass(string toChange) {
	inClass = toChange;
}

void Account::addCourse(Course C) {
	courses.push_back(C);
}

void Account::removeCourse(string courseID) {
	for (int i = 0 ; i < courses.size() ; i++)
		if (courses[i].isMatchedID(courseID)) {
			courses.erase(courses.begin() + i);
			return;
		}
}

void Account::addCourse(string courseName, ArrayOfCourse course) {
	for (int i = 0; i < courses.size(); i++)
		if (courses[i].isMatchedID(courseName)) return;
	Course C = course.findACourse(courseName);
	courses.push_back(C);
}

vector <Course> Account::returnCourses() {
	return courses;
}