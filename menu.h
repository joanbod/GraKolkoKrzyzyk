#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>

using namespace std;
class Sprites
{
public:
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;
	bool isButton;
	//Tworzy sprite
	bool setUpSprite(string);

	Sprites(string, float, float,bool);
	virtual ~Sprites();


	//void Starting_Menu();
	//void how_to_play();
};

class Texts
{
public:
	wstring line;
	sf::Font font;
	sf::Text text;
	sf::Vector2f position;
	//Tworzy tekst
	Texts(wstring,string,int,float,float);
	virtual ~Texts();

	bool setUpText(string);
};