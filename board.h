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
	void wstaw(int x,int y,int kto);   // 1-kolko    2-krzyzyk
	~board();

private:
	RenderWindow* window;
	int rozmiar;
	RectangleShape* tab;
	int* tab_score;

};




