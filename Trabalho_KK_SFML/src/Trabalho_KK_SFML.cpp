#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "includes/math.hpp"


int main(){
	// Criação da janela
	sf::RenderWindow window{ sf::VideoMode(986,771), "King Kong" };

//------------------------------------FUNDO-------------------------------------------------------------//

	// Carregar textura do Fundo a partir de um arquivo
        sf::Texture texturaFundo;
        if(!texturaFundo.loadFromFile("Fundo.png")){
        	 std::cout << "Erro ao carregar a textura do arquivo" << std::endl;
        	 return -1;
        }

        // Criar um sprite do Fundo para desenhar a textura
        sf::Sprite SpriteFundo(texturaFundo);
        SpriteFundo.setPosition(0,0);

//------------------------------------BOMBA-------------------------------------------------------------//

        sf::Texture texturaBomba;
           if (!texturaBomba.loadFromFile("bomb1.png"))
           {
               std::cerr << "Erro ao carregar a textura do arquivo" << std::endl;
               return -1;
           }
           else{
        	   sf::Sprite spriteBomba;
        	   spriteBomba.setTexture(texturaBomba);


           }

           // Criar um sprite e associá-lo à textura
           sf::Sprite spriteBomba;
           spriteBomba.setTexture(texturaBomba);

           spriteBomba.setPosition(180, 180);


//Loop da janela
        while (window.isOpen())
        {
                sf::Event windowEvent;
                while (window.pollEvent(windowEvent))
                {
                        if (windowEvent.type == sf::Event::Closed)
                                window.close();
                }



                window.clear(sf::Color::White);

//Desenhar
                window.draw(SpriteFundo);
                 window.draw(spriteBomba);
                window.display();
        }
        return 0;
}
