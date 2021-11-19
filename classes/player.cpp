//
// Created by Thiago on 23/10/2021.
//

#include "player.h"
#include <cmath>
#include <iostream>

using namespace std;

Player::Player(int x, int y, const sf::Texture &tx) {
    acc = 0;
    sp.setTexture(tx);
    sp.setPosition(x, y);
    sp.setOrigin(tx.getSize().x / 2, tx.getSize().y / 2);
    sp.setScale(1.f, 1.f);
}

void Player::dibujar(sf::RenderWindow &w) {
    w.draw(sp);
}

void Player::arriba() {
    acc = 5;
    sp.move(0,-1.f*acc);
}

void Player::abajo() {
    acc = 5;
    sp.move(0,1.f*acc);
}

void Player::derecha(){
    acc = 5;
    sp.move(1.f*acc, 0);
}

void Player::izquierda(){
    acc=5;
    sp.move(-1.f*acc,0);
}

sf::Sprite Player::getSprite(){
    return sp;
}