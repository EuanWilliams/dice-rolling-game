#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
using namespace std;

void rolling_output(){
    cout << "Rolling.";
    this_thread::sleep_for(chrono::milliseconds(300));
    cout << ".";
    this_thread::sleep_for(chrono::milliseconds(300));
    cout << "." << endl;
}

int main() {
    string player_one_name;
    cout << "Enter player one name: ";
    cin >> player_one_name;
    cout << "Player ones name: " << player_one_name << endl;

    string player_two_name;
    cout << "Enter player two name: ";
    cin >> player_two_name;
    cout << "Player two name: " << player_two_name << endl;

    rolling_output();
    
    srand((unsigned) time(NULL));
    int random = 1 + (rand() % 6);
    cout << "Random number " << random << endl;     
}