// Ball.cpp
#include "Ball.h"
#include "Floor.h"

Ball::Ball(): m_shape(10.f), m_rate(5.f, -5.f) // переменные содержащие форму круга и его скорость
{

    m_shape.setFillColor(sf::Color::Red);
    float yOset = rand() % 100; // Случайный сдвиг от 0 до 99
    m_shape.setPosition(400.f, 280.f+yOset);

}
void Ball::update(const std::vector<GameObject*>& objects)
{
    // Обновление позиции мяча
    float dt = 1.f / 60.f;
    m_shape.move(m_rate * dt);
    m_gameOver = false;

    for (GameObject* object : objects) 
    {
        Floor* floor = dynamic_cast<Floor*>(object);
        if (floor) 
        {
            sf::FloatRect ballBounds = m_shape.getGlobalBounds();
            sf::FloatRect floorBounds = floor->getShape().getGlobalBounds();
            if (ballBounds.left < floorBounds.left + floorBounds.width
                && ballBounds.left + ballBounds.width > floorBounds.left
                && ballBounds.top < floorBounds.top + floorBounds.height
                && ballBounds.top + ballBounds.height > floorBounds.top) {

                m_rate.y = -m_rate.y;
            }
        }
    }
    if (m_shape.getPosition().x < 0.f || m_shape.getPosition().x > 800.f) 
    {
        m_rate.x = -m_rate.x;
    }
   //ДОДЕЛАТЬ!
    if (m_shape.getPosition().y < 0.f || m_shape.getPosition().y > 600.f)
    {
       // Останавливаем скорость мяча       
      m_rate = {0.f, 0.f};          
      m_gameOver = true;

    }
}

void Ball::draw(sf::RenderTarget& target) const
{
    if (m_gameOver == false)
    {
        target.draw(m_shape);
    }
}
