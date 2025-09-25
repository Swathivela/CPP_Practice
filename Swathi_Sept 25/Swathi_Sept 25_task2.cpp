#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  
#include <random>     
#include <ctime>      
using namespace std;

// ----------------- Card Class -----------------
class Card {
private:
    int face;  // 0–12
    int suit;  // 0–3

public:
    static const string faces[13];
    static const string suits[4];

    // Constructor
    Card(int f, int s) : face(f), suit(s) {}

    // Return card as "Face of Suit"
    string toString() const {
        return faces[face] + " of " + suits[suit];
    }
};

// Initialize static arrays
const string Card::faces[13] = {
    "Ace", "Deuce", "Three", "Four", "Five", "Six",
    "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"
};

const string Card::suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};


// ----------------- DeckOfCards Class -----------------
class DeckOfCards {
private:
    vector<Card> deck;
    int currentCard;

public:
    // Constructor: create 52 cards
    DeckOfCards() {
        for (int s = 0; s < 4; ++s) {
            for (int f = 0; f < 13; ++f) {
                deck.push_back(Card(f, s));
            }
        }
        currentCard = 0;
    }

    // Shuffle deck
    void shuffle() {
        static random_device rd;
        static mt19937 g(rd());
        std::shuffle(deck.begin(), deck.end(), g);
        currentCard = 0;
    }

    // Deal next card
    Card dealCard() {
        if (moreCards()) {
            return deck[currentCard++];
        } else {
            throw out_of_range("No more cards to deal.");
        }
    }

    // Check if more cards remain
    bool moreCards() const {
        return currentCard < deck.size();
    }
};



int main() {
    DeckOfCards deck;

    deck.shuffle(); // shuffle deck

    cout << "Dealing 52 cards:\n\n";

    // Deal all cards
    int count = 0;
    while (deck.moreCards()) {
        cout << deck.dealCard().toString() << "\t";

        // print 4 cards per line
        if (++count % 4 == 0)
            cout << endl;
    }

    return 0;
}
