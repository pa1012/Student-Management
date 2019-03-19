#pragma once

#include"Base.h"
#include"LoadData.h"
#include"Account.h"

using namespace std;

class MenuOfStudent{
private:
	sf::Texture checkInTexture, scoreTexture, scheduleTexture;
	sf::Sprite checkIn, score, schedule;
	
public:
	void initGraphics();
	void render(sf::RenderWindow &window);
	string handleEvent(sf::Event event);
	
};
