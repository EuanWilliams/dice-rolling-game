#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
using namespace std;

extern const int NUMBER_OF_PLAYERS = 2;
extern const int SEVEN_HUNDRED_MILLISECONDS = 700;

class Player {
    // Holds data about a player

    public: 
        string name;
        int score;
};

void rolling_the_dice_output(string player_name) {
    // Outputs "(player name) is rolling..." with 0.7s between each dot...create some suspense.

    cout << player_name << " is rolling.";
    this_thread::sleep_for(chrono::milliseconds(SEVEN_HUNDRED_MILLISECONDS));
    cout << ".";
    this_thread::sleep_for(chrono::milliseconds(SEVEN_HUNDRED_MILLISECONDS));
    cout << ".";
    this_thread::sleep_for(chrono::milliseconds(SEVEN_HUNDRED_MILLISECONDS));
    cout << "." << endl;
};

Player gather_player_data() {
    // Asks to user to input their name, creates Player object

    Player single_player;
    cout << "Enter player name: ";
    cin >> single_player.name;

    return single_player;
};

int main() {
    // Main function, makes a list of players, then rolls the dice for each player, and decides who won.

    Player players[NUMBER_OF_PLAYERS];
    for (int i = 0; i < NUMBER_OF_PLAYERS; i++) {
        players[i] = gather_player_data();
    };

    for (int i = 0; i < NUMBER_OF_PLAYERS; i++) {
        rolling_the_dice_output(players[i].name);
        srand((unsigned) time(NULL));
        players[i].score = 1 + (rand() % 6);
        cout << players[i].name << " rolled a " << players[i].score << endl;
    };

    Player biggest_roll = players[0];
    for (int i = 1; i < NUMBER_OF_PLAYERS; i++) {
        if (players[i].score > biggest_roll.score){
            biggest_roll = players[i];
        };
    }

    cout << biggest_roll.name << " won.";
};
