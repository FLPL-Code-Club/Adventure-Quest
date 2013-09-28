#include <iostream>
#include <string>
#include "adventurer.h"
using namespace std;

void beginJourney(adventurer& hero);
bool startBattle(adventurer& hero);
bool fight(adventurer& hero, string enemy);
bool bossBattle(adventurer& hero);
void winGame();

int main(){
    srand(time(NULL));
    adventurer hero;
    string badger;
    string prizes[10]= {"a sword", 
                        "a spear",
                        "a bow",
                        "a mace",
                        "a axe",
                        "a sling-shot",
                        "a dagger",
                        "mauled by angry mutant badgers",
                        "a cute feisty mutant badger",
                        "nothing"};
    int choice = rand()%10;
    char open;
    
    cout<<"Welcome to Adventure Quest 3000™!"<<endl;
    cout<<"Please enter your name, adventurer..."<<endl;
    getline(cin, hero.name);
    
    cout<<"Welcome, "<<hero.name<<"!"<<endl;
    // system("pause");
    system("clear");
    cout<<"You find yourself in a dark, wooded forest of doom."<<endl;
    
    cout<<"You see a chest labeled \"Free stuff! (No badgers here!)\". Do you open it? (y/n)"<<endl;
    cin>>open;
    if(open=='y'){
       cout<<"You got "<< prizes[choice] <<"!!"<<endl;
       hero.weapon = prizes[choice];
       switch(choice){
           case 0:
           case 1:
           case 2:
           case 3:
           case 4:
           case 5:
           case 6:
                cout<<"You don your Monocle of Power and set out to hunt some dirty orcs."<<endl; beginJourney(hero);  break;
           case 7:
                cout<<"You lie on the ground, wallowing in your agonizingly painful badger wounds.\nGood luck with that..."<<endl; break;
           case 8:
                cout<<"You decide to keep the badger.\nWhat do you name it?"<<endl;
                cin>>badger;
                cout<<"You and "<<badger<<" grow to a ripe old age.\n You settle in a valley full of wildflowers, and live out your days, happily.\n Your adventure was lame, but at least you got a mutant badger out of the ordeal."<<endl;
                break;
           case 9:
                cout<<"You shrug it off and go get a milkshake.\nYour adventure was lame, but at least you have a delicious beverage to console you."<<endl; break;
       }
    }else{
       cout<<"You move on your way, and grow to a ripe old age.\n You settle in a valley full of wildflowers, and live out your days, happily.\n Your adventure was lame."<<endl;
    }
    // system("pause");
    return 0;
}

void beginJourney(adventurer& hero){
    bool win = false;
    while(hero.hp>0){
        if(hero.wins<10){
          startBattle(hero);
        }else{
          win = bossBattle(hero);
          break;
        }
        if(hero.hp<=0){
            cout<<"You have been vanquished.\n";
            cout<<"You won "<<hero.wins<<" battles.\n";
            cout<<"You lost "<<hero.losses<<" battles.\n";
            cout<<"You survived "<<(hero.wins+hero.losses-1)<<" battles, total.\n";
        }else{
            cout<<"You have "<<hero.hp<<" health remaining."<<endl;
        }
    }
    if(win == true){
      winGame();
    }
}

bool startBattle(adventurer& hero){
    bool success = true;
    string enemies[5] = {"a goblin",
                         "a wolf",
                         "a wild charizard",
                         "a creeper",
                         "Tim the Enchanter"};
    int index = rand()%5;
    char choice;
    string enemy = enemies[index];
        
    cout<<"As you walk down the road, you encounter "<<enemy<<". \nDo you fight or run? (f/r)"<<endl;
    cin>>choice;
    switch(choice){
        case 'f':
        case 'F':
             success = fight(hero, enemy); break;
        case 'r':
        case 'R':
             cout<<"You ran away, like a pansy. Your hero-card is revoked."<<endl;  break;
        default:
             cout<<"You got confused, and didn't fight or run. The enemy took advantage of your confusion, and swiftly devoured you. The end. Goodbye... \n\n\n\n\n\n\n\n For real, goodbye.\n"; exit(0);
    }
    return success;
}

bool fight(adventurer& hero, string enemy){
    bool success = rand()%2;
    if(success){
        cout<<"You vanquished "<<enemy<<" using your "<<hero.weapon<<"!";
        hero.wins++;
        //This is for drops
          srand(time(NULL));
          int drop = rand()%5;
          int chickens = rand()%100;
          bool dropType = rand()%2;
          
          if(dropType){
              string droptions[5]={"Potion",
                                   "Helmet",
                                   "Smoke Bombs",
                                   "Tim the Enchanter's Prized Ornamental Dagger",
                                   "An Old Shoe"};
              if(hero.inventoryPush(droptions[drop])){
                  cout<<"You got a "<<droptions[drop]<<"!\n";
              }
          }else{
              hero.wallet+=chickens;
          }
          
    }else{
        int damage = rand()%20;
        hero.hp -= damage;
        cout<<"You got your butt kicked by "<<enemy<<"!\nYou took "<<damage<<" damage!"<<endl;
        hero.losses++;
    }
    // system("pause");
    // system("clear");
    return success;
}

// bool fight(adventurer& hero, enemy badGuy){
//   bool success = false;
//   return success;
// }

bool bossBattle(adventurer& hero){
  dragon boss = dragon();
  // cout<<"Strength: "<<boss.strength<<endl;
  cout<<"Name: "<<boss.getName()<<endl;
  return true;
}

void winGame(){
  cout<<"Yay.\n";
}
