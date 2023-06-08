// Ball.cpp
#include "Ball.h"
#include "Floor.h"

Ball::Ball(): m_shape(10.f), m_rate(5.f, -5.f) // переменные содержащие форму круга и его скорость по осям х и у
{

    m_shape.setFillColor(sf::Color::Red);
    float yOset = rand() % 100; // Случайный сдвиг от 0 до 99
    m_shape.setPosition(400.f, 280.f+yOset);
    m_shape.setOrigin(5, 5);

}
void Ball::update(const std::vector<GameObject*>& objects)
{
    // Обновление позиции мяча
    float dt = 1.f / 80.f; //переменная, которая представляет время, прошедшее с последнего кадра.
    m_shape.move(m_rate * dt);

    for (GameObject* object : objects) 
    {
        Floor* floor = dynamic_cast<Floor*>(object); // приводим object к указателю типа Floor, создается указатель  floor
        if (floor) 
        {
            sf::FloatRect ballBounds = m_shape.getGlobalBounds(); //ballBounds границы шара, возвращает границы формы
            sf::FloatRect floorBounds = floor->getShape().getGlobalBounds(); //floorBounds границы дощечек
            if (ballBounds.left < floorBounds.left + floorBounds.width
                && ballBounds.left + ballBounds.width > floorBounds.left
                && ballBounds.top < floorBounds.top + floorBounds.height
                && ballBounds.top + ballBounds.height > floorBounds.top) {

                m_rate.y = -m_rate.y;

            }
        }
    }
    if (m_shape.getPosition().x < 0.f) 
    {
        m_rate.x = -m_rate.x;
    }
    if (m_shape.getPosition().x + m_shape.getRadius() > 800.f)
    {
        m_rate.x = -m_rate.x;
    }
   
}



void Ball::draw(sf::RenderWindow& window) const
{
    window.draw(m_shape);
}
