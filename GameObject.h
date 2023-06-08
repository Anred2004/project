// GameObject.h базовый класс
#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class GameObject
{
public:
   
    virtual void update(const std::vector<GameObject*>& objects) = 0;
    virtual void draw(sf::RenderTarget& target) const = 0;
    virtual GameObject::~GameObject() {}
};
