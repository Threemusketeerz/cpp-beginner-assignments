#include <iostream>
using namespace std;

int main() {

    int input;
    int j = 0;

    do {
        cout << "iteration " << j << endl;
        cout << "number this bitch " << endl;
        cin >> input;
        if (input == j) {
            cout << "That was not nice";
            return 0;
        }

        j++;
    } while (j <= 10);

    cout << "You fucker" << endl;
    return 0;
}
