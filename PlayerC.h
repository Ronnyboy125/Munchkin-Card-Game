#ifndef PlayerC_h
#define PlayerC_h
//class for the player
#include <iostream>
#include <vector>
#include "Item.h"
#include "MonsterC.h"
#include <fstream>
#include "TDeck.h"
#include<ctime>
using namespace std;

class Player{//player class
    private:
        int level;//player level
        int bonus;//player bonus level
        string race;//player race
        string job;//player job
        string headgear;//player headgear
        string armor;//player armor
        string footgear;//player footgear
        string weapon;//player weapon
        bool alive;//bool to see if player is alive or not
    public:
        vector<Item>hand;//vector for hand to hold cards
        vector<Item>discardPile;//vector for discard pile
        Player(){//constructor
            level = 1; bonus = 0; race = "human"; job = "None"; headgear = "None"; armor = "None"; footgear = "None"; alive = true; weapon = "None";
        }
        Player(int l, int b, string h, string a, string f, bool al){//constructor
            level = l; bonus = b, headgear = h, armor = a, footgear = f; alive = al;
        }
        void setHead(string name);//function to set headgear
        void setLevel(int num);//function to set player level
        void setArmor(string name);//function to set armor
        void setFoot(string name);//function to set footgear
        void setWeapon(string name);//function to set weapon
        void setJob(string name);//function to set job
        void setRace(string name);//function to set race
        void discard(int card);//function for discard
        void setBonus(int num);//function to set bonuses
        bool getAlive()const;//function to get alive bool
        int getLevel()const;//function to get player level
        void battle(Monster fight,Deck tDeck);//function for battle
        int runAway();//function for runaway
        void playCard();//function for play cards
        void printStat();//function for printing player stats

};

#endif