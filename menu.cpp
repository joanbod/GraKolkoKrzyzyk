#include<iostream>
#include<locale.h>
#include "menu.h"

using namespace std;

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::Starting_Menu()
{
	//setlocale(LC_CTYPE, "Polish");
	cout << "Grafika koloko krzyzyk" << endl;
	cout << "Start" << endl;
	cout << "Jak grac?" << endl;
}

void Menu::how_to_play()
{
	
	setlocale(LC_CTYPE, "Polish");		//Dodanie poolskich znak�w.
	cout << "Pierwszy nast�puje wyb�r planszy. Nast�pnie wybierasz pomi�dzy dwoma trybami: gra z drugim graczem lub komputerem z okre�lonym poziomem zaawansowania. Kolejno nast�puje wyb�r ilo�ci rozgrywek oraz elementu, kt�rym b�dziesz gra�." << endl;
	cout << "Zasady gry" << endl;
	cout << "Gracze stawiaj� na przemian k�ko i krzy�yk d���c do zaj�cia trzech lub pi�ciu p�l w jednej linii zgodnie z wybranym trybem gry. Wygrywa ten z graczy, kt�remu jako pierwszemu uda u�o�y� si� trzy znaki w jednej linii.";
	//TODO: mo�na doda� jakie� grafiki??
}