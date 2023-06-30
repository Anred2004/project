// Ball.h
#pragma once
#include "GameObject.h"

class Ball : public GameObject
{
public:
    Ball();
    void update(const std::vector<GameObject*>& objects) override; // метод обновляет состояние объекта на основе переданного ему списка объектов
    void draw(sf::RenderWindow& window) const override; // метод отрисовки

private:
    sf::CircleShape m_shape; // переменная формы круга
    sf::Vector2f m_rate;//переменна содержит информацию о скорости и направлении движения обьекта
};
