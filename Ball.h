#pragma once

#include "GameObject.h"

class Ball : public GameObject
{
public:
    Ball();

    void update(const std::vector<std::unique_ptr<GameObject>>& objects) override;
    void draw(sf::RenderTarget& target) const override;
    // Ball specific drawing logic  
private:
    sf::CircleShape m_shape;
    sf::Vector2f m_rate;
};
