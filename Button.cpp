#include "Button.h"

Button::Button(float x, float y, float width, float height, unsigned int characterSize, std::string fontLocation, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor, sf::Color textColor) {
	this->buttonState = BTN_IDLE;

	this->shape.setPosition(sf::Vector2<float>(x, y));
	this->shape.setSize(sf::Vector2<float>(width, height));
	this->shape.setOrigin(this->shape.getGlobalBounds().width / 2, this->shape.getGlobalBounds().height / 2);

	buttonFont.loadFromFile(fontLocation);
	this->text.setFont(buttonFont);
	this->text.setOrigin(this->text.getPosition().x / 2, this->text.getPosition().y / 2);
	this->text.setString(text);
	this->text.setCharacterSize(characterSize);
	this->text.setFillColor(textColor);
	/*this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width - this->text.getGlobalBounds().width / 2.f),
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height - this->text.getGlobalBounds().height / 2.f)
	);*/

	//Need help here VVVV
	this->text.setPosition(
		this->shape.getGlobalBounds().width + this->shape.getOrigin().x,
		this->shape.getGlobalBounds().height + this->shape.getOrigin().y
	);

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->shape.setFillColor(this->idleColor);


}

Button::~Button() {

}


const bool Button::isPressed() const {
	if (this->buttonState == BTN_ACTIVE) {
		return true;
	}

	return false;
}

void Button::update(const sf::Vector2<float> mousePos) {
	//Idle
	this->buttonState = BTN_IDLE;

	//Hover
	if (this->shape.getGlobalBounds().contains(mousePos)) {
		this->buttonState = BTN_HOVER;

		//Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->buttonState = BTN_ACTIVE;
		}
	}

	switch (this->buttonState) {
		case BTN_IDLE:
			this->shape.setFillColor(this->idleColor);
			break;

		case BTN_HOVER:
			this->shape.setFillColor(this->hoverColor);
			break;

		case BTN_ACTIVE:
			this->shape.setFillColor(this->activeColor);
			break;

		default:
			this->shape.setFillColor(sf::Color::Red);
			break;
	}
}

void Button::renderTo(sf::RenderWindow& window) {
	window.draw(this->shape);
	window.draw(this->text);
}
