#include"Attendance.h"

void Attendance::inputAttendance(string id, string week[5]) {
	ID = id;
	for (int i = 0; i < 5; i++)
		w[i] = week[i][0];
}
void Attendance::printOut() {
	cout << ID;
	for (int i = 0; i < 5; i++)
		cout << w[i];
	cout << endl;
}
void Attendance::clear() {

}