#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
using namespace std;

class player {
    public: 
        string name;
        int score;
};

void rolling_output(){
    cout << "Rolling.";
    this_thread::sleep_for(chrono::milliseconds(300));
    cout << ".";
    this_thread::sleep_for(chrono::milliseconds(300));
    cout << "." << endl;
};

int main() {
    player player_one; 
    cout << "Enter player one name: ";
    cin >> player_one.name;

    player player_two;
    cout << "Enter player two name: ";
    cin >>  player_two.name;

    rolling_output();

    srand((unsigned) time(NULL));
    player_one.score = 1 + (rand() % 6);
    cout << player_one.name << " rolled a: " << player_one.score << endl;

    rolling_output();

    srand((unsigned) time(NULL));
    player_two.score = 1 + (rand() % 6);
    cout << player_two.name << " rolled a: " << player_two.score << endl;

    if (player_one.score > player_two.score) {
        cout << player_one.name << " won.";
    }
    else {
        cout << player_two.name << " won.";
    }
};
