#ifndef ENTIDADES_HPP_
#define ENTIDADES_HPP_

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include "includes/math.hpp"

class Fundo {
public:
    sf::Texture texturaFundo;
    sf::Sprite spriteFundo;

//---------------------------------------FUNDO------------------------------------------------------
    Fundo() {
        if (!texturaFundo.loadFromFile("Fundo.png")) {
            std::cout << "Erro ao carregar a textura do arquivo" << std::endl;

        }
        spriteFundo.setTexture(texturaFundo);
        spriteFundo.setPosition(0, 0);
    }
    void draw(sf::RenderWindow& window) {
           window.draw(spriteFundo);
      }
};
//-----------------------------------------------BOMBA---------------------------------------------
class Bomba {
public:
    sf::Texture texturaBomba[3];
    sf::Sprite spriteBomba;
    int textura_corrente = 0;
    int f = 0;
    // Define a velocidade de movimento
      float speed = 200.0f;
      bool movingRight = true;
      sf::Clock movementClock;

    Bomba() {
        texturaBomba[0].loadFromFile("bombC.png", sf::IntRect(0, 0, 32, 96));
        texturaBomba[1].loadFromFile("bombC.png", sf::IntRect(32, 0, 64, 96));
        texturaBomba[2].loadFromFile("bombC.png", sf::IntRect(64, 0, 96, 96));
        spriteBomba.setTexture(texturaBomba[textura_corrente]);

        spriteBomba.setPosition(130, 130);
    }


    void update() {
            f++;
            if (f >= 10) {
                f = 0;
                // Muda para a próxima textura da animação
                textura_corrente = (textura_corrente + 1) % 3;
                spriteBomba.setTexture(texturaBomba[textura_corrente]);
            }
        }


int movimentacao(sf::RenderWindow& window){
    sf::Time deltaTime = movementClock.restart();

    if (movingRight) {
        spriteBomba.move(speed * deltaTime.asSeconds(), 0);
        if (spriteBomba.getPosition().x + spriteBomba.getGlobalBounds().width >= window.getSize().x) {
            movingRight = false;
        }
    } else {
        spriteBomba.move(-speed * deltaTime.asSeconds(), 0);
        if (spriteBomba.getPosition().x <= 0) {
            movingRight = true;
        }
    }

    return 0;
}

    void draw(sf::RenderWindow& window) {
        window.draw(spriteBomba);
    }
};

//--------------------------------------- JOGADOR----------------------------------------------------

class Personagem{
   public:
   	sf::Texture player[3];
   	sf::Sprite playersfml;
   	    int textura_corrente = 0;
   	    int f = 0;

   	    Personagem() {
   	        player[0].loadFromFile("player-sfml-TP_Andando.png", sf::IntRect(0, 0, 16, 48));
   	        player[1].loadFromFile("player-sfml-TP_Andando.png", sf::IntRect(16, 0, 32, 48));
   	        player[2].loadFromFile("player-sfml-TP_Andando.png", sf::IntRect(32, 0, 48, 48));
   	        playersfml.setTexture(player[textura_corrente]);
   	        playersfml.setPosition(130,630);
   	        //Aumenta o tamanho do player
   	        playersfml.setScale(3,3);
   	    }

   	 void updatePlayer() {
   		            f++;
   		            if (f >= 10) {
   		                f = 0;
   		                textura_corrente = (textura_corrente + 1) % 3;
   		                playersfml.setTexture(player[textura_corrente]);
   		            }
   		        }

   	 void mover (){
   		 sf::Vector2f position = playersfml.getPosition();

   		 if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
   			 playersfml.setPosition(position + sf::Vector2f(1 ,0));
   		 }
   		 if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
   		   			 playersfml.setPosition(position + sf::Vector2f(-1 ,0));

   		 }
   		 if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
   		   			 playersfml.setPosition(position + sf::Vector2f(0, -1));
   		  }
   		 if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
   		   		   	 playersfml.setPosition(position + sf::Vector2f(0, 1));
   		  }
   	 }
 };

#endif /* ENTIDADES_HPP_ */
