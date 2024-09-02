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
#include "map.hpp"
#include "Bomb.hpp"
#include "entidades.hpp"

enum ID{
	vazio =0,
	player,
	projeteis,
	inimigo,
	plataformas
};

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

    Bomba() {
        texturaBomba[0].loadFromFile("bombC.png", sf::IntRect(0, 0, 32, 96));
        texturaBomba[1].loadFromFile("bombC.png", sf::IntRect(32, 0, 64, 96));
        texturaBomba[2].loadFromFile("bombC.png", sf::IntRect(64, 0, 96, 96));
        spriteBomba.setTexture(texturaBomba[textura_corrente]);
    }

    void update() {
        f++;
        if (f >= 10) {
            f = 0;
            textura_corrente = (textura_corrente + 1) % 3;
            spriteBomba.setTexture(texturaBomba[textura_corrente]);
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(spriteBomba);
    }
};


/*
class entidade{
protected:
	ID id;

public:
	entidade(math::coordenada<float> position = math::coordenada(0.f, 0.f),math::coordenada<float> tamnaho = math::coordenada(0.f, 0.f), ID id = vazio);

	~entidade();

	void setaPosicao(math::coordenada pos);

	math::coordenada pegaPosicao() const;

	ID getId() const;


};

*/

#endif /* ENTIDADES_HPP_ */
