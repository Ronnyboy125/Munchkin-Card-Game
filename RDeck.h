#ifndef RDECK_H
#define RDECK_H
//class for room card deck
#include "MonsterC.h"
#include <algorithm>
#include<string>



class RDeck{//room deck class
    private:
        string _name;//card name
        vector<Monster> cards;//vector to hold monsters
    public: 
        RDeck(){//constructor
            _name = "none";
        }

        RDeck(string name){//constructor
            _name = name;
        }

        void setName(string name);//function to set name

        string getName() const;//function to get name

        void deckFill(vector<Monster>& deck, string file);//function to fill deck

        void rDeckShuffle();//function to shuffle deck

        Monster drawCard();//function to draw room cards

};

#endif