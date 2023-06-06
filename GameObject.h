#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class GameObject
{
public:
   
    virtual void update(const std::vector<std::unique_ptr<GameObject>>& objects) = 0;
    virtual void draw(sf::RenderTarget& target) const = 0;

    virtual ~GameObject() = default;
};
