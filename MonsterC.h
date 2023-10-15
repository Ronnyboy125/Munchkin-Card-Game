#ifndef MonsterC_h
#define MonsterC_h
//class for monster card
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Monster{//monster class
    private:
        string name;//name of monster
        string type;//monster type
        int level;//monster level
        int levels;//monster levels that you recieve if you defeat it
        int treasure;//amount of treasures given if you defeat monster
        int pursue;//pursue level, if level is higher than yours it will not pursue you
    public:
        Monster(){//constructor
            name = "??"; type = "??"; level = 1; levels = 1; treasure = 1; pursue = 0;
        }
        Monster(string n, int l, string ty, int ls, int t, int p){//constructor
            name = n; type = ty; level = l; levels = ls; treasure = t; pursue = p;
        }
        string getName();//function to get monster name
        int getLevel();//function to get monster level
        int getLevels();//function to get monster levels
        int getTreasure();//functiont to get monster treasure
        int getPursue();//function to get monsters pursue level
        string getType();//function to get monster type
        void printStat();//function for printing stats
};

#endif