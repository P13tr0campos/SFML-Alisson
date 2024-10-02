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

 const int h=25, l=33;
                    	sf::String tilemap[h] = {
                    	"                                 ",
                    	"                                 ",
                    	"                                 ",
                    	"   BBBBBBBBBBBBBBBBBBBBBBBBBBB   ",
                    	"   B           OOO           B   ",
                    	"  B            OOO            B  ",
                    	"  B OO                     OO B  ",
                    	"  B OO                     OO B  ",
                    	" B             OOO             B ",
                    	" B             OOO             B ",
                    	" B             OOO             B ",
                    	" BOO                         OOB ",
                    	" BOO                         OOB ",
                    	" B             OOO             B ",
                    	" B             OOO             B ",
                    	" B             OOO             B ",
                    	" BOO                         OOB ",
                    	" BOO                         OOB ",
                    	" B             OOO             B ",
                    	" BOO           OOO             B ",
                    	" BOO           OOO           OOB ",
                    	" BOO                         OOB ",
                    	" BOO                         OOB ",
                    	" BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB ",
                    	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
                    	};

int main(){


	// Criação da janela
	sf::RenderWindow window{ sf::VideoMode(990,750), "King Kong" };
	window.setVerticalSyncEnabled(true);

	//Declaração de objetos das classes
	Fundo fundo;
	Bomba bomba;
	Personagem player;
	Princesa princesa;
	FonteTexto tempo, fase;
    sf::Clock clock;
	bool temporizador = false; // Variável para controlar se o temporizador começou


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
           player.colisao(tilemap, h, l);
           sf::RectangleShape rectangle(sf::Vector2f(30, 30));

     //Desenhar
           window.clear(sf::Color::White);
           window.draw(fundo.spriteFundo);
           for (int i{}; i < h; ++i){
        	   for (int j{}; j < l; ++j){
                   if( tilemap[i][j] == 'B'){
                   rectangle.setFillColor(sf::Color::Transparent);
                   }
                   if( tilemap[i][j] == 'O'){
                   rectangle.setFillColor(sf::Color::Transparent);
                   }
                   if( tilemap[i][j] == ' '){
                   continue;
                   }
                   rectangle.setPosition( j * 30, i * 30);
                   window.draw(rectangle);
        	   	   }
            }
           window.draw(bomba.spriteBomba);
           window.draw(princesa.spritePrincesa);
           window.draw(player.spriteJogador);
           tempo.atualizaContador(window, temporizador);
           fase.fasePersonagem(window);
           window.display();
        }
}
