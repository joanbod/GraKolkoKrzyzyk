#pragma once
#include<iostream>
#include <SFML/Window.hpp>
#include "menu.h"
#include "bot.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Board 
{
public:
	Board(RenderWindow* window, int rozmiar);
	void rysuj(int punkty_gracz_1,int punkty_gracz_2);
	void rysuj_x_o();

	/*Sprawdza czy ktoœ wygra³.*/
	int checkIfWin();
	bool wstaw(int x, int y, int kto);   // 1-kolko    2-krzyzyk
	void newGame();

	virtual ~Board();

	friend class Bot;

private:
	RenderWindow* window;
	int rozmiar;
	RectangleShape* tab;
	int* tab_score;

	int x_poczatek;    //poczatek od ktorego zaczyna sie plansza
	int y_poczatek;

};





