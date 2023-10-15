#ifndef ITEM_H
#define ITEM_H
//Item class for item cards
#include <iostream>
using namespace std;

class Item{//class for item
    private:
        string _type;//type of card
        string _name;//name of card
        string _condition;//card condition
        int _bonus;//card bonus level
    public: 
        Item(){//constructor
            _type = "none";
            _name = "none";
            _condition = "N/A";
            _bonus = 0;
        }

        Item(string type, string name, string condition, int bonus){//constructor
            _type = type;
            _name = name;
            _condition = condition;
            _bonus = bonus;
        }

        string getType()const;//function to get card type

        string getName()const;//function to get card name

        string getCondition()const;//function to get card condition

        int getBonus()const;//function to get card bonuses
    
};


#endif