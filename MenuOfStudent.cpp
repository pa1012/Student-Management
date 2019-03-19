#include"MenuStudent.h"

void MenuOfStudent::initGraphics() {
	loadTexture("checkIn.png", checkInTexture);
	loadTexture("schedule.png", scheduleTexture);
	loadTexture("score.png", scoreTexture);
	

	checkIn.setTexture(checkInTexture);
	checkIn.setPosition(40, 117);

	schedule.setTexture(scheduleTexture);
	schedule.setPosition(40, 224);

	score.setTexture(scoreTexture);
	score.setPosition(40, 318);

	
}

void MenuOfStudent::render(sf::RenderWindow &window) {
	window.draw(checkIn);
	window.draw(schedule);
	window.draw(score);
	
}

string MenuOfStudent::handleEvent(sf::Event event) {
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		if (checkIn.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
			return "check-in";
		}
		if (schedule.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
		{
			return "schedule";
		}
		if (score.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
			return "score";
		}
	}
	return "anywhere";
}

