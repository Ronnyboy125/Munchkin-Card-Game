#include "RDeck.h"
#include "PlayerC.h"

void RDeck :: setName(string name){
    _name = name;//sets name
}

string RDeck :: getName() const{
    return _name;//gets and returns name
}

void RDeck :: deckFill(vector<Monster>& deck,string file){//function for deck fill
    ifstream fin;
    fin.open(file);//creats and opens file
    string str;//str string
    int count = 0;//count int
    string tempName;//temporary name
    string tempType;//temporary type
    int tempLevel;//temporary level
    int tempLevels;//temporary levels
    int tempTreasure;//temporary treasure
    int tempPursue;//temporary pursue

    while(fin >> str){//while the file is greater than the string
        if(count%6 == 0){//runs if count mod 6 is equal to 0
            tempType = str;//sets temp to string
        }else if(count%6 == 1){//runs if count mod 6 is equal to 1
            tempLevel = stoi(str);//sets temp level to string
        }else if(count%6 == 2){//runs if count mod 6 is equal to 2
            tempName = str;//sets temp name to string
        }else if(count%6 ==3){//runs if count mod 6 is equal to 3
            tempLevels = stoi(str);//sets temp levels to string
        }else if(count%6 == 4){//runs if count mod 6 is equal to 4
            tempTreasure =stoi(str);//sets temp treasure to string
        }else if(count%6 == 5){//runs if count mod 6 is equal to 5
            tempPursue = stoi(str);//sets temp pursue to string
            deck.push_back(Monster(tempName,tempLevel,tempType,tempLevels, tempTreasure, tempPursue));//adds monster to deck
        }
        count++;//increases count
    }
    fin.close();//closes file

}

void RDeck :: rDeckShuffle(){//deck shuffle function
    string file = "roomCards.txt";//sets file equal to room cards
    deckFill(cards, file);//calls deck fill function
    random_shuffle(cards.begin(),cards.end());//shuffles cards
}

Monster RDeck:: drawCard(){//draw card function
    Monster temp = cards.front();//sets monster temp to first card
    cards.erase(cards.begin());//erases card
    return temp;//returns temp
}