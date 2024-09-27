#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include "includes/math.hpp"
#include "entidades.hpp"

int main(){


	// Criação da janela
	sf::RenderWindow window{ sf::VideoMode(986,771), "King Kong" };
	window.setVerticalSyncEnabled(true);

	//Declaração de objetos das classes
	Fundo fundo;
	Bomba bomba;
	Personagem player;
	Princesa princesa;

	//Loop da janela
        while (window.isOpen())
        {
                sf::Event windowEvent;
                while (window.pollEvent(windowEvent))
                {
                        if (windowEvent.type == sf::Event::Closed)
                                window.close();
                }

     // Atualizações
           bomba.colisaoBomba(window);
           princesa.colisaoPrincesa(window);
           player.updatePlayer();
           player.mover();

           window.clear(sf::Color::White);

     //Desenhar
           window.draw(fundo.spriteFundo);
           window.draw(bomba.spriteBomba);
           window.draw(princesa.spritePrincesa);
           window.draw(player.spriteJogador);
           window.display();
        }
        return 0;
}
