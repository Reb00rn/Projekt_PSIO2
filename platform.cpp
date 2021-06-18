#include "platform.h"



Platform::Platform(sf::Texture*texture, sf::Vector2f size,sf::Vector2f position)
{
    body_.setSize(size);
    body_.setTexture(texture);
    body_.setPosition(position);
    body_.setOrigin(size/2.0f);

}
Platform::~Platform()
{

}


void Platform::Draw(sf::RenderWindow& window)
{
    window.draw(body_);
}
