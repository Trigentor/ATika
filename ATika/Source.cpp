#include <SFML\Graphics.hpp>
#include <iostream>
#include "string.h"
#include <cmath>
#include <fstream>


using namespace std;
using namespace sf;
class Play
{
public:
	float x, y, w, h, dy, dx, speed = 0;
	int dir = 0;
	String path;
	Image image;
	Texture texture;
	Sprite sprite;
	Play(String P, int X, int Y, int W, int H)
	{
		path = P;
		w = W; h = H;
		image.loadFromFile("D:/Go/" + path);
		image.createMaskFromColor(Color(Color::White));
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;
		sprite.setTextureRect(IntRect(0, 0, w, h));

	}
	void update(float time)
	{
		switch (dir)
		{
		case 0:dx = speed; dy = 0; break;
		case 1:dx = -speed; dy = 0; break;
		case 2:dx = 0; dy = speed; break;
		case 3:dx = 0; dy = -speed; break;
		}

		x += dx * time;
		y += dy * time;

		speed = 0;
		sprite.setPosition(x, y);
	}
};
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
	
	Play B("Back.png", 250, 250, 1800, 1000);
	Play P("One.png", 0, 0, 51.00, 91.00);
	

	//int xcor = 0, ycor = 0;
	float CurrentFrame = 0;
	Clock clock;
	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		Event event;
		while (window.pollEvent(event))
		{
			
			//Начало Ивентов 
			//Правильно Лево+ клавиш A
			if ((Keyboard::isKeyPressed(Keyboard::A))|| (Keyboard::isKeyPressed(Keyboard::Left))){
				P.dir = 1; P.speed = 5;
				CurrentFrame += 0.09 * time;
				if (CurrentFrame > 3)CurrentFrame -= 3;
				P.sprite.setTextureRect(IntRect(52 * int(CurrentFrame), 93, 51, 91));
				/*xcor = 2;
					P.sprite.move(xcor, 0);
				*/
				};
			//Правильно Право+ клавиш D
			if ((Keyboard::isKeyPressed(Keyboard::D)) || (Keyboard::isKeyPressed(Keyboard::Right))) {
				P.dir = 0; P.speed = 5;
				CurrentFrame += 0.09 * time;
				if (CurrentFrame > 3)CurrentFrame -= 3;
				P.sprite.setTextureRect(IntRect(52 * int(CurrentFrame), 0, 51, 91));
			};

			if ((Keyboard::isKeyPressed(Keyboard::W)) || (Keyboard::isKeyPressed(Keyboard::Up))) {
				P.dir = 3; P.speed = 5;
				CurrentFrame += 0.09 * time;
				if (CurrentFrame > 3)CurrentFrame -= 3;
				P.sprite.setTextureRect(IntRect(52 * int(CurrentFrame), 186, 51, 91));
			};
			if ((Keyboard::isKeyPressed(Keyboard::S)) || (Keyboard::isKeyPressed(Keyboard::Down))) {
				P.dir = 2; P.speed = 5;
				CurrentFrame += 0.09 * time;
				if (CurrentFrame > 3)CurrentFrame -= 3;
				P.sprite.setTextureRect(IntRect(52 * int(CurrentFrame), 279, 51, 91));
			};
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				P.path = "Two.png";
			}
				if (event.type == Event::Closed)
					window.close();
			};
			P.update(time);

			window.clear();
			window.draw(B.sprite);
			window.draw(P.sprite);
			window.display();
		}
	return 0;
}