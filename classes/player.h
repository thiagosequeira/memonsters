//
// Created by Thiago on 23/10/2021.
//

#ifndef PROYECTO_INFOII_PLAYER_H
#define PROYECTO_INFOII_PLAYER_H

#include "SFML/Graphics.hpp"

class Player {
    float acc;
    sf::Sprite sp;
public:
    Player(int x, int y, const sf::Texture &tx);
    void dibujar(sf::RenderWindow &w);

    void arriba();

    void abajo();

    void derecha();

    void izquierda();
    sf::Sprite getSprite();


};

#endif //PROYECTO_INFOII_PLAYER_H
