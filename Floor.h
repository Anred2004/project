#pragma once

#include "GameObject.h"

class Floor : public GameObject
{
public:
    Floor(float x, float y);

    void update(const std::vector<std::unique_ptr<GameObject>>& objects) override;
    void draw(sf::RenderTarget& target) const override;

    sf::RectangleShape& getShape();

private:
    sf::RectangleShape m_shape;
    float m_speed;
};
