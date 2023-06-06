#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class GameObject;

class Game
{
public:
    Game();
    void update();
    void draw(sf::RenderTarget& target);
private:
    std::vector<std::unique_ptr<GameObject>> m_objects;
};
