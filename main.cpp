#include<iostream>
#include <SFML/Window.hpp>
#include "menu.h"
#include"board.h"
#include<vector>
#include <SFML/Graphics.hpp>



using namespace std;


int main()
{

	GameMenu game1(800,650,"Okno gry");
	game1.setUpMenu();

	system("pause");
	return 0;
}
