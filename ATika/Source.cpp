#include <SFML\Graphics.hpp>
#include <iostream>
#include "string.h"
#include <cmath>
#include <fstream>


using namespace std;
using namespace sf;
int main()
{
	setlocale(LC_ALL, "ru");
	
	/*int a = 0;
	cout << "What do you want" << endl;
	cout << "1.average of numbers" << endl;
	cin >> a;
	a--;
	switch (a)
	{
	case 0:

		break;

	default:
		fclose;
		break;
	}
	*/

	//Пропуск числа
	/*int a = 0;
	cout << "Введите число:";
		cin >> a;
		for (int i=0; i < 9; i++)
	{
			if (i == a)	{continue;}
			cout << "Переменная i="<<i<<endl;
	}*/
	RenderWindow window(VideoMode(1800, 1000), "ATika", Style::Default);
	/*CircleShape shape(100.f);
	shape.setFillColor(Color::Yellow);
	*/
	class images
	{
	public:
		int x, y, w, h;
		string path;
		Image image;
		Texture texture;
		Sprite sprite;
		images(String P,int X, int Y, int W, int H)
		{
			path = P;
			w = W; h = H;
			image.loadFromFile("D:/Go/" + path);
			//image.createMaskFromColor(Color(Color::White));
			texture.loadFromImage(image);
			sprite.setTexture(texture);
			sprite.setTextureRect(IntRect(w, h, w, h));
		
		}
	};
	images B("Back.png", 250, 250, 1800, 1000);
	images P("One.png", 0, 0, 83, 106);
	

	int xcor = 0, ycor = 0;
	
		while (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{

				if (Keyboard::isKeyPressed(Keyboard::D))
				{
					xcor = 2;
					P.sprite.move(xcor, 0);
				};
				if (Keyboard::isKeyPressed(Keyboard::A))
				{
					xcor = -2;
					P.sprite.move(xcor, 0);
				};
				if (Keyboard::isKeyPressed(Keyboard::W))
				{
					ycor = -2;
					P.sprite.move(0, ycor);
					
				};
				if (Keyboard::isKeyPressed(Keyboard::S))
				{
					ycor = 2;
					P.sprite.move(0, ycor);
				};
				if (event.type == Event::Closed)
					window.close();
			};
			window.clear();
			window.draw(B.sprite);
			window.draw(P.sprite);
			window.display();
		}
	return 0;
}