#include<iostream>
#include <SFML/Graphics.hpp>
#include "menu.h"

using namespace std;


Sprites::Sprites(string textureName, float x, float y,bool button)
{
	//Ustawienie pozycji sprite.
	if (!setUpSprite(textureName))
		return;
	position = sf::Vector2f(x, y);
	sprite.setPosition(position);
	isButton = button;

}

Sprites::~Sprites()
{

}

bool Sprites::setUpSprite(string textureName)
{
	if (!texture.loadFromFile(textureName))
		return 0;
	texture.setSmooth(true);	//Wyg³adza brzegi
	sprite.setTexture(texture);
	return true;

}

Texts::Texts(wstring line,string fontfilename,int charactersize, float x, float y)
{
	if (!setUpText(fontfilename))
		return;

	text.setString(line);
	text.setCharacterSize(charactersize);
	text.setFillColor(sf::Color::White);
	position = sf::Vector2f(x, y);
	text.setPosition(position);
}

Texts::~Texts()
{

}

bool Texts::setUpText(string fontfilename)
{
	if (!font.loadFromFile(fontfilename))
		return 0;
	text.setFont(font);
	return true;
}
