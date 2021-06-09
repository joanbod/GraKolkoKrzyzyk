#pragma once
#include<iostream>
#include <SFML/Window.hpp>
#include "menu.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Board
{
public:
	Board(RenderWindow* window, int rozmiar);
	void rysuj();
	/*Sprawdza czy ktoœ wygra³.*/
	bool checkIfWin();
	void wstaw(int x, int y, int kto);   // 1-kolko    2-krzyzyk
	~Board();

private:
	RenderWindow* window;
	int rozmiar;
	RectangleShape* tab;
	int* tab_score;

};





