#include "player.h"

Player::Player(sf::Texture*texture, sf::Vector2u image_count_,float switchTime_,float speed_):animation_(texture, image_count_,switchTime_)
{
 this-> speed_ = speed_;
    row_ = 0;
    FaceRight_ = true;

        body_.setSize(sf::Vector2f(50,100.0));
        body_.setOrigin(body_.getSize()/2.0f);
        body_.setPosition(500,400);
        body_.setTexture(texture);
}
Player::~Player()
{

}
void Player::Update(float deltaTime)
{
    sf::Vector2f movement(0.0f,0.0f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        movement.x -= speed_*deltaTime;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        movement.x += speed_*deltaTime;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        movement.y -= speed_*deltaTime;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        movement.y += speed_*deltaTime;
    }

    if(movement.x == 0.0f)
    {
        row_ =0;
        deltaTime = 0;
    }
    else
    {
        row_ = 0;

        if(movement.x>0.0f)
        {
            FaceRight_ = true;
        }
        else
        {
            FaceRight_ = false;
        }
    }
    animation_.Update(row_,deltaTime,FaceRight_);
    body_.setTextureRect(animation_.uvRect);
    body_.move(movement);

}
void Player::Draw(sf::RenderWindow& window)
{
    window.draw(body_);
}

