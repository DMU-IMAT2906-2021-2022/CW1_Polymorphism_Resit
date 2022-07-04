#include<iostream>
#include<string>
#include <SFML/Graphics.hpp>

//Function for drawing a SFML circle
sf::CircleShape drawCircle(float f_radius) {
	sf::CircleShape shape(f_radius);
	return shape;
}



int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500, 32), "Polymorphic Lab Book Coursework"); //Draw an SFML window.
	sf::CircleShape shape = drawCircle(50.f); //Draw and SFML circle.
	shape.setFillColor(sf::Color::Green); //Make cicle green.


	const float f_FPS = 60.0f; //The desired FPS. (The number of updates each second).
	bool b_redraw = true;      //Do I redraw everything on the screen?


	window.setFramerateLimit(f_FPS);
	sf::Clock clock;
	shape.setOrigin(10.0f, 10.0f); //Position origin of the circle in the centre.
	shape.setPosition(0, 150.0f); //Set the intial position of the circle. 


	while (window.isOpen())
	{
		//Wait until 1/60th of a second has passed, then update everything.
		if (clock.getElapsedTime().asSeconds() >= 1.0f / f_FPS)
		{
			b_redraw = true; //We're ready to redraw everything
			shape.move(1.0f, 0);
			clock.restart();
		}
		//Check if the window is open or closed.
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Draw stuff if ready
		if (b_redraw)
		{
			b_redraw = false;
			window.clear();
			window.draw(shape);
			window.display();
		}
	}

	return 0;
}
