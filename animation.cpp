#include "animation.h"

Animation::Animation(sf::Texture*texture, sf::Vector2u image_count_,float switchTime_)
{
    this->image_count_ = image_count_;
    this->switchTime_ = switchTime_;
    totalTime_ = 0.0;
    current_image_.x = 0.0;


    uvRect.width = texture->getSize().x/float(image_count_.x);//szerokość tekstury
    uvRect.height = texture->getSize().y/float(image_count_.y);//wysokość tekstury
}
Animation::~Animation()
{

}

void Animation::Update(int row,float deltaTime,bool FaceRight)
{
    current_image_.y = row;
    totalTime_+= deltaTime;

    if(totalTime_>= switchTime_)//płynniejszy ruch animacji
    {
        totalTime_ -=switchTime_;
        current_image_.x++;

        if(current_image_.x>=image_count_.x)// w razie gdy rząd się kończy przechodzi do kolejnego
        {
            current_image_.x = 0;
        }

    }

    uvRect.top = current_image_.y * uvRect.height;

    if(FaceRight)
    {
            uvRect.left = current_image_.x * uvRect.width;
            uvRect.width = abs(uvRect.width);
    }
    else
    {
        uvRect.left = (current_image_.x + 1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }
}
