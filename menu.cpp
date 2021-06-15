#include<iostream>
#include <SFML/Graphics.hpp>
#include"board.h"
#include "menu.h"

using namespace std;
using namespace sf;

GameMenu::GameMenu(float x, float y, string windowName)
{
	this->x = x;
	this->y = y;
	window = new RenderWindow(VideoMode(x, y, 32), windowName);
	mod = 0;
	choiceMode = 1;
	i_amount = 1;
	gracz = 1;
	vecChoices = { 0 };
}



void GameMenu::setUpMenu()
{
	
	//Strona g³ówna gry
	Texts o_x = Texts(L"O_X", "fonts/PressStart2P-Regular.ttf", 60, 315, 100);	//O_X na ka¿dej stronie
	Texts startButton = Texts(L"Start", "fonts/PressStart2P-Regular.ttf", 42, 300, 240);
	Texts instructionButton = Texts(L"Instrukcja", "fonts/PressStart2P-Regular.ttf", 42, 220, 330);

	//Strona instrukcji
	wstring instruction = L"ZASADY GRY\nGracze obejmuj¹ pola na przemian d¹¿¹c do objêcia trzech pól w jednej linii,\nprzy jednoczesnym uniemo¿liwieniu tego samego przeciwnikowi.\nPole mo¿e byæ objête przez jednego gracza i\nnie zmienia swego w³aœciciela przez ca³y przebieg gry.\n\nJAK GRAÆ?\n Po pierwsze wybierz planszê:\n\n3x3\n5x5\n\n nastêpnie wybierz swojego przeciwnika:\n\n-£atwy\n-Œredni\n-Zaawansowany\n-Ze znajomym\n\nKoñcowo wybierz iloœæ rozgrywek wybieraj¹c odpowiedni¹ liczbê.\n\nI najwa¿niejsze pamiêtaj o dobrej zabawie.";
	Texts instructionText = Texts(instruction, "fonts/Quicksand-VariableFont_wght.ttf", 16, 100, 160);

	//Strony wybory trybu gry
	Texts chooseGameBoard = Texts(L"PLANSZA", "fonts/PressStart2P-Regular.ttf", 40, 310, 150);
	Texts threeXthree = Texts(L"3 x 3", "fonts/PressStart2P-Regular.ttf", 32, 360, 250);
	Texts fiveXfive = Texts(L"5 x 5", "fonts/PressStart2P-Regular.ttf", 32, 360, 310);

	Texts chooseGameMode = Texts(L"TRYB GRY", "fonts/PressStart2P-Regular.ttf", 40, 280, 150);
	Texts easy = Texts(L"³atwy", "fonts/PressStart2P-Regular.ttf", 32, 340, 220);
	Texts medium = Texts(L"œredni", "fonts/PressStart2P-Regular.ttf", 32, 335, 270);
	Texts advanced = Texts(L"trudny", "fonts/PressStart2P-Regular.ttf", 32, 335, 320);
	Texts withAFriend = Texts(L"Ze znajomym", "fonts/PressStart2P-Regular.ttf", 32, 280, 370);

	Texts chooseAmountOfGames = Texts(L"LICZBA ROZGRYWEK", "fonts/PressStart2P-Regular.ttf", 40, 80, 150);
	wstring w_amount = to_wstring(i_amount);
	Texts amountOfGames = Texts(w_amount, "fonts/PressStart2P-Regular.ttf", 38, 405, 295);

	//Przycisk powiêkszenia i pomniejszenia wartoœci
	Sprites amountButtonsUp = Sprites("buttonAmountUp.png", 375, 220, true/*rozmiar 50X100*/);
	Sprites amountButtonsDown = Sprites("buttonAmountDown.png", 375, 345, true/*rozmiar 50X100*/);

	//Kó³ko i krzy¿yk do gry
	Texts o_sign = Texts(L"O", "fonts/PressStart2P-Regular.ttf", 40, 310, 150);
	Texts x_sign = Texts(L"x", "fonts/PressStart2P-Regular.ttf", 40, 310, 150);

	//Przycisk powrotu do poprzedniej strony
	Texts goBackButton = Texts(L"BACK", "fonts/PressStart2P-Regular.ttf", 14, 740, 20);

	//Tryby gry
	enum class GameBoard { threexthree = 1, fivexfive = 2 };
	enum class GameMode { easy = 1, medium = 2, advanced = 3, withAFriend = 4 };

	window->setVerticalSyncEnabled(true);

	//Stworzenie plansz
	/*Board* plansza_5 = new Board(&window, 5);		
	Board* plansza_3 = new Board(&window, 3);*/

	//G³ówna pêtla gry
	while (window->isOpen())
	{
		//TODO: To do usuniêcia, bo tylko sprawdza
		for (int i = 0; i < vecChoices.size(); i++)
		{
			cout << vecChoices[i] << endl;
		}
		
		Event e;

		while (window->pollEvent(e))
		{

			//obsluga zdarzenia
			if (e.type == sf::Event::Closed || (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape))
			{
				window->close();
			}

			//Powrót do strony g³ównej
			if (!(mod == 0) && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 800 && e.mouseButton.x > 740 && e.mouseButton.y > 0 && e.mouseButton.y < 40)
			{

				if ((mod == 2 && choiceMode == 1) || mod == 1 || mod == 3)
				{
					mod=0;
					choiceMode = 1;
					vecChoices.clear();
				}
				else if ((mod == 2 && choiceMode == 2)||(mod == 2 && choiceMode==3))
				{
					mod=2;
					choiceMode--;
					vecChoices.pop_back();

				}
				
			}



			if (mod == 0 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 640 && e.mouseButton.x > 210 && e.mouseButton.y > 320 && e.mouseButton.y < 364)
			{
				//PrzejÅ›cie do instrukcji.
				mod = 1;
			}
			else if (mod == 0 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 510 && e.mouseButton.x > 290 && e.mouseButton.y < 300 && e.mouseButton.y > 230)
			{
				//PrzejÅ›cie do wyboru trybu gry.
				mod = 2;
			}

			//wybór trybu gr 3x3 albo 5x5
			else if (mod == 2 && choiceMode == 1 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 560 && e.mouseButton.x > 360 && e.mouseButton.y > 248 && e.mouseButton.y < 285)
			{
				vecChoices.push_back(static_cast<int>(GameBoard::threexthree));
				choiceMode = 2;
			}

			else if (mod == 2 && choiceMode == 1 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 550 && e.mouseButton.x > 350 && e.mouseButton.y > 300 && e.mouseButton.y < 340)
			{
				vecChoices.push_back(static_cast<int>(GameBoard::fivexfive));
				choiceMode = 2;
			}
			//wybor poziomu trudnoœci lub czy z innym graczem 
			else if (mod == 2 && choiceMode == 2 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 500 && e.mouseButton.x > 330 && e.mouseButton.y < 255 && e.mouseButton.y > 215)
			{
				vecChoices.push_back(static_cast<int>(GameMode::easy));
				choiceMode = 3;
			}
			else if (mod == 2 && choiceMode == 2 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 530 && e.mouseButton.x > 330 && e.mouseButton.y < 360 && e.mouseButton.y > 310)
			{
				vecChoices.push_back(static_cast<int>(GameMode::advanced));
				choiceMode = 3;
			}
			else if (mod == 2 && choiceMode == 2 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 530 && e.mouseButton.x > 330 && e.mouseButton.y < 310 && e.mouseButton.y > 270)
			{
				vecChoices.push_back(static_cast<int>(GameMode::medium));
				choiceMode = 3;
			}
			else if (mod == 2 && choiceMode == 2 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 635 && e.mouseButton.x > 270 && e.mouseButton.y < 405 && e.mouseButton.y > 360)
			{
				vecChoices.push_back(static_cast<int>(GameMode::withAFriend));
				choiceMode = 3;
			}
			else if (i_amount != 15 && mod == 2 && choiceMode == 3 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 445 && e.mouseButton.x > 395 && e.mouseButton.y < 275 && e.mouseButton.y > 225)
			{
				i_amount++;

			}
			else if (i_amount != 1 && mod == 2 && choiceMode == 3 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 455 && e.mouseButton.x > 395 && e.mouseButton.y < 395 && e.mouseButton.y > 335)
			{
				i_amount--;

			}
			else if (mod == 2 && choiceMode == 3 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 515 && e.mouseButton.x > 320 && e.mouseButton.y < 500 && e.mouseButton.y > 460)
			{
				//tutaj chhyba inputem jakims bedzie trzeba to zrobic
				vecChoices.push_back(i_amount);
				mod = 3;
			}

			/*else if (mod == 3 && vecChoices[0] == 1 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left) {
				plansza_3->wstaw(e.mouseButton.x, e.mouseButton.y, gracz);
			}
			else if (mod == 3 && vecChoices[0] == 2 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left) {
				plansza_5->wstaw(e.mouseButton.x, e.mouseButton.y, gracz);

			}*/



			//TODO: przycisk powrotu, moÂ¿e maÂ³e menu po najechaniu siÃª wysietla? przyciski wyboru gry bo rozpierdala to powoli.
		}



		window->clear(sf::Color(0, 0, 0));
		//TODO: Do osobnej funkjci to strzeliæ by trzeba by³o.
		//Ustawia Start napis dla róznych ekranów.
		if (mod == 2)
		{
			startButton.text.setScale(sf::Vector2f(0.85f, 0.85f));
			startButton.text.setPosition(sf::Vector2f(340, 460));
		}
		else
		{
			startButton.text.setScale(sf::Vector2f(1.15f, 1.15f));
			startButton.text.setPosition(sf::Vector2f(300, 240));
		}

		switch (mod)
		{
			//GÂ³Ã³wne menu gry
		case 0:
			window->draw(o_x.text);
			window->draw(startButton.text);
			window->draw(instructionButton.text);
			break;
			//Instrukcja gry
		case 1:
			window->draw(o_x.text);
			window->draw(instructionText.text);
			window->draw(goBackButton.text);

			break;
			//WybÃ³r trybu gry
		case 2:
		{
			switch (choiceMode)
			{
			case 1:
				window->draw(chooseGameBoard.text);
				window->draw(threeXthree.text);
				window->draw(fiveXfive.text);
				window->draw(goBackButton.text);
				break;
			case 2:
				window->draw(chooseGameMode.text);
				window->draw(easy.text);
				window->draw(medium.text);
				window->draw(advanced.text);
				window->draw(withAFriend.text);


				window->draw(goBackButton.text);

				break;
			case 3:
				window->draw(chooseAmountOfGames.text);

				w_amount = to_wstring(i_amount);
				amountOfGames.text.setString(w_amount);

				//Ustawienie liczby rozgrywek w oknie w zale¿noœci od iloœci cyfr.
				if (i_amount > 9)
					amountOfGames.text.setPosition(sf::Vector2f(390, 295));
				else
					amountOfGames.text.setPosition(sf::Vector2f(405, 295));
					
				window->draw(amountOfGames.text);
				
				if (i_amount == 1)
					window->draw(amountButtonsUp.sprite);
				else if (i_amount == 15)
					window->draw(amountButtonsDown.sprite);
				else
				{
					window->draw(amountButtonsUp.sprite);
					window->draw(amountButtonsDown.sprite);
				}

				window->draw(startButton.text);
				window->draw(goBackButton.text);

				break;

			}
		}
		break;
		//Gra
		case 3:

			/*if (vecChoices[0] == 1) {
				plansza_3->rysuj();
			}
			if (vecChoices[0] == 2) {
				plansza_5->rysuj();
			}*/
			window->draw(goBackButton.text);
			break;
		default:
			break;
		}



		window->display();
	}


}

GameMenu::~GameMenu()
{
	delete window;
}
Sprites::Sprites(string textureName, float x, float y,bool button)
{
	//Ustawienie pozycji sprite.
	if (!setUpSprite(textureName))
		return;
	position = sf::Vector2f(x, y);
	sprite.setPosition(position);
	isButton = button;

}

Sprites::~Sprites()
{

}

bool Sprites::setUpSprite(string textureName)
{
	if (!texture.loadFromFile(textureName))
		return 0;
	texture.setSmooth(true);	//Wyg³adza brzegi
	sprite.setTexture(texture);
	return true;

}

Texts::Texts(wstring line,string fontfilename,int charactersize, float x, float y)
{
	if (!setUpText(fontfilename))
		return;

	text.setString(line);
	text.setCharacterSize(charactersize);
	text.setFillColor(sf::Color::White);
	position = sf::Vector2f(x, y);
	text.setPosition(position);
}

Texts::~Texts()
{

}

bool Texts::setUpText(string fontfilename)
{
	if (!font.loadFromFile(fontfilename))
		return 0;
	text.setFont(font);
	return true;
}
