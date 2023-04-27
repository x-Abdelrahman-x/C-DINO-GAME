#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Animation.h"
#include <SFML/Network.hpp>
using namespace sf;

RenderWindow window(VideoMode(780,780),"SFML Works!");

int main()
{
    window.setFramerateLimit(60); // to not burn out your graphics card

    Texture t;
    t.loadFromFile("assets/WPP.png");

    Sprite x;
    x.setTexture(t);

    Texture L;
    L.loadFromFile("assets/PP.png");

    Sprite G;
    G.setTexture(L);

    Font font;
    font.loadFromFile("assets/zerovelo.ttf");

    Text text;
    text.setFont(font);
    text.setPosition(140.f, 10.f);
    text.setCharacterSize(60);
    text.setFillColor(Color::White);
    text.setString("DINO GAME");


    Music music;
    if (!music.openFromFile("assets/2018-11-27_-_Track_A.wav"))
    {
        std::cout << "error" << std::endl;
    }
    music.play();


    // vectors
    Vector2f circle1pos = Vector2f(60.f, 300.f);

    // shapes and properties
    CircleShape circle1(30.f);
    circle1.setFillColor(Color::Green);
    circle1.setPosition(circle1pos);

    float yvelocity = 3;
    float xvelocity = 4;

    float yvelocit = 2;
    float xvelocit = 3;

    Vector2f circle2pose = Vector2f(25.f, 300.f);

    // shapes and properties
    CircleShape circle2(25.f);
    circle2.setFillColor(Color::Red);
    circle2.setPosition(circle2pose);
   
    Vector2f circle3pose = Vector2f(50.f, 300.f);

    // shapes and properties
    CircleShape circle3(35.f);
    circle3.setFillColor(Color::Blue);
    circle3.setPosition(circle3pose);
    float yvelocitY3 = 3;
    float xvelocitY3 = 3;


    Vector2f circle4pose = Vector2f(50.f, 300.f);

    // shapes and properties
    CircleShape circle4(35.f);
    circle4.setFillColor(Color::Black);
    circle4.setPosition(circle4pose);
    float yvelocitY4 = 3.5;
    float xvelocitY4 = 2.5;

    Font font1;
    font1.loadFromFile("assets/arial.ttf");

    Text text1;
    text1.setFont(font1);
    text1.setPosition(269.f, 645.f);
    text1.setCharacterSize(27);
    text1.setFillColor(Color::Blue);
    text1.setString("Press 'enter' to start");



    RectangleShape player(Vector2f(100.0f, 150.0f));
    player.setPosition(350.0f, 570.0f);
    sf::Texture playerTexture;
    playerTexture.loadFromFile("assets/DinoSprites_2.png");
    player.setTexture(&playerTexture);

    Animation animation(&playerTexture, sf::Vector2u(3, 9), 0.3f);

    Vector2u textureSize = playerTexture.getSize();
    textureSize.x /= 3; 
    textureSize.y /=9;
    player.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 8, textureSize.x, textureSize.y));

    float deltaTime = 0.0f;
    sf::Clock clock;

    // The Game Loop
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
           
            if (event.type == sf::Event::Closed)
                window.close();

        }
       
        circle1pos.y += yvelocity;
        circle1pos.x += xvelocity;

        circle1.setPosition(circle1pos);
        if (circle1pos.y < 160 || circle1pos.y > 460) yvelocity *= -1;
        if (circle1pos.x < 0 || circle1pos.x > 120) xvelocity *= -1;

        circle2pose.y += yvelocit;
        circle2pose.x += xvelocit;
        circle2.setPosition(circle2pose);
        if (circle2pose.y < 172 || circle2pose.y > 450) yvelocit *= -1;
        if (circle2pose.x < 0 || circle2pose.x > 120) xvelocit *= -1;

        circle3pose.y += yvelocitY3;
        circle3pose.x += xvelocitY3;
        circle3.setPosition(circle3pose);
        if (circle3pose.y < 172 || circle3pose.y > 450) yvelocitY3 *= -1;
        if (circle3pose.x < 0 || circle3pose.x > 120) xvelocitY3 *= -1;

        circle4pose.y += yvelocitY4;
        circle4pose.x += xvelocitY4;
        circle4.setPosition(circle4pose);
        if (circle4pose.y < 172 || circle4pose.y > 450) yvelocitY4 *= -1;
        if (circle4pose.x < 0 || circle4pose.x > 120) xvelocitY4 *= -1;


        animation.Update(0, deltaTime);
        player.setTextureRect(animation.uvRict);
        window.clear();
        
     
        

        window.draw(x);
        window.draw(circle1);
        window.draw(circle2); 
        window.draw(circle3);
        window.draw(circle4);


        window.draw(G);
        window.draw(player);
        window.draw(text);
        window.draw(text1);

        window.display();
        
    }

    return 0;
}

