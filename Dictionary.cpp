#include "dictionary.h"
#include <fstream>

Dictionary::Dictionary(string textFile) {
	ifstream words;
    string word;
    words.open(textFile);
    
    while(!words.eof()) {
        words >> word;
        wordBank.push_back(word);
    }
}

void Dictionary::print() {
    for(string word : wordBank) {
        cout << "word: " << word << endl;
    }
}

string Dictionary::getRandom() {
    int random = rand() % wordBank.size();
    return wordBank[random];
}

char Dictionary::toASCII(sf::Keyboard::Key key) {
    return (int)key+97;
}