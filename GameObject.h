// GameObject.h базовый класс
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class GameObject
{
public:

    virtual void update(const std::vector<GameObject*>& objects) = 0;
    virtual void draw(sf::RenderWindow& window) const = 0;//позволяет рисовать графику на отдельной области экрана или текстуры.
    virtual GameObject::~GameObject() {}
};
