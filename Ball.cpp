// Ball.cpp
#include "Ball.h"
#include "Floor.h"

Ball::Ball() : m_shape(12.f), m_rate(5.f, -5.f) // переменные содержащие форму круга и его скорость по осям х и у
{

    m_shape.setFillColor(sf::Color::Red);
    float yOset = rand() % 100; // Случайный сдвиг от 0 до 99
    m_shape.setPosition(400.f, 240.f + yOset);
    m_shape.setOrigin(5, 5);

}
void Ball::update(const std::vector<GameObject*>& objects)
{
    // Обновление позиции мяча
    float dt = 1.f / 80.f; //переменная, которая представляет время, прошедшее с последнего кадра.
    m_shape.move(m_rate * dt);

    for (GameObject* object : objects)
    {
        Floor* floor = dynamic_cast<Floor*>(object); //приводим object к указателю типа Floor, создается указатель floor
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
    if (m_shape.getPosition().x + 1.5*m_shape.getRadius() > 800.f)
    {
        m_rate.x = -m_rate.x;
    }
    if (m_shape.getPosition().y == 590.f || m_shape.getPosition().y == 0.f)
    {
        m_rate.x = 0.f;
        m_rate.y = 0.f;

        // Создаем окно с надписью "Game Over"
        sf::RenderWindow gameOverWindow(sf::VideoMode(800, 600), "Game Over");
        sf::Font font;
        font.loadFromFile("arial.ttf"); 
        sf::Text gameOverText("Game Over!!!", font);
        gameOverText.setCharacterSize(60);
        gameOverText.setPosition(230, 250);
        gameOverText.setFillColor(sf::Color::Red);

        while (gameOverWindow.isOpen()) {
            sf::Event event;
            while (gameOverWindow.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    gameOverWindow.close();
                }
            }

            gameOverWindow.clear(sf::Color::Black);
            gameOverWindow.draw(gameOverText);
            gameOverWindow.display();
        }
    }


}

void Ball::draw(sf::RenderWindow& window) const
{
    window.draw(m_shape);
}
