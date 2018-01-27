#include <iostream>
using namespace std;

int main() {
    int soda;
    cout << "Please choose a soda, you can choose between: " << endl;
    cout << "1: Cola" << endl;
    cout << "2: Fanta" << endl;
    cout << "3: Juice" << endl;
    cin >> soda;

    switch(soda){
        case 1:
            cout << "Cola" << endl;
            break;
        case 2:
            cout << "Fanta" << endl;
            break;
        case 3:
            cout << "Juice" << endl;
            break;
        default:
            cout << "Please choose between 1-3" << endl;
            break;
    }
    return 0;
}
