// main.cpp 
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Logger.h"
#include "Game.h"
using namespace pp;
int main()
{

    Logger logger;
    try {
        // Создание окна
        sf::RenderWindow window(sf::VideoMode(800, 600), "Window with Texture");
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("fon.png"))
        {
            std::cout << "error";
        }
        sf::Sprite backgroundSprite(backgroundTexture);
        // Создание объекта игры
        std::unique_ptr<Game> game(new Game());
        // Основной цикл программы
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }
            window.clear();
            window.draw(backgroundSprite);
            // Обновление игры
            game->update();
            // Отрисовка игры
            game->draw(window);
            window.display();
        }
    }
    catch (const std::exception& ex)
    {
        // Логирование исключения
        logger.logError(ex.what());
        throw;
    }

    return EXIT_SUCCESS;
}
