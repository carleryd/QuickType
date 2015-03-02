#include "Game.h"
#include "ResourcePath.hpp"

Game::Game(sf::RenderWindow* window_) {
    window = window_;

    //sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        cout << "FAIL TO LOAD TEXTFILE" << endl;
    }
    
    font.loadFromFile("/Users/christoferarleryd/Documents/Programming/QuickType/QuickType/sansation.ttf");
    infoText.setFont(font);
    infoText.setCharacterSize(40);
    infoText.setStyle(sf::Text::Bold);
    infoText.setColor(sf::Color::Magenta);
    infoText.setPosition(100, 100);
    
    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setStyle(sf::Text::Bold);
    scoreText.setColor(sf::Color::White);
    scoreText.setPosition(100, 400);
    
    richText.setFont(font);
    richText.setCharacterSize(50);
    richText.setPosition(300, 400);
    
    dictionary = new Dictionary("/Users/christoferarleryd/Documents/Programming/QuickType/QuickType/dictionary.txt");
    init();
}

void Game::init() {
    prepTime = 1;
    wordTime = 30;
    score = 0;
    scoreText.setString("0 points");
    scoreInc = 10;
    started = false;
    gameOver = false;
    clock.restart();
    
    currentWord = dictionary->getRandom();
    richText.clear();
    richText << sf::Text::Bold << sf::Color::Red << currentWord;
}


template<class type>
string toString(type number, int precision) {
    ostringstream out;
    out << fixed << setprecision(precision) << number;
    return out.str();
}

void Game::keyPressed(sf::Event event) {
    if(event.type == sf::Event::KeyPressed) {
        if(event.key.code >= 0 && event.key.code <= 25 && !gameOver) {
            typingWord += dictionary->toASCII(event.key.code);
            
            // Check how many correct letters has been typed
            for(int i = 0; i < typingWord.length(); ++i) {
                if(currentWord.substr(0, i+1) == typingWord.substr(0, i+1)) {
                    length = i+1;
                    if(typingWord == currentWord) {
                        score += scoreInc;
                        scoreInc += 10;
                        scoreText.setString(toString(score, 2) + " points");
                        
                        length = 0;
                        typingWord = "";
                        currentWord = dictionary->getRandom();
                        break;
                    }
                }
                else {
                    length = 0;
                    typingWord = "";
                    currentWord = dictionary->getRandom();
                    
                    wordTime -= 5;
                    scoreText.setString(toString(score, 2) + " points");
                    break;
                }
            }
        
            richText.clear();
            richText << sf::Text::Bold << sf::Color::Green << currentWord.substr(0, length)
                     << sf::Text::Bold << sf::Color::Red << currentWord.substr(length, currentWord.length());
    	}
        else if(event.key.code == sf::Keyboard::Return && gameOver) {
            init();
        }
    }
}

void Game::run() {
    elapsed = clock.getElapsedTime();
    window->draw(infoText);
    window->draw(scoreText);
    
    if(!started) {
		if(elapsed.asSeconds() < prepTime) {
            infoText.setString("Welcome to QuickType!\nGame will start in " + toString(prepTime - elapsed.asSeconds(), 1) + " seconds");
        }
        else {
			started = true;
         	clock.restart();
        }
    }
    else if(!gameOver) {
        window->draw(richText);
        infoText.setString(toString(wordTime - elapsed.asSeconds(), 1));
        if(wordTime - elapsed.asSeconds() <= 0) {
            infoText.setString("You scored " + toString(score, 2) + " points\nPress enter to restart");
            gameOver = true;
        }
    }
    else {
        // Wait for player to press enter to restart game
    }
}