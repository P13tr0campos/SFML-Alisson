//============================================================================
// Name        : Trabalho_KK_SFML.cpp
// Author      : PietroCampos
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.hpp>

 #include<SFML/Graphics.hpp>

//Código principal.
 int main()
 {
 sf::RenderWindow window(
 sf::VideoMode(160,192),
 "HelloWorld");
 sf ::CircleShape shape (6);

 // Abertura da janela.

 while(window.isOpen())
 {
 sf::Event event;
 while(
 window.pollEvent(event))
 if(event.type==
 sf::Event::Closed)
 window.close();
 window.clear();
 window.draw(shape);
 window.display();
 }
 return 0;
 }
