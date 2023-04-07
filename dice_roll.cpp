#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
using namespace std;

extern const int NUMBER_OF_PLAYERS = 2;

class player {
    public: 
        string name;
        int score;
};

void rolling_output(string player_name){
    cout << player_name << " is rolling.";
    this_thread::sleep_for(chrono::milliseconds(300));
    cout << ".";
    this_thread::sleep_for(chrono::milliseconds(300));
    cout << "." << endl;
};

player gather_player_data() {
    player single_player;
    cout << "Enter player name: ";
    cin >> single_player.name;

    return single_player;
};

int main() {
    player players[NUMBER_OF_PLAYERS];
    for (int i = 0; i < NUMBER_OF_PLAYERS; i++) {
        players[i] = gather_player_data();
    };

    for (int i = 0; i < NUMBER_OF_PLAYERS; i++) {
        rolling_output(players[i].name);
        srand((unsigned) time(NULL));
        players[i].score = 1 + (rand() % 6);
        cout << players[i].name << " rolled a: " << players[i].score << endl;
    };

    player biggest_roll = players[0];
    for (int i = 1; i < NUMBER_OF_PLAYERS; i++) {
        if (players[i].score > biggest_roll.score){
            biggest_roll = players[i];
        };
    }

    cout << biggest_roll.name << " won.";
};
