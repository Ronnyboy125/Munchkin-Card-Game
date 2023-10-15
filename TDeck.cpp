#include <TDeck.h>
#include "Item.h"
#include <PlayerC.h>
#include<random>

void Deck :: setName(string name){
    _name = name;//sets name
}

string Deck :: getName() const{
    return _name;//gets name and returns name
}

void Deck :: deckFill(vector<Item>& deck,string file){//deck fill function
    ifstream fin;
    fin.open(file);//opens file
    string str;//string str
    int count = 0;//sets count to 0
    string tempType;//temporary type
    string tempName;//temporary name
    string tempCond;//temporary condition
    int tempBonus;//temporary bonus

    while(fin >> str){//runs while file is greater than string
        if(count%4 == 0){//runs if count mod 4 is equal to 0
            tempType = str;//sets type to string
        }else if(count%4 == 1){//runs if count mod 4 is equal to 1
            tempBonus = stoi(str);//sets bonus to string
        }else if(count%4 == 2){//runs if count mod 4 is equal to 2
            tempName = str;//sets name to string
        }else if(count%4 == 3){//runs if count mod 4 is equal to 3
            tempCond = str;//sets condition to string
            deck.push_back(Item(tempType,tempName,tempCond,tempBonus));//adds item to deck
        }
        count++;//increases count
     }
    fin.close();//closes file


}

void Deck :: deckShuffle(){//function for deck shuffle
    string file = "treasureCards.txt";//file for treasure cards
    deckFill(items, file);//calls deckfill
    random_shuffle(items.begin(),items.end());//shuffle cards
    
}

Item Deck:: drawCard(){//function for draw card
    Item temp = items.front();//sets temp to first item
    items.erase(items.begin());//delets item
    return temp;//returns temp
}