#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


//define a data structure that represents a card.

//TODO: Extra part, do an ascending order function that displays cards in ascending order.

struct card{
    string cardSuit;
    int cardRank; //TODO: Code member functions that make sure that if you have J, Q, K etc. they are converted to numbers.
    string highRank;

    string printCards(){
        stringstream ss;
        if(cardRank > 10){
            ss << highRank << " of " << cardSuit << endl;
        }
        else{
            ss << cardRank << " of " << cardSuit << endl;
        }
        return ss.str();
    }

    void formatCards(){
        if(cardSuit == "s"){
            cardSuit = "Spades";
        }
        else if(cardSuit == "c"){
            cardSuit = "Clubs";
        }
        else if(cardSuit == "d"){
            cardSuit = "Diamonds";
        }
        else if(cardSuit == "h"){
            cardSuit = "Hearts";
        }

        if(cardRank == 11){
            highRank = "Jack";
        }
        else if(cardRank == 12){
            highRank = "Queen";
        }
        else if(cardRank == 13){
            highRank = "King";
        }
        else if(cardRank == 14){
            highRank = "Ace";
        }
    }

};

void winner(card player1Card, vector<card> player2Vect, vector<card>& winningVector);
//function that returns true if there is a way for player 2 to win--compares suit/rank from 2's vectors to player 1's card.

int main()
{
    card p1; //player 1's card;

    cout << "Please enter player 1's card: " << endl;
    cin >> p1.cardSuit >> p1.cardRank;
    p1.formatCards(); //Forgot this on first version

    //vector of cards for player 2: format is vector<card>
    vector<card>p2; //declaration of card vector for player 2
    card cards2;

    int numCards; //number of cards for player 2
    cout << " How many cards would you like to enter? " << endl;
    cin >> numCards;

    cout << "Please enter your cards: " << endl;
    do{
        cin >> cards2.cardSuit >> cards2.cardRank;
        cards2.formatCards(); //also forgot this
        p2.push_back(cards2); //store the cards entered into a vector
        numCards -= 1; //decrement # cards to stop when user has entered chosen # of cards.
    } while (numCards > 0);

    vector<card> winningVector; //declares the vector containing winning cards;
    winner(p1, p2, winningVector);

    //case where player 2 can't win
    if(winningVector.size() == 0){
        cout << "You suck" << endl;
    }
    else{
        for(int i = 0; i < winningVector.size(); i++){
            cout << "Your winning cards are " << winningVector[i].printCards() << " ";
        }
    }

    return 0;
}

void winner(card player1Card, vector<card> player2Vect, vector<card>& winningVector){
    //determines of player 2 can win with a chosen card against player 1.
    card tempWin; //you were missing this declaration before. REMEMBER.
    for(int i = 0; i < player2Vect.size(); i++){
        if(player2Vect[i].cardSuit == player1Card.cardSuit && player2Vect[i].cardRank > player1Card.cardRank){
            tempWin = player2Vect[i];
            winningVector.push_back(tempWin);
        }
    }
}
