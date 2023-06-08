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
    void draw(sf::RenderWindow& window);
 
private:
    std::vector<GameObject*> m_objects;//вектор указателей на объекты класса GameObject.
};
