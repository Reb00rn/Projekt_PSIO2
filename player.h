#pragma once



#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include"animation.h"
#include"collider.h"

class Player
{
public:
    Player(sf::Texture*texture, sf::Vector2u image_count_,float switchTime_,float speed_);
   ~Player();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow &window);//not needed

    sf::Vector2f GetPosition() {return body_.getPosition();}

    Collider GetCollider() { return Collider(body_);}

private:
    sf::RectangleShape body_;
    Animation animation_;
    unsigned int row_;
    float speed_;
    bool FaceRight_;
};
