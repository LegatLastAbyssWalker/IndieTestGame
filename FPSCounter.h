#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H

#include "SFML/Graphics.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/System/Time.hpp"
#include "SFML/System/Clock.hpp"

#include <iostream>
#include <sstream>

class FPSCounter {
	public:
		FPSCounter();
		~FPSCounter();


		void renderTo(sf::RenderWindow& window);
		void update();


	private:
		sf::Font gameFont;
		sf::Text framerateCounter;

		std::ostringstream ssFPS;

		sf::Clock fpsClock;
		sf::Time fpsTime;
};

#endif