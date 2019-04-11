#include"ArrayOfCourse.h"

void ArrayOfCourse::loadCourse() {
	stringstream str;
	str << "Data/Course.csv";
	string fileName = str.str();

	ifstream fin;

	fin.open(fileName.c_str());
	string no, id, name, clas, lecture, lectureID, year, semester, startDate, endDate, dayOfWeek, start, end, room;

	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, id, ',');
		getline(fin, name, ',');
		getline(fin, lecture, ',');
		getline(fin, year, ',');
		getline(fin, semester, ',');
		getline(fin, startDate, ',');
		getline(fin, endDate, ',');
		getline(fin, dayOfWeek, ',');
		getline(fin, start, ',');
		getline(fin, end, ',');
		getline(fin, room, '\n');

		int number;
		int se = semester[0] - '0';
		string pass;
		convertStringToInt(no, number);

		if (number != -1) {
			Course S;
			S.inputACourse(id, name, lecture, year, se, startDate, endDate, dayOfWeek, start, end, room);
			if (!isExisted(S)) Arr.push_back(S);
		}

	}
	fin.close();
}

bool ArrayOfCourse::isExisted(Course C) {
	for (int i = 0; i < Arr.size(); i++)
		if (Arr[i].isMatched(C)) return true;

	return false;
}

void ArrayOfCourse::tryOutput() {
	for (int i = 0; i < Arr.size(); i++)
		cout << Arr[i].getID() << endl;
}

Course ArrayOfCourse::findACourse(string id) {
	for (int i = 0; i < Arr.size(); i++)
		if (Arr[i].isMatchedID(id)) return Arr[i];
	Course c;
	c.inputACourse("", "", "", "", 0, "", "", "", "", "", "");
	return c;
}

vector<Course> ArrayOfCourse::returnCourses(string year, int term)
{
	vector<Course> arr;
	for (int i = 0; i < Arr.size(); i++) {
		if (Arr[i].getSemester() == term && Arr[i].getYear() == year) {
			arr.push_back(Arr[i]);
		}
	}
	return arr;
}

void ArrayOfCourse::loadCourse(string y, int term) {
	stringstream str;
	str << "import/" << y<<"_"<<term<<".csv";
	string fileName = str.str();

	ifstream fin;

	fin.open(fileName.c_str());

	if (fin.fail()) return;
	string no, id, name, clas, lecture, lectureID, year, semester, startDate, endDate, dayOfWeek, start, end, room;

	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, id, ',');
		getline(fin, name, ',');
		getline(fin, lecture, ',');
		getline(fin, year, ',');
		getline(fin, semester, ',');
		getline(fin, startDate, ',');
		getline(fin, endDate, ',');
		getline(fin, dayOfWeek, ',');
		getline(fin, start, ',');
		getline(fin, end, ',');
		getline(fin, room, '\n');

		int number;
		int se = semester[0] - '0';
		string pass;
		convertStringToInt(no, number);
		
		if (number != -1) {
			Course S;
			S.inputACourse(id, name, lecture, year, se, startDate, endDate, dayOfWeek, start, end, room);
			if (!isExisted(S)) Arr.push_back(S);
		}

	}
	fin.close();

}

void ArrayOfCourse::saveCourse() {
	ofstream fout;
	fout.open("Data/Course.csv");
	fout.clear();
	fout << "No,ID,CourseName,Lecture name,Year,Term,Start Date,End Date,Day,Start,End,Room" << endl;
	for (int i = 0; i < Arr.size(); i++)
	{
		Arr[i].save(i+1);
	}
	fout.close();
}

void ArrayOfCourse::deleteAll(string year, int term) {
	int i = 0;
	while (i < Arr.size())
	{
		if (Arr[i].getYear() == year && Arr[i].getSemester() == term) {
			Arr.erase(Arr.begin() + i);
		}
		else i++;
	}
}

void ArrayOfCourse::pushCourse(Course C) {
	Arr.push_back(C);
}

int ArrayOfCourse::size() {
	return Arr.size();
}
string ArrayOfCourse::nameOfCourse(int i) {
	return Arr[i].getID();
}

void ArrayOfCourse::removeCourse(string ID) {
	for (int i = 0 ; i < Arr.size(); i++)
		if (Arr[i].isMatchedID(ID)) {
			Arr.erase(Arr.begin() + i);
			break;
		}
}

void ArrayOfCourse::editCourse(string ID, string what, string inform) {
	for (int i = 0; i < Arr.size(); i++) {
		if (Arr[i].isMatchedID(ID)) {
			if (what == "CourseName") Arr[i].updateCourseName(inform);
			if (what == "Day") Arr[i].updateDayOfWeek(inform);
			if (what == "Start") Arr[i].updateStart(inform);
			if (what == "End") Arr[i].updateEnd(inform);
			if (what == "Room") Arr[i].updateRoom(inform);
			break;
		}
	}
}

vector<Course> ArrayOfCourse::returnCourses() {
	return Arr;
}

bool ArrayOfCourse::isExisted(string courseID) {
	for (int i = 0; i < Arr.size(); i++)
		if (Arr[i].isMatchedID(courseID)) return true;
	return false;
}