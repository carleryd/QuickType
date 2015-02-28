#include "Dictionary.h"
#include "RichText.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <SFML/Graphics.hpp>

using namespace std;

class Game
{
public:
    Game(sf::RenderWindow* window_);
    void init();
    void run();
    void keyPressed(sf::Event event);
    void nextWord();
    void restart();
private:
    Dictionary* dictionary;
    sf::RenderWindow* window;
    sf::Clock clock;
    sf::Time elapsed;
    sf::Font font;
    sf::Text infoText;
    sf::Text wordText;
	sf::Text scoreText;
    sfe::RichText richText;
    
    string currentWord;
    string typingWord;
    bool started;
    bool gameOver;
    float prepTime;
    float wordTime;
    int score;
    int scoreInc;
    int length;
};