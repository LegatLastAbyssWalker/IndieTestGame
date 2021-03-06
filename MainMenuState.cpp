#include "MainMenuState.h"

#include "State.h"
#include "StateMachine.h"

#include "TutorialLevelState.h"

#include <iostream>

MainMenuState::MainMenuState(StateMachine& machine, sf::RenderWindow& window, bool replace)
	:State{ machine, window, replace } {
	
		//Buttons
		this->quitGameButton	  = new Button(window.getSize().x / 2, window.getSize().y / 2 + 40, 150, 50, 20, arialFont, "Quit Game",
			sf::Color(128, 128, 128), sf::Color(192, 192, 192), sf::Color(0, 0, 128), sf::Color(255, 255, 255));

		this->tutorialLevelButton = new Button(window.getSize().x / 2, window.getSize().y / 2 - 40, 150, 50, 20, arialFont, "Start Tutorial!",
			sf::Color(128, 128, 128), sf::Color(192, 192, 192), sf::Color(0, 0, 128), sf::Color(255, 255, 255));


		//Text
		this->titleText = new Text(window.getSize().x / 2, window.getSize().y / 4, 40, arialFont, "Indie Game Dev!", sf::Color(0, 139, 139));
}

MainMenuState::~MainMenuState() {
	delete this->quitGameButton;
	delete this->tutorialLevelButton;
	delete this->titleText;
}

void MainMenuState::pause() {
	//

}

void MainMenuState::resume() {
	//
	
}


void MainMenuState::update() {
	sf::Vector2<int> mousePos = sf::Mouse::getPosition(window);

	//Updating mouse position for button functionality
	this->quitGameButton->update(sf::Vector2<float>(mousePos));
	this->tutorialLevelButton->update(sf::Vector2<float>(mousePos));

	//Event loop
	while (window.pollEvent(sfEvent)) {

		switch (sfEvent.type) {
			case sf::Event::Closed:
				machine.quit();
				break;

			case sf::Event::MouseButtonPressed:
				if (this->quitGameButton->isPressed() == true)		{ machine.quit(); }
				if (this->tutorialLevelButton->isPressed() == true) { machine.run(machine.buildState<TutorialLevelState>(machine, window, true)); }
			 

				break;

			case sf::Event::MouseMoved:
				//

				//sf::Vector2<int> mousePos = sf::Mouse::getPosition(window);
				//std::cout << "X: " << mousePos.x << ", " << "Y: " << mousePos.y << '\n';
				break;
		}
	}




	fpsCounter.update();
	/*-----------------------------------------------------------------------------------------*/
}


void MainMenuState::render() {
	window.clear();

	//Render items
	this->fpsCounter.renderTo(window);
	this->quitGameButton->renderTo(window);
	this->tutorialLevelButton->renderTo(window);
	this->titleText->renderTo(window);


	window.display();
}
