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
	void rysuj_x_o();

	/*Sprawdza czy ktoœ wygra³.*/
	int checkIfWin();
	void wstaw(int x, int y, int kto);   // 1-kolko    2-krzyzyk
	void newGame();

	~Board();

private:
	RenderWindow* window;
	int rozmiar;
	RectangleShape* tab;
	int* tab_score;

	int x_poczatek;    //poczatek od ktorego zaczyna sie plansza
	int y_poczatek;

};





