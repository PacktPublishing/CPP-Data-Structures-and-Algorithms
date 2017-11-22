// Enum.cbp
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum CardSuits
{
    Club,
    Diamond,
    Heart,
    Spade
};

enum CardElements
{
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};

struct Cards
{
    CardSuits suit;
    CardElements element;
};

string GetSuitString(CardSuits suit)
{
    string s;

    switch(suit)
    {
        case Club:
            s = "Club";
            break;
        case Diamond:
            s = "Diamond";
            break;
        case Heart:
            s = "Heart";
            break;
        case Spade:
            s = "Spade";
            break;
    }

    return s;
}

string GetElementString(CardElements element)
{
    string e;

    switch(element)
    {
        case Ace:
            e = "Ace";
            break;
        case Two:
            e = "Two";
            break;
        case Three:
            e = "Three";
            break;
        case Four:
            e = "Four";
            break;
        case Five:
            e = "Five";
            break;
        case Six:
            e = "Six";
            break;
        case Seven:
            e = "Seven";
            break;
        case Eight:
            e = "Eight";
            break;
        case Nine:
            e = "Nine";
            break;
        case Ten:
            e = "Ten";
            break;
        case Jack:
            e = "Jack";
            break;
        case Queen:
            e = "Queen";
            break;
        case King:
            e = "King";
            break;
    }

    return e;
}

int GenerateRandomNumber(int min, int max)
{
    // static used for efficiency,
    // so we only calculate this value once
    static const double fraction =
        1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    // evenly distribute the random number
    // across our range
    return min + static_cast<int>(
        (max - min + 1) * (rand() * fraction));
}

int main()
{
    // set initial seed value to system clock
    srand(static_cast<unsigned int>(time(0)));

    Cards card;
    card.suit = static_cast<CardSuits>(
        GenerateRandomNumber(0, 3));
    card.element = static_cast<CardElements>(
        GenerateRandomNumber(0, 12));

    cout << "Your card is ";
    cout << GetElementString(card.element);
    cout << " of " << GetSuitString(card.suit) << endl;

    return 0;
}
