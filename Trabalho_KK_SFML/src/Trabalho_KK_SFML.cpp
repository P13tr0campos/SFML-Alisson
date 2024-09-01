#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "includes/math.hpp"
#include "map.hpp"
#include "Bomb.hpp"

class Bomba {
public :
	int Xcount;
	int Ycount;
};


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


        Bomba b;
        sf::Texture texturaBomba;
           if (!texturaBomba.loadFromFile("bombC.png"))
           {
               std::cerr << "Erro ao carregar a textura do arquivo" << std::endl;
               return -1;
           }

        	   // Criar um sprite e associá-lo à textura
        	   sf::Sprite spriteBomba;
        	   spriteBomba.setTexture(texturaBomba);

        	   spriteBomba.setPosition(150, 130);

        	   b.Xcount = 1;
        	   b.Ycount = 0;

        	   spriteBomba.setTextureRect(sf::IntRect(b.Xcount * 32, b.Ycount  * 32, 32, 32));



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
