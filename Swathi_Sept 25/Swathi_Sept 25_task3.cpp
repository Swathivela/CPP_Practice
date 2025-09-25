#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <random>
using namespace std;

// ---------------- Card Class ----------------
class Card {
private:
    int face; // 0–12
    int suit; // 0–3

public:
    static const string faces[13];
    static const string suits[4];

    Card(int f, int s) : face(f), suit(s) {}

    int getFace() const { return face; }
    int getSuit() const { return suit; }

    string toString() const {
        return faces[face] + " of " + suits[suit];
    }
};

const string Card::faces[13] = {
    "Ace", "Deuce", "Three", "Four", "Five", "Six",
    "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"
};
const string Card::suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

// ---------------- DeckOfCards Class ----------------
class DeckOfCards {
private:
    vector<Card> deck;
    int currentCard;

public:
    DeckOfCards() {
        for (int s = 0; s < 4; ++s)
            for (int f = 0; f < 13; ++f)
                deck.push_back(Card(f, s));
        currentCard = 0;
    }

    void shuffle() {
        static random_device rd;
        static mt19937 g(rd());
        std::shuffle(deck.begin(), deck.end(), g);
        currentCard = 0;
    }

    Card dealCard() {
        return deck[currentCard++];
    }
};

// ---------------- Hand Evaluation ----------------
struct HandValue {
    int rank;          // strength of hand
    vector<int> high;  // high cards for tie-breaking
};

HandValue evaluateHand(vector<Card>& hand) {
    map<int, int> faceCount;
    map<int, int> suitCount;

    for (auto& c : hand) {
        faceCount[c.getFace()]++;
        suitCount[c.getSuit()]++;
    }

    // Sort faces
    vector<int> faces;
    for (auto& c : hand) faces.push_back(c.getFace());
    sort(faces.begin(), faces.end());

    // Check flush
    bool flush = (suitCount.size() == 1);

    // Check straight (special Ace handling omitted for simplicity)
    bool straight = true;
    for (int i = 1; i < 5; i++) {
        if (faces[i] != faces[0] + i) {
            straight = false;
            break;
        }
    }

    // Count groups
    vector<int> counts;
    for (auto& kv : faceCount) counts.push_back(kv.second);
    sort(counts.rbegin(), counts.rend());

    HandValue hv;

    if (straight && flush) hv.rank = 8;          // Straight flush
    else if (counts[0] == 4) hv.rank = 7;        // Four of a kind
    else if (counts[0] == 3 && counts[1] == 2) hv.rank = 6; // Full house
    else if (flush) hv.rank = 5;                 // Flush
    else if (straight) hv.rank = 4;              // Straight
    else if (counts[0] == 3) hv.rank = 3;        // Three of a kind
    else if (counts[0] == 2 && counts[1] == 2) hv.rank = 2; // Two pair
    else if (counts[0] == 2) hv.rank = 1;        // One pair
    else hv.rank = 0;                            // High card

    // For tie-breaking, just store faces descending
    sort(faces.rbegin(), faces.rend());
    hv.high = faces;
    return hv;
}

// Compare two hands
int compareHands(vector<Card>& h1, vector<Card>& h2) {
    HandValue hv1 = evaluateHand(h1);
    HandValue hv2 = evaluateHand(h2);

    if (hv1.rank != hv2.rank)
        return (hv1.rank > hv2.rank) ? 1 : -1;

    // If ranks are same, compare high cards
    for (size_t i = 0; i < hv1.high.size(); i++) {
        if (hv1.high[i] != hv2.high[i])
            return (hv1.high[i] > hv2.high[i]) ? 1 : -1;
    }
    return 0; // tie
}

// ---------------- Driver ----------------
int main() {
    DeckOfCards deck;
    deck.shuffle();

    vector<Card> hand1, hand2;

    for (int i = 0; i < 5; i++) hand1.push_back(deck.dealCard());
    for (int i = 0; i < 5; i++) hand2.push_back(deck.dealCard());

    cout << "Player 1's hand:\n";
    for (auto& c : hand1) cout << "  " << c.toString() << endl;

    cout << "\nPlayer 2's hand:\n";
    for (auto& c : hand2) cout << "  " << c.toString() << endl;

    int result = compareHands(hand1, hand2);

    cout << "\nResult: ";
    if (result == 1) cout << "Player 1 wins!\n";
    else if (result == -1) cout << "Player 2 wins!\n";
    else cout << "It's a tie!\n";

    return 0;
}
