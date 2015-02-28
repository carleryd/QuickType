
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"
#include "Game.h"

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load a sprite to display
//    sf::Texture texture;
//    if (!texture.loadFromFile(resourcePath() + "cute_image.jpg")) {
//        return EXIT_FAILURE;
//    }
    
//    sf::Sprite sprite(texture);
    
//    sf::Music music;
//    if (!music.openFromFile(resourcePath() + "Eiffel_65_Blue.wav"))
//    {
//        // error...
//        cout << "Error loading music" << endl;
//    }
//    
//    music.setLoop(true);         // make it loop
//    music.play();
    
    sf::RectangleShape shape(sf::Vector2f(window.getSize().x, window.getSize().y));
    
    // set the shape color to green
    shape.setFillColor(sf::Color::Black);
    // Create a graphical text to display
//    sf::Font font;
//    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
//        return EXIT_FAILURE;
//    }
//    sf::Text text("Hello SFML", font, 50);
//    text.setColor(sf::Color::Black);

    Game* game = new Game(&window);
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed : exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            
            game->keyPressed(event);
        }
        

        // Clear screen
        window.clear();
        
        // Draw background§
    	window.draw(shape);
        
        game->run();


        // Draw the string
//        window.draw(text);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
