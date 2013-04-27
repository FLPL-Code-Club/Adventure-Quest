#include <iostream>
using namespace std;

class adventurer{
public:
    string name;
    string weapon;
    string inventory[50];
    
    int hp;
    int wins;
    int losses;
    int wallet;
    
    adventurer();
    adventurer(string name);
    bool inventoryPush(string drop);
};

adventurer::adventurer(){
    name = "Johnny Appleseed";
    weapon = "Fist";
    hp = 100;
    wins = 0;
    losses = 0;
    wallet = 0;
    for(int i=0; i<50; ++i)
        inventory[i]="";
}

adventurer::adventurer(string str){
    name = str;
    weapon = "Fist";
    hp = 100;
    wins = 0;
    losses = 0;
    wallet = 0;
    for(int i=0; i<50; ++i)
        inventory[i]="";
}

bool adventurer::inventoryPush(string drop){
    int i=0;
    while(inventory[i] != ""){
        ++i;
    }
    if(i<50){
        inventory[i] = drop;
        return true;
    }
    cout<<"Your inventory is already full!\n";
    return false;
}
