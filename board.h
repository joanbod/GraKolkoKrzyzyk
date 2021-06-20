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
	void rysuj(int punkty_gracz_1,int punkty_gracz_2); // rysuje plansze razem z punktacja
	void rysuj_x_o(); //rysuje kolka i krzyzyki w odpowiedniej pozycji na podstawie tablicy tab_score

	/*Sprawdza czy ktoœ wygra³.*/
	int checkIfWin(); //sprawdza czy w tablicy tab_score nie znajduja sie 3 lub 4 takie same cyfry na ukos w poziomie lub w wierszach
	bool wstaw(int x, int y, int kto);   // 1-kolko    2-krzyzyk
	void newGame(); // wype³nia tablice tab_score zerami co skutkuje resetem gry

	virtual ~Board();

	friend class Bot;

private:
	RenderWindow* window;
	int rozmiar;
	RectangleShape* tab; // tablica obiektow ktore odpowiadaja za wyglad planszy
	int* tab_score;  //tablica przechowujaca postawione kolka(1) / krzyzyki(2)

	int x_poczatek;    //poczatek od ktorego zaczyna sie plansza
	int y_poczatek;   

};





