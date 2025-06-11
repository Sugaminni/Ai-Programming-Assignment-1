#include <iostream>
#include <string>

using namespace std;

class CokeMachine {
    int total;

public:
    CokeMachine() {
        total = 0;
    }

    void insertCoin(string coin) { // Method for calculating coins and returns
        if (coin == "N" || coin == "n") {
            total += 5;
        } else if (coin == "D" || coin == "d") {
            total += 10;
        } else {
            cout << "Invalid input! Please only insert N or D" << endl;
            return;
        }

        if (total == 15) {
            cout << "Can of Coke has been dispensed." << endl;
            total = 0;
        } else if (total > 15) {
            const int change = total - 15;
            cout << "Can of Coke has been dispensed. Change returned: " << change << " cents." << endl;
            total = 0;
        } else {
            cout << "Current total: " << total << " cents." << endl;
        }
    }
};

int main() {
    CokeMachine machine;
    string userInput;

    while (true) {
        cout << "Insert coin (N for Nickel, D for Dime): ";
        cin >> userInput;
        machine.insertCoin(userInput);
    }

    return 0;
}
