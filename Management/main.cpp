#include <SFML/Graphics.hpp>
//#include"ArrayOfClass.h"
#include"LoadData.h"
#include"Course.h"
#include"Login.h"

enum AppState {
	LOGIN, STUDENT, LECTURER, ADMIN, MENU
};

int main()
{
	ArrOfAccount Acc;
	Acc.loadAccount();
	ArrayOfClass Class;
	Class.load(Acc);
	Acc.saveAccount();

	AppState state = LOGIN;

	Login login;
	login.initGraphic();
	
	sf::RenderWindow window(sf::VideoMode(1800, 800), "Student Management");

	sf::RectangleShape rect;
	rect.setPosition(0, 0);
	rect.setSize(sf::Vector2f(100, 100));
	
	while (window.isOpen())
	{
		sf::Event event;
		int st = 0;

		//HANDLE EVENT
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			switch (state)
			{
			case LOGIN:
				//if (event.type == sf::Event::MouseButtonPressed) cout << 1 << endl;
				st = login.handleEvent(event,Acc);
				cout << st << endl;
				break;
			}
		}

		//LOGIC

		switch (state)
		{
		case LOGIN:
			if (st == 1)
				state = MENU;
			if (st == -1)
				window.close();
			break;
		case STUDENT:
			break;
		case LECTURER:
			break;
		case ADMIN:
			break;
		default:
			break;
		}
		
		//RENDER WINDOW
		window.clear();
		if (state == LOGIN) 
			login.render(window);
		//window.draw(rect);
		window.display();
	}
	
	return 0;
}