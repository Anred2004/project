// Floor.h
#pragma once
#include "GameObject.h"

class Floor : public GameObject
{
public:
    Floor(float x, float y);

    void update(const std::vector<GameObject*>& objects) override;
    void draw(sf::RenderTarget& target) const override;
    void setPlayer(int player) 
    { 
        m_player = player; 
    }
    sf::RectangleShape& getShape();

private:
    sf::RectangleShape m_shape;
    float m_speed;
    int m_player;
    
};
