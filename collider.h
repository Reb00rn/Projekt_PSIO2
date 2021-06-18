#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Collider
{
public:
    Collider(sf::RectangleShape& body_);
    ~Collider();


    void Move(float dx, float dy) {body_.move(dx,dy);}

    bool CheckCollision(Collider& other,float push);
    sf::Vector2f GetPosition() {return body_.getPosition();}
    sf::Vector2f GetHalfSize() {return body_.getSize()/ 2.0f;}

private:
    sf::RectangleShape& body_;
};

