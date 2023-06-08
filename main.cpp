// main.cpp
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Logger.h"
#include "Game.h"

int main()
{
    Logger logger;
    try {
        // Создание окна
        sf::RenderWindow window(sf::VideoMode(800, 600), "Game");
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
            // Обновление игры
            game->update();
            // Отрисовка игры
            window.clear(sf::Color::White);
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
