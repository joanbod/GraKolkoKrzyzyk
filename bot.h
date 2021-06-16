#pragma once
#include<iostream>
#include <SFML/Window.hpp>
#include "menu.h"
#include"board.h"
#include <SFML/Graphics.hpp>
#include<random>

using namespace std;
using namespace sf;


class Bot
{
public:
	virtual bool czy_pole_puste(int i) = 0;
	virtual int sprawdz_czy_wygram() = 0;
	virtual int sprawdz_czy_zablokuje() = 0;
	virtual void dodaj_losowo_wartosc() = 0;
	virtual int dodaj_losowo_wartosc_optymalniej() = 0;
	virtual void wykonaj_ruch() = 0;

	friend int losowa_liczba(int a,int b);
};

class Easy :public Bot
{
	Board* plansza;

public:
	Easy(Board&);
	virtual ~Easy();

	bool czy_pole_puste(int i);
	void dodaj_losowo_wartosc();
	

	
};

class Medium :public Bot
{
	Board* plansza;
	
public:
	Medium(Board&);
	virtual ~Medium();

	bool czy_pole_puste(int i);
	int sprawdz_czy_wygram();
	int dodaj_losowo_wartosc_optymalniej();

	void wykonaj_ruch();
	
};

class Advanced :public Bot
{
	Board* plansza;
	

public:
	Advanced(Board&);
	virtual ~Advanced();

	bool czy_pole_puste(int i);
	int sprawdz_czy_wygram();
	int sprawdz_czy_zablokuje();
	int dodaj_losowo_wartosc_optymalniej();
	
	void wykonaj_ruch();
};
