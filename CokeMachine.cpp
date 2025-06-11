#include <iostream>
#include <string>

using namespace std;

// CokeMachine class simulates finite state machine for coke machine
class CokeMachine {
    int total;

public: // Constructor initializes the total to 0
    CokeMachine() {
        total = 0;
    }

    void insertCoin(string coin) { // Method for calculating coins and returns
        if (coin == "N" || coin == "n") {
            total += 5;
        } else if (coin == "D" || coin == "d") {
            total += 10;
        } else { // Handles invalid inputs
            cout << "Invalid input! Please only insert N or D" << endl;
            return;
        }

        if (total == 15) { // Dispenses coke if total is exactly 15 cents
            cout << "Can of Coke has been dispensed." << endl;
            total = 0;
        } else if (total > 15) { // If total exceeds 15, dispenses coke and returns the change
            const int change = total - 15;
            cout << "Can of Coke has been dispensed. Change returned: " << change << " cents." << endl;
            total = 0; // Resets machine
        } else { // Else, shows current amount of coins inserted
            cout << "Current total: " << total << " cents." << endl;
        }
    }
};

 // Main function (Program entry)
int main() {
    CokeMachine machine; // Creates instance of coke machine
    string userInput;

    while (true) { // Runs infinite loop to simulate ongoing coke machine operating
        cout << "Insert coin (N for Nickel, D for Dime): ";
        cin >> userInput; // Takes input from user
        machine.insertCoin(userInput); // Passes input into the coke machine
    }

    return 0;
}
