#include <SFML/Graphics.hpp>
#include"LoadData.h"
#include"Login.h"
#include"ScreenControl.h"
#include"ArrayOfAccount.h"
#include"School.h"
#include"MenuStudent.h"
#include"MenuOfLecture.h"
#include"MenuOfAdmin.h"
#include"RenderTable.h"
#include"Time.h"
#include"ScoreBoard.h"
#include"AttendanceList.h"

enum AppState {
	LOGIN, STUDENT, LECTURER, ADMIN
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(1800, 800), "Student Management");

	Time time;
	ifstream fin;
	fin.open("Data/Time.txt");
	string y;
	int t, w;
	fin >> y;
	fin >> t >> w;
	time.input(y, t, w);
	fin.close();

	ArrayOfCourse course;
	course.loadCourse();

	ArrOfAccount Acc;
	Acc.loadAccount(course);

	vector<ScoreBoard> scoreBoard;
	vector<AttendanceList>  attendanceList;

	loadfileScore(scoreBoard, course);
	loadfileAttendance(attendanceList, course);
	initTableAttendance(attendanceList, time);

	ArrayOfClass Class;
	Class.loadList();
	Class.initData(Acc);

	
	School school;
	school.initDataLecturer(Acc);
	school.initDataAdmin(Acc);

	
	AppState state = LOGIN;

	Login login;
	login.initGraphic();

	Screen screenControl;
	

	sf::Texture rectTexture;
	sf::Sprite rect;
	sf::View view;

	MenuOfStudent menuStudent;

	MenuOfAdmin menuAdmin;

	MenuOfLecturer menuLecturer;

	vector<AccountGraphic> accountGraphic;
	vector<CourseGraphic> courseGraphic;
	vector<StudentGraphic> studentGraphic;
	vector<ScoreGraphic> scoreGraphic;
	vector<AttendanceGraphic> attendanceGraphic;

	Account account;

	loadTexture("rect.png", rectTexture);
	rect.setPosition(1772, 0);
	rect.setTexture(rectTexture);

	view.reset(sf::FloatRect(0.0, 0.0, SCREEN_WIDTH, SCREEN_HEIGHT));


	float screenX, screenY;
	screenX = screenY = 0;
	float veclocity = 0;
	bool scroll = false;

	sf::RectangleShape r;
	r.setFillColor(sf::Color::Blue);
	r.setPosition(0, 1000);
	r.setSize(sf::Vector2f(200, 200));

	string now = "";
	string nowStudent = "";
	string nowLecturer = "";
	string nowAdmin = "";
	string nowView = "";

	while (window.isOpen())
	{
		sf::Event event;
		int st = 0;
		
		//HANDLE EVENT
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			//Handle events in program

			if (state == LOGIN) {
				st = login.handleEvent(event, Acc,account, course);
			}
			else 
			if (state == STUDENT || state == LECTURER || state == ADMIN) {
				if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::TextEntered)
				{
					if (!rect.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						now = screenControl.handleEvent(event, now, Acc,nowAdmin,nowStudent);
					}
				}
				if ( event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
				{
					if (rect.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
						//cout << "yes" << endl;
						scroll = true;
						//cout << nowView << scroll << endl;
					}
					else {
						scroll = false;
						nowView = "stop";
					}
				}
				if (scroll && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
					nowView = "down";
				}

				if (scroll && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
					nowView = "up";
				}

				if (scroll && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down) {
					nowView = "stop";
				}

				if (scroll && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up) {
					nowView = "stop";
				}
				if (state == STUDENT) {
					if (scroll == false && (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::TextEntered)) {
						nowStudent = menuStudent.handleEvent(event,nowStudent);
					}
				}
				if (state == LECTURER) {
					if (scroll == false && (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::TextEntered)) {
						nowLecturer = menuLecturer.handleEvent(event, nowLecturer, Acc, accountGraphic);
					}
					
				}
				if (state == ADMIN) {
					if (scroll == false && (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::TextEntered))
					{
						nowAdmin = menuAdmin.handleEvent(event,nowAdmin,Acc,accountGraphic, course,courseGraphic,studentGraphic);
					}
				}
			}
			//cout << event.mouseButton.x << " " << event.mouseButton.y << endl;
		}

		//LOGIC

		if (state == LOGIN) {
			if (st == 1)
			{
				state = ADMIN;
				menuAdmin.initGraphics(Class);
				now = "anywhere";
				nowView = "";
				screenControl.updateAccount(account);
				screenControl.initGraphic();
			}
			if (st == 2)
			{
				state = STUDENT;
				menuStudent.initGraphics();
				now = "anywhere";
				nowView = "";
				screenControl.updateAccount(account);
				screenControl.initGraphic();
			}
			if (st == 3)
			{
				state = LECTURER;
				menuLecturer.initGraphics();
				now = "anywhere";
				nowView = "";
				screenControl.updateAccount(account); 
				screenControl.initGraphic();
			}
			if (st == -1)
				window.close();
		}
		else
		if (state == STUDENT || state == LECTURER || state == ADMIN) {

			//Control the window
			if (now == "logout") {
				state = LOGIN;
				login.initData();
				login.initGraphic();
				st = 0;
			}
			if (nowView == "up")
			{
				veclocity = -5.0;

			}
			if (nowView == "down") {
				veclocity = 5.0;

			}
			if (nowView == "stop") {
				veclocity = 0;
			}
			rect.move(0, veclocity);
			if (rect.getPosition().y < 0) rect.setPosition(1772, 0);
			screenY = -(SCREEN_HEIGHT / 3 ) + rect.getPosition().y + 53;
			if (screenX < 0) screenX = 0;
			if (screenY < 0) screenY = 0;

			view.reset(sf::FloatRect(screenX, screenY, SCREEN_WIDTH, SCREEN_HEIGHT ));
			//
			if (state == STUDENT) {
				cout << nowStudent << endl;
				menuStudent.logic(time,account, nowStudent,course,attendanceList,scoreBoard,courseGraphic,scoreGraphic,attendanceGraphic);
				//cout << now << endl;
			}
			else 
			if (state == LECTURER) {
				cout << nowLecturer << endl;
			}
			else 
			if (state == ADMIN) {
				cout << nowAdmin << endl;
				menuAdmin.logic(nowAdmin,time, Class, Acc, course,scoreBoard,attendanceList,accountGraphic,courseGraphic,studentGraphic,scoreGraphic, attendanceGraphic);
			}
		}
		

		//RENDER WINDOW
		window.clear();

		switch (state)
		{
		case LOGIN:
			login.render(window);
			break;
		case STUDENT:
			window.setView(view);
			screenControl.render(window, now);
			window.draw(rect);
			//window.draw(r);
			menuStudent.render(window,nowStudent,courseGraphic,scoreGraphic,attendanceGraphic);
			break;
		case LECTURER:
			window.setView(view);
			screenControl.render(window,now);
			window.draw(rect);
			menuLecturer.render(window,nowLecturer,Acc,accountGraphic);
			break;
		case ADMIN:
			window.setView(view);
			screenControl.render(window,now);
			window.draw(rect);
			
			menuAdmin.render(window,nowAdmin,Acc,Class,accountGraphic,courseGraphic,studentGraphic,scoreGraphic, attendanceGraphic);
			break;
		}

		window.display();
	}
	
	Acc.saveAccount();
	Class.save();
	course.saveCourse();
	saveAttendance(attendanceList);
	saveScoreBoard(scoreBoard);
	return 0;
}