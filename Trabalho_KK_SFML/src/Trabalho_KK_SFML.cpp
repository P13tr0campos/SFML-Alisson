#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include "includes/math.hpp"

int main()
{
        sf::RenderWindow window{ sf::VideoMode(986,771), "The game!" };
        sf::Texture t;
        t.loadFromFile("Background/Fundo.PNG");
        sf::Sprite s(t);
        while (window.isOpen())
        {
                sf::Event windowEvent;
                while (window.pollEvent(windowEvent))
                {
                        if (windowEvent.type == sf::Event::Closed)
                                window.close();
                }
                window.clear(sf::Color::White);
                window.draw(s);
                window.display();
        }
        return 0;
}
