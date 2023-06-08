// Ball.h
#pragma once
#include "GameObject.h"

class Ball : public GameObject
{
public:
    Ball();
    void update(const std::vector<GameObject*>& objects) override;
    void draw(sf::RenderTarget& target) const override;
    
private:
    sf::CircleShape m_shape;
    sf::Vector2f m_rate;
    bool m_gameOver;

};
