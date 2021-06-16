#pragma once
#include<iostream>
#include <SFML/Window.hpp>
#include "menu.h"
#include"board.h"
#include <SFML/Graphics.hpp>
#include<random>

using namespace std;
using namespace sf;

class Board;

class Bot
{
	int tryb_gry;//pobiera wartość wektora z indesku 1 (1-3)
	Board* plansza;

public:
	Bot(Board&, int);
	virtual ~Bot();

	bool czy_pole_puste(int i) ;
	int sprawdz_czy_wygram() ;
	int sprawdz_czy_zablokuje();
	void dodaj_losowo_wartosc() ;
	int dodaj_losowo_wartosc_optymalniej() ;
	void wykonaj_ruch();

	friend int losowa_liczba(int a,int b);
};
