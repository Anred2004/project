// Game.cpp
#include "Game.h"
#include "Ball.h"
#include "Floor.h"
Game::Game()
{   // Создание мяча и ракеток и игроков
    m_objects.push_back(new Ball());
    m_objects.push_back(new Floor(100.f, 510.f));
    m_objects.push_back(new Floor(100.f, 60.f));
    static_cast<Floor*>(m_objects[1]) -> setPlayer(1); // мы приводим указатель на базовый класс к указателю на производный класс 
    static_cast<Floor*>(m_objects[2]) -> setPlayer(2); // Floor, чтобы вызвать функцию setPlayer, которая определена только для класса Floor.
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
void Game::draw(sf::RenderWindow& window)
{
    // Отрисовка объектов
    for (GameObject* object : m_objects)
    {
        object->draw(window);
    }
}
