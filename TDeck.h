#ifndef TDECK_H
#define TDECK_H
//class for treasure deck
#include "Item.h"
#include <vector>
#include <string>
#include<algorithm>
#include <fstream>

class Deck{//class for treasure deck
    private:
        string _name;//name of card
    public:
        vector<Item> items;//vector to hold items
        Deck(){//constructor
            _name = "NONE";
        }

        Deck(string name){//constructor
            _name = name;
        }

        void setName(string name);//function to set name

        string getName() const;//function to get name

        void deckFill(vector<Item>& deck, string file);//function to fill deck

        void deckShuffle();//function to shuffle deck

        Item drawCard();//function to draw card

        


};




#endif