#include <iostream>
#include <SFML/Graphics.hpp>

#include "classes/player.h"


int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Memonsters");
    sf::CircleShape shape(100.f);
    sf::Texture texture;
    sf::Sprite image;

    if (!texture.loadFromFile("assets/map.png")) {
        std::cout << "Error al cargar textura, verifique la ruta";
        return EXIT_FAILURE;
    }
    image.setTexture(texture);
    image.setPosition((800 - 680) / 2, 0);

    window.setFramerateLimit(30);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition((800 - 200) / 2, 300);

    // Load a sprite to display
    sf::Texture tx_player;
    if (!tx_player.loadFromFile("assets/player.png"))
        return EXIT_FAILURE;

    Player *player;
    sf::Sprite contrincante;
    contrincante.setTexture(tx_player);
    contrincante.setPosition(400, 400);
    contrincante.setColor(sf::Color::Red);

        // Start the game loop
        while (window.isOpen()) {
            // Process events
            sf::Event event;
            while (window.pollEvent(event)) {
                // Close window: exit
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                player->arriba();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                player->abajo();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                player->doblar(0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                player->doblar(1);
            }
        // Update world parameters

        // player.move(3,4);

        // Draw all elements
        window.clear();
        window.draw(shape);
        window.draw(image);
        window.display();
    }
    return 0;
}