// Floor.h
#pragma once
#include "GameObject.h"

class Floor : public GameObject
{
public:
    Floor(float x, float y);

    void update(const std::vector<GameObject*>& objects) override;
    void draw(sf::RenderWindow& window) const override;
    void setPlayer(int player)
    {
        m_player = player;
    }
    sf::RectangleShape& getShape();//возвращает ссылку на прямоугольник

private:
    sf::RectangleShape m_shape;// прямоугольник
    float m_speed;
    int m_player;
    sf::Texture floors;

};
