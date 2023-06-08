// Floor.cpp
#include "Floor.h"

Floor::Floor(float x, float y): m_shape(sf::Vector2f(100.f, 30.f)), m_speed(200.f)
{
    m_shape.setFillColor(sf::Color::Blue);
    m_shape.setPosition(x, y);
}
void Floor::update(const std::vector<GameObject*>& objects)
{
    // Обновление позиции ракетки
    float dt = 1.f / 500.f;
    
    if (m_player == 1) 
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            m_shape.move(-m_speed * dt, 0.f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            m_shape.move(m_speed * dt, 0.f);
        }
    }

    if (m_player == 2) 
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            m_shape.move(-m_speed * dt, 0.f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            m_shape.move(m_speed * dt, 0.f);
        }
    }
    // Проверка выхода ракетки за границы окна
    if (m_shape.getPosition().x < 0.f) 
    {
        m_shape.setPosition(0.f, m_shape.getPosition().y);
    }
    if (m_shape.getPosition().x + m_shape.getSize().x > 800.f) {
        m_shape.setPosition(800.f - m_shape.getSize().x, m_shape.getPosition().y);
    }
}
void Floor::draw(sf::RenderWindow& window) const
{
    window.draw(m_shape);
}
sf::RectangleShape& Floor::getShape()
{
    return m_shape;
}
