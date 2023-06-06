#include "Ball.h"
#include "Floor.h"

Ball::Ball() : m_shape(10.f), m_rate(200.f, -200.f)
{
    m_shape.setFillColor(sf::Color::Red);
    m_shape.setPosition(400.f, 300.f);
}

void Ball::update(const std::vector<std::unique_ptr<GameObject>>& objects)
{
    // Обновление позиции мяча
    float dt = 1.f / 60.f;
    m_shape.move(m_rate * dt);

    //111// Проверка столкновения с ракетками
    for (const auto& object : objects) {
        auto floor = dynamic_cast<Floor*>(object.get());
        if (floor) {
            if (m_shape.getGlobalBounds().intersects(floor->getShape().getGlobalBounds())) {
                m_rate.y = -m_rate.y;
            }
        }
    }

    // Проверка столкновения с границами окна
    if (m_shape.getPosition().x < 0.f || m_shape.getPosition().x > 800.f) {
        m_rate.x = -m_rate.x;
    }
    if (m_shape.getPosition().y < 0.f) {
        m_rate.y = -m_rate.y;
    }
}

void Ball::draw(sf::RenderTarget& target) const
{
    target.draw(m_shape);
}
