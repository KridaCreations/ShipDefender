#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
using namespace std;

//int main()
//{
//    //sf::RenderWindow window(sf::VideoMode().getFullscreenModes()[0], "SFML works!", sf::Style::Fullscreen);
//    sf::RenderWindow window(sf::VideoMode(257,813), "SFML works!", sf::Style::Default);
//    
//    sf::VideoMode myscreenmode = sf::VideoMode::getDesktopMode();
//    cout << myscreenmode.width << endl;
//    cout << myscreenmode.height << endl;
//    cout << myscreenmode.bitsPerPixel <<endl;
//
//
//    sf::Clock clock;
//    clock.restart();
//    int maximum = 10000;
//    for (int i = 0; i < maximum; i++)
//    {
//        //cout << (((float)i * 100.00) / (float)maximum) << endl;
//    }
//    /*sf::Cursor cursor;
//    if (cursor.loadFromSystem(sf::Cursor::Hand))
//        window.setMouseCursor(cursor);*/
//    sf::Cursor cursor;
//    int time = clock.getElapsedTime().asSeconds();
//    int curtype = 0;
//    while (window.isOpen())
//    {
//        // check all the window's events that were triggered since the last iteration of the loop
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            // "close requested" event: we close the window
//            if (event.type == sf::Event::Closed)
//            {
//                window.close();
//                cout << "closed button pressed" << endl;
//            }
//            else if (event.type == sf::Event::Resized)
//            {
//                cout << "new window size" << endl;
//                std::cout << "new width: " << event.size.width << std::endl;
//                std::cout << "new height: " << event.size.height << std::endl;
//            }
//            else if (event.type == sf::Event::TextEntered)
//            {
//                if (event.text.unicode < 128)
//                    std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
//            }
//        }
//        
//        /*if (cursor.loadFromSystem((sf::Cursor::Type)curtype))
//            window.setMouseCursor(cursor); 
//        if ((clock.getElapsedTime().asSeconds() - time) > 1)
//        {
//            time = clock.getElapsedTime().asSeconds();
//            curtype++;
//            if (curtype - 1 == sf::Cursor::NotAllowed)
//            {
//                curtype = 0;
//            }
//        }*/
//        
//    }
//    sf::Time elapsed_time = clock.getElapsedTime();
//    cout <<"elapsed time " << elapsed_time.asMicroseconds() << " " << endl;
//    
//    return 0;
//}
