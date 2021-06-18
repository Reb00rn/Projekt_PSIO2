#include <iostream>


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include"animation.h"
#include"player.h"
#include"platform.h"
#include"collider.h"



int main()
{



    sf::RenderWindow window(sf::VideoMode(1200,800), "My window");


    //Załadowanie textury


    sf::Texture PlayerTexture;
    PlayerTexture.loadFromFile("miner1.png");


    Player player(&PlayerTexture,sf::Vector2u(9,1),0.1f,100.0f);//(liczba animacji.x,y),czas delta

    Platform platform1(nullptr,sf::Vector2f(400.0f,200.0f), sf::Vector2f(500.0f,200.0f));
    Platform platform2(nullptr,sf::Vector2f(400.0f,200.0f), sf::Vector2f(500.0f,0.0f));


    float deltaTime = 0.0f;
    sf::Clock clock;




//window.setFramerateLimit(6);


    // run the program as long as the window is open
    while (window.isOpen())
    {
    deltaTime  = clock.restart().asSeconds();


 //EVENTS-------------------------------------------------------------
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
}

        // draw everything here...

        player.Update(deltaTime);

        //najpierw deklarować kolizje

//        platform1.GetCollider().CheckCollision(player.GetCollider(),0.0f);
//        platform2.GetCollider().CheckCollision(player.GetCollider(),1.0f);


        window.clear(sf::Color(150,150,150));
        player.Draw(window);
        platform1.Draw(window);
        platform2.Draw(window);
        window.display();
        // end the current frame


}
    return 0;
}
