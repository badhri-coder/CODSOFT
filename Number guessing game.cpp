
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int target = rand() % 100 + 1;
    int guess;

    while (true) {
        cout << "Enter your guess (1-100): ";
        cin >> guess;

        if (guess > target)
            cout << "Too high.\n";
        else if (guess < target)
            cout << "Too low.\n";
        else {
            cout << "Correct! The number was " << target << ".\n";
            break;
        }
    }
    return 0;
}
