// Game.cpp
#include "Game.h"
#include "Ball.h"
#include "Floor.h"
Game::Game()
{   // Создание мяча и ракеток и игроков
    m_objects.push_back(new Ball());
    m_objects.push_back(new Floor(100.f, 500.f));
    m_objects.push_back(new Floor(100.f, 100.f));
    static_cast<Floor*>(m_objects[1])->setPlayer(1);
    static_cast<Floor*>(m_objects[2])->setPlayer(2);
}
Game::~Game() {
    // Удаляем все объекты
    for (GameObject* object : m_objects) 
    {
        delete object;
    }
}
void Game::update()
{
    // Обновление объектов
    for (GameObject* object : m_objects) 
    {
        object->update(m_objects);
    }
}
void Game::draw(sf::RenderTarget& target)
{
    // Отрисовка объектов
    for (GameObject* object : m_objects)
    {
        object->draw(target);
    }
}
