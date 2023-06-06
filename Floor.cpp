Floor::Floor(float x, float y): m_shape(sf::Vector2f(100.f, 20.f)), m_speed(400.f)
{
    m_shape.setFillColor(sf::Color::Blue);
    m_shape.setPosition(x, y);
}

void Floor::update(const std::vector<std::unique_ptr<GameObject>>& objects)
{
    // Обновление позиции ракетки
    float dt = 1.f / 60.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        m_shape.move(-m_speed * dt, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        m_shape.move(m_speed * dt, 0.f);
    }


    // Проверка выхода ракетки за границы окна
    if (m_shape.getPosition().x < 0.f) {
        m_shape.setPosition(0.f, m_shape.getPosition().y);
    }
    if (m_shape.getPosition().x + m_shape.getSize().x > 800.f) {
        m_shape.setPosition(800.f - m_shape.getSize().x, m_shape.getPosition().y);
    }
}

void Floor::draw(sf::RenderTarget& target) const
{
    target.draw(m_shape);
}

sf::RectangleShape& Floor::getShape()
{
    return m_shape;
}
