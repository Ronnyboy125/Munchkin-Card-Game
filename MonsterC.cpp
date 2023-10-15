#include <MonsterC.h>

string Monster::getName(){
    return name;//gets and returns name
}

int Monster::getLevel(){
    return level;//gets and returns level
}

int Monster::getLevels(){
    return levels;//gets and returns levels
}

int Monster::getTreasure(){
    return treasure;//gets and returns treasures
}

int Monster::getPursue(){
    return pursue;//gets and returns pursue
}

string Monster::getType(){
    return type;//gets and returns type
}

void Monster:: printStat(){
    ofstream stats; stats.open("Monster Stats.txt");//creats and opens monster txt file
    stats<<"Name: " << name <<endl <<"Level: " << level << endl << "Levels: " <<levels <<endl
         <<"Treasures: " << treasure <<endl;//prints all of the monsters stats
    stats.close();//closes file
}