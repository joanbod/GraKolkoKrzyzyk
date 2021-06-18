#pragma once
#include<iostream>
#include <SFML/Window.hpp>
#include "menu.h"
#include"board.h"
#include <SFML/Graphics.hpp>
#include<random>

using namespace std;
using namespace sf;

//Deklaracja zaprzyjaznionej klasy
class Board;

//Klasa odpowiedzialna za bota przeciwnika
class Bot
{
	//Pobiera wartosc wektora z indeksu 1, ktory odpowiada trybowi gry (latwy-1,sredni-2,trudny-3)
	int tryb_gry;
	//Wskaznik do planszy, aby moc korzystac z tablicy inforamcjami na temat pol
	Board* plansza;
	
public:
	Bot(Board&, int);
	virtual ~Bot();
	
	//Pobiera wartosc z tab_score z obiektu Board o indeksie i. Sprawdza jego zawartosc 0-puste 1,2-zapelnione
	bool czy_pole_puste(int i) ;
	//Sprawdza wykorzystujac metode checkIfWin z obiektu Board czy po dodaniu okreslonej wartosci moze wygrac jesli nie to w zaleznosci od trybu dodaje losowo lub sprawdza czy moze zablokowac
	int sprawdz_czy_wygram() ;
	//Sprawdza wykorzystujac metode checkIfWin z obiektu Board czy po dodaniu okreslonej wartosci moze zablokowac ruch przeciwnika do wygranej jesli nie przechodzi do dodaj losowo
	int sprawdz_czy_zablokuje();
	//Dodaje w losowe miejsce na planszy element
	int dodaj_losowo_wartosc() ;
	//Sprawdza czy jest dodawany pierwszy obiekt i stara sie wypelnic rogi w celu zwiekszenia szans wygranej
	int dodaj_losowo_wartosc_optymalniej() ;
	//W zaleznosci od trybu uruchamia okreslone metody
	void wykonaj_ruch();
	
	//Zaprzyjazniona funkcja zwracajaca losowe wartosci z zakresu od a do b
	friend int losowa_liczba(int a,int b);
};
