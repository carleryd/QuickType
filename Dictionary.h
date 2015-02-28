#ifndef __FUN__dictionary__
#define __FUN__dictionary__

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

class Dictionary
{
public:
    Dictionary(string textFile);
    void print();
    string getRandom();
    char toASCII(sf::Keyboard::Key key);
    
private:
    vector<string> wordBank;
};

#endif /* defined(__FUN__dictionary__) */
