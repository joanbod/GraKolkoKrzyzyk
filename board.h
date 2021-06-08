#pragma once
#include<iostream>
#include <SFML/Window.hpp>
#include "menu.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class board
{
public:
	board(RenderWindow* window, int rozmiar);
	void rysuj();
	~board();

private:
	RenderWindow* window;
	int rozmiar;
	RectangleShape* tab;
	
};




