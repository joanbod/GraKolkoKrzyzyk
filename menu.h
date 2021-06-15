#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

class GameMenu
{
	//Okno aplikacji
	RenderWindow* window;
	//Wymiary okna
	float x;
	float y;
	//Zmienne odpowiedzialne za poruszanie siê po grze
	int mod;
	int choiceMode;
	int i_amount;
	//TODO:Do czego to?
	int gracz;
	//Wektory odpowiedzialne za zapisanie wyborów gracza
	vector<int> vecChoices;

public:
	GameMenu(float=800,float=650,string="Okno aplikacji");
	virtual ~GameMenu();

	void setUpMenu();

};

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