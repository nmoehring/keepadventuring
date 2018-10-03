#include <string>
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

void Story();
bool AskYesNo(string);
int RollDie(int sides=6);
void Ending();
void Adventure();
void Sleep(int);
string AllCaps(string);

int health = 100;
int totalTreasure = 0;

int main() {
    bool adventure = true;
    srand(time(0));
    Story();
    while (adventure && health > 0) {
        Sleep(1500);
        adventure = AskYesNo("\nWill you attack the orcs?");
        if (adventure) {Adventure();}
    }
    Ending();
    return 0;
}

void Story() {
    cout << "You're an unusually large dwarf, nearly the size of a man." << endl;
    Sleep(2500);
    cout << "Several lights dot the distance in the twilight-dimmed, sparse,";
    cout << " forest." << endl;
    Sleep(2500);
    cout << "You're in orc country now. Their yards will surely be littered with";
    cout << " the treasures swiped off passing-through caravans." << endl;
    Sleep(2500);
    cout << "You could choose to catch the orcs off guard and run off with their";
    cout << " trinkets, but you may lose valuable time on your journey..." << endl;
    Sleep(2500);
}

bool AskYesNo(string question) {
    string userInput;
    vector<string> yes_vector = {"YES", "Y", "YE", "YAY", "SI", "TRUE", "HAI", "OUI", "1"};
    vector<string> no_vector = {"NO", "N", "FALSE", "NAY", "IIE", "NON", "0"};
    cout << question << "\n>>> ";
    while (true) {
        getline(cin,userInput);
        userInput = AllCaps(userInput);
        if (find(yes_vector.begin(),yes_vector.end(),userInput) != yes_vector.end()) {
            return true;
        } else if (find(no_vector.begin(),no_vector.end(),userInput) != no_vector.end()) {
            return false;
        } else {
            cout << "Invalid answer." << endl;
        }
    }
}

int RollDie(int sides) {
    return (rand() % sides) + 1;
}

void Adventure() {
    cout << "You start trashing one of the orcs' yards, and an orc rushes out";
    cout << " in his pajamas and yells several obscenities at you!" << endl;
    int orcAttack = RollDie(100);
    int playerBlock = RollDie(100);
    if (orcAttack > playerBlock) {
        cout << "The orc hits you over the head with a hammer and deals " << orcAttack;
        cout << " damage! You are forced to flee the fight!" << endl;
        health -= orcAttack;
    } else {
        int haul = RollDie();
        cout << "You fend off the orc and run off with " << haul;
        cout << " of its treasures!" << endl;
        totalTreasure += haul;
    }
}

void Ending() {
    if (health <= 0) {
        cout << "\n~~~You died!~~~" << endl;
    } else if (health <= 50) {
        if (totalTreasure > 0) {
            cout << "Running in the dark forest, you clutch your " << totalTreasure;
            cout << " trinkets to your chest, hoping you're heading in the direction of the city.\n";
            cout << "You barely made it out alive, with only " << health;
            cout << " health left. Hopefully it was worth it." << endl;
        } else {
            cout << "With only " << health << " health left, you barely make";
            cout << " it out alive. You have nothing to show for your troubles." << endl;
        }
    } else if (health < 100) {
        if (totalTreasure > 0) {
            cout << "You whistle an old dwarvish folk song while you find your ";
            cout << "way back to the trail.\n You've got " << totalTreasure;
            cout << " trinkets in your backpack and with " << health;
            cout << " health, you feel pretty fricking good right now." << endl;
        } else {
            cout << "Walking away from the orc encampments, you feel lucky to";
            cout << " just to get away with your life.\n You have no treasure";
            cout << " and you're just a little bit embarressed after having lost";
            cout << health << " health, but things could be worse." << endl;
        }
    } else {
        if (totalTreasure > 0) {
            cout << "'Suckers.' You snicker to yourself as you run back to the";
            cout << " trail.\n You have full health and " << totalTreasure;
            cout << " trinkets in your backpack. Damn, you're good!" << endl;
        } else {
            cout << "You wander back towards the trail that got you here.\n";
            cout << "No treasure, but you have full health. You live to fight";
            cout << " another day." << endl;
        }
    }
}

string AllCaps(string phrase) {
    string newPhrase;
    string::const_iterator iter;
    for (iter = phrase.begin(); iter < phrase.end(); iter++) {
        newPhrase += char(toupper(*iter));
    }
    return newPhrase;
}

void Sleep(int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}
