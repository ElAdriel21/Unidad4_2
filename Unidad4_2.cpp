#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "2");

    sf::Texture redPointTexture;
    redPointTexture.loadFromFile("rcircle.png");
    sf::Sprite puntoRojo1(redPointTexture);
    sf::Sprite puntoRojo2(redPointTexture);
    sf::Sprite puntoRojo3(redPointTexture);
    sf::Sprite puntoRojo4(redPointTexture);

    sf::Vector2f topLeft(0, 0);
    sf::Vector2f topRight(680, 0);
    sf::Vector2f bottomLeft(0, 480);
    sf::Vector2f bottomRight(680, 480);

    bool isDragging = false;
    sf::Vector2f offset;
    int puntoRojoPresionado = 0;

    while (window.isOpen()) {
        sf::Event event;

        puntoRojo1.setPosition(topLeft);
        puntoRojo2.setPosition(topRight);
        puntoRojo3.setPosition(bottomLeft);
        puntoRojo4.setPosition(bottomRight);

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (puntoRojo1.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    puntoRojoPresionado = 1;
                    isDragging = true;
                    offset = puntoRojo1.getPosition() - sf::Vector2f(mousePos);
                }
                else if (puntoRojo2.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    puntoRojoPresionado = 2;
                    isDragging = true;
                    offset = puntoRojo2.getPosition() - sf::Vector2f(mousePos);
                }
                else if (puntoRojo3.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    puntoRojoPresionado = 3;
                    isDragging = true;
                    offset = puntoRojo3.getPosition() - sf::Vector2f(mousePos);
                }
                else if (puntoRojo4.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    puntoRojoPresionado = 4;
                    isDragging = true;
                    offset = puntoRojo4.getPosition() - sf::Vector2f(mousePos);
                }
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                isDragging = false;
            }
        }

        if (isDragging) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            switch (puntoRojoPresionado)
            {
            case 1:
                puntoRojo1.setPosition(sf::Vector2f(mousePos) + offset);
                break;
            case 2:
                puntoRojo2.setPosition(sf::Vector2f(mousePos) + offset);
                break;
            case 3:
                puntoRojo3.setPosition(sf::Vector2f(mousePos) + offset);
                break;
            case 4:
                puntoRojo4.setPosition(sf::Vector2f(mousePos) + offset);
                break;
            }
        }

        window.clear();
        window.draw(puntoRojo1);
        window.draw(puntoRojo2);
        window.draw(puntoRojo3);
        window.draw(puntoRojo4);
        window.display();
    }

    return 0;
}