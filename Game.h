// Game.h
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class GameObject;

class Game
{
public:
    Game();
    ~Game();
    void update();
    void draw(sf::RenderTarget& target);
 
private:
    std::vector<GameObject*> m_objects;
};
