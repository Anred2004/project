#include "Game.h"
#include "Ball.h"
#include "Floor.h"

Game::Game()
{
    // Создание мяча и ракеток
    m_objects.push_back(std::make_unique<Ball>());
    m_objects.push_back(std::make_unique<Floor>(100.f, 500.f));
    m_objects.push_back(std::make_unique<Floor>(600.f, 500.f));
}

void Game::update()
{
    // Обновление объектов
    for (auto& object : m_objects) 
    {
        object->update(m_objects);
    }
}

void Game::draw(sf::RenderTarget& target)
{
    // Отрисовка объектов
    for (const auto& object : m_objects) 
    {
        object->draw(target);
    }
}
