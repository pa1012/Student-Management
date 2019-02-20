#include <SFML/Graphics.hpp>
#include"ArrayOfClass.h"
#include"LoadData.h"
#include"Course.h"

enum AppState {
	LOGIN, STUDENT, LECTURER, ADMIN
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(1800, 800), "Student Management");
	
	ArrOfAccount Acc;
	Acc.loadAccountStudent();
	ArrayOfClass Class;
	Class.load(Acc);
	Acc.saveAccount();

	AppState state = LOGIN;

	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}

		
		window.clear();
		
		window.display();
	}
	
	system("pause");
	return 0;
}