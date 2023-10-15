#include <PLayerC.h>
#include"Item.h"
#include"MonsterC.h"
#include"RDeck.h"
#include "TDeck.h"
using namespace std;

void game(Player p, Deck t, RDeck r);//function declaration

int main(){

    Player p;//variable for Player class
    Deck treasure;//variable for Deck class
    RDeck room;//variable for RDeck class
    game(p,treasure,room);//function to play the game

}

void game(Player p, Deck t, RDeck r){
    srand(time(NULL));//establishes use for rand
    t.deckShuffle();//calls deck shuffle
    r.rDeckShuffle();//calls room deck shuffle
    Monster fighter;//sets monster variable
    bool play = true;//sets play equal to true
    char choice;//creates choice char
    char choose;//creates choose char
    int discard;//created discard int

    for(int i =0; i<4; i++){
        p.hand.push_back(t.drawCard());//for loop to add cards to your hand in a vector
    }

    p.printStat();//function to output stats to txt file

    while(p.getAlive()&&p.getLevel()<10){//runs while alive and level are less than 10
        fighter = r.drawCard();//sets fighter equal to draw card to draw the monster card
        fighter.printStat();//outputs monster card to txt file
        cout << "Would you like to play a card? y/n " <<endl;
        cin >> choose;//choose if you want to play a card
        if(choose == 'y'){//runs if you choose yes
            while(play){//runs while play is equal to true
                p.playCard();//function to play card
                p.printStat();//function to output your new stats to txt file
                cout << "Would you like to play another card? y/n" <<endl;
                cin >> choice;
                if(choice == 'n'){
                    play = false;//sets play to false if you choose n
                }
            }
        }
        p.battle(fighter,t);//calls battle function
        p.printStat();//outputs new stats after battle to txt file
        play = true;//sets play equal to true
    }
    if(p.getLevel() == 10){
        cout<<"You have won. Congrats. Now go touch grass."<<endl;//if level is equal to 10 runs and you win
        return;
    }
    p.printStat();//outputs stats to txt file
    
}