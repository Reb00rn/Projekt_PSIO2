#include "collider.h"

Collider::Collider(sf::RectangleShape& body_):
body_(body_)
{

}


Collider::~Collider()
{

}


bool Collider::CheckCollision(Collider& other,float push)
{
    sf::Vector2f otherPosition = other.GetPosition();//pobiera pozycje obiektu
    sf::Vector2f otherHalfSize = other.GetHalfSize();//pobiera promień od środka

    sf::Vector2f thisPosition = GetPosition();
    sf::Vector2f thisHalfSize = GetHalfSize();

    float deltaX = otherPosition.x - thisPosition.x;//odległość między obiektami x
    float deltaY = otherPosition.y - thisPosition.y;//odległość miedzy obiektami y

    float intersectX = abs(deltaX) - (otherHalfSize.x+ thisHalfSize.x);//czy nachodzą na siebie w x
    float intersectY = abs(deltaY) - (otherHalfSize.y+ thisHalfSize.y);// czy nachodzą na siebie w y

    if(intersectX< 0.0f&&intersectY<0.0f)
    {
        push = std::min(std::max(push,0.0f),1.0f);//clamping
        if(intersectX>intersectY)
        {
            if(deltaX>0.0f)
            {
                Move(intersectX*(1.0f - push), 0.0f);
                other.Move(-intersectX* push, 0.0f);
            }
            else
            {
                Move(intersectX*(1.0f - push), 0.0f);
                other.Move(intersectX* push, 0.0f);
            }
            if(deltaY>0.0f)
            {
                Move(0.0f,intersectY*(1.0f - push));
                other.Move(0.0f,-intersectY* push);
            }
            else
            {
                Move( 0.0f,intersectY*(1.0f - push));
                other.Move(0.0f,intersectY* push);
            }

        }
        return true;
    }
    return false;
}
