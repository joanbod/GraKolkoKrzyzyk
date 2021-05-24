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
	
	setlocale(LC_CTYPE, "Polish");		//Dodanie poolskich znaków.
	cout << "Pierwszy nastêpuje wybór planszy. Nastêpnie wybierasz pomiêdzy dwoma trybami: gra z drugim graczem lub komputerem z okreœlonym poziomem zaawansowania. Kolejno nastêpuje wybór iloœci rozgrywek oraz elementu, którym bêdziesz graæ." << endl;
	cout << "Zasady gry" << endl;
	cout << "Gracze stawiaj¹ na przemian kó³ko i krzy¿yk d¹¿¹c do zajêcia trzech lub piêciu pól w jednej linii zgodnie z wybranym trybem gry. Wygrywa ten z graczy, któremu jako pierwszemu uda u³o¿yæ siê trzy znaki w jednej linii.";
	//TODO: mo¿na dodaæ jakieœ grafiki??
}