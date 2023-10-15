#include <PlayerC.h>
#include"Item.h"

void Player::setHead(string name){
    headgear = name;//sets head
}

void Player::setArmor(string name){
    armor = name;//sets armor
}

void Player::setFoot(string name){
    footgear = name;//sets foot
}

void Player::setWeapon(string name){
    weapon = name;//sets weapon
}

void Player::setJob(string name){
    job = name;//sets job
}

void Player::setRace(string name){
    race = name;//sets race
}

void Player::discard(int card){//discard function
    discardPile.push_back (hand[card-1]);//puts card from hand into discard pile
    hand.erase(hand.begin()+card-1);//erases card from hand
}

void Player::setLevel(int num){
    level+=num;//sets level
}

void Player::setBonus(int num){
    bonus = bonus + num;//sets bonus
}

bool Player::getAlive()const{
    return alive;//returns alive
}

int Player:: getLevel()const{
    return level;//returns level
}


void Player::playCard(){//play card function
    int choice;//int for choice
    if(hand.size()==0){//runs if hand size is equal to 0
        cout << "You have no cards to play. " <<endl;
        return;
    }
    else{
        cout << "Which card would you like to play?"<<endl;
    }
    cin>>choice;
    if(hand[choice-1].getCondition()=="none"){//runs if card condition is set to none
        if(hand[choice-1].getType()=="level"){//runs if type is equal to level
            setLevel(hand[choice-1].getBonus());//sets level
            discard(choice);//discards
            return;
        }else if(hand[choice-1].getType()=="Headgear"){//runs if card type is headgear
            setHead(hand[choice-1].getName());//sets head
            setBonus(hand[choice-1].getBonus());//sets bonus
            discard(choice);
            return;
        }else if(hand[choice-1].getType()=="Armor"){//runs if type is equal to armor
            setArmor(hand[choice-1].getName());//sets armor
            setBonus(hand[choice-1].getBonus());//sets bonus
            discard(choice);
            return;
        }else if(hand[choice-1].getType()=="Footgear"){//runs if type is equal to footgear
            setFoot(hand[choice-1].getName());//sets foot
            setBonus(hand[choice-1].getBonus());
            discard(choice);
            return;
        }else if(hand[choice-1].getType()=="Weapon"){//runs if type is equal to weapon
            setWeapon(hand[choice-1].getName());//sets weapon
            setBonus(hand[choice-1].getBonus());
            discard(choice);
            return;
        }else if(hand[choice-1].getType()=="Item"){//runs if type is equal to item
            setBonus(hand[choice-1].getBonus());//sets bonus
            discard(choice);
            return;
        }
    }else if(hand[choice-1].getCondition()== race){//runs if condition is equal to race
        if(hand[choice-1].getType()=="Headgear"){
            setHead(hand[choice-1].getName());
            setBonus(hand[choice-1].getBonus());
            discard(choice);
            return;
        }else if(hand[choice-1].getType()=="Armor"){
            setArmor(hand[choice-1].getName());
            setBonus(hand[choice-1].getBonus());
            discard(choice);
            return;
        }else if(hand[choice-1].getType()=="Footgear"){
            setFoot(hand[choice-1].getName());
            setBonus(hand[choice-1].getBonus());
            discard(choice);
            return;
        }else if(hand[choice-1].getType()=="Weapon"){
            setWeapon(hand[choice-1].getName());
            setBonus(hand[choice-1].getBonus());
            discard(choice);
            return;
        }else if(hand[choice-1].getType()=="Item"){
            setBonus(hand[choice-1].getBonus());
            discard(choice);
            return;
        }
    }else if (hand[choice-1].getCondition()== job){//runs if condition is equal to job
        if(hand[choice-1].getType()=="Headgear"){
            setHead(hand[choice-1].getName());
            setBonus(hand[choice-1].getBonus());
            discard(choice);
            return;
        }else if(hand[choice-1].getType()=="Armor"){
            setArmor(hand[choice-1].getName());
            setBonus(hand[choice-1].getBonus());
            discard(choice);
            return;
        }else if(hand[choice-1].getType()=="Footgear"){
            setFoot(hand[choice-1].getName());
            setBonus(hand[choice-1].getBonus());
            discard(choice);
            return;
        }else if(hand[choice-1].getType()=="Weapon"){
            setWeapon(hand[choice-1].getName());
            setBonus(hand[choice-1].getBonus());
            discard(choice);
            return;
        }else if(hand[choice-1].getType()=="Item"){
            setBonus(hand[choice-1].getBonus());
            discard(choice);
            return;
        }
    }else if(hand[choice-1].getCondition()== "job"){
        setJob(hand[choice-1].getName());
        discard(choice);
        return;
    }else if(hand[choice-1].getCondition() == "race"){
        setRace(hand[choice-1].getName());
        discard(choice);
        return;
    }else if(hand[choice-1].getCondition()== "once"){
        setBonus(hand[choice-1].getBonus());
        discard(choice);
        return;
    }else{
        cout << "You Cannot Play That Card"<<endl;
    }
}

void Player:: battle(Monster fight,Deck tDeck){//battle function
    int treasures=fight.getTreasure();//sets treasures int equal to monsters treasure
    if(fight.getPursue()<=level){//runs if level is greater than pursue
        if(fight.getType()=="Curse"){//runs if type is curse
            if(level ==1){//runs if level is equal to 1
                cout << "you drew a curse but couldn't lose a level! " <<endl;
            }
            else{
                level+=fight.getLevels();//gets levels and adds them to yours
                return;
            }
        }else if(fight.getLevel()<bonus+level){//runs if monster level is less than your level and bonuses
            cout << "You are victorious!"<<endl;
            level=level+fight.getLevels();//gets levels and adds them to yours
            for(int i=0; i<treasures; i++){
                hand.push_back(tDeck.drawCard());//adds treasures to your hand
            }
            return;
        }else if(fight.getLevel()>=bonus+level){//runs if monster level is greater than yours and bonuses
            if(runAway()>4){//runs if runaway function is greater than 4
                cout << "You managed to escape a losing battle!" << endl;
                return;
            }else{
                cout << "You were beaten" << endl;
                alive = false;//sets alive to false
                return;
            }
        }
    }else{//runs if pursue is less
        cout << "That Monster deemed you weak and let you go!" <<endl;
        return;
    }
}

int Player:: runAway(){//runaway function
    int escape = (rand()%6)+1;//sets escape to rand mod 6 + 1
    return escape;
}

void Player::printStat(){//print stat function
    ofstream stats; stats.open("Player Stats.txt");//creates and opens player stats then prints all of the stats
    stats<<"Headgear: "<<headgear<<endl; stats<<"Armor: "<<armor<<endl; stats<<"Footgear: "<<footgear<<endl;
    stats<<"Weapon: "<<weapon<<endl; stats<<"Race: "<< race << endl <<"Class: " << job << endl;
    stats<<"Level: "<<level<<endl; stats<<"Bonus level: "<<bonus <<endl << "Alive: " << alive<<endl; 
    for(int i =0; i<hand.size(); i++){//for loop to print out all cards in hand
        stats << "Card " << i+1 << ": " << hand[i].getType() << " " << hand[i].getName()
              << " " << hand[i].getCondition()<< " " << hand[i].getBonus()<<endl;
    }
    stats.close();//closes file
}