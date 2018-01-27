#include <iostream>
using namespace std;

int main() {
    int iter = 0;
    int input;
    bool keep_asking = true;

    cout << "Welcome to a little game, all you have to do is not type 5";
    cout << endl;

    do {
        if (iter == 10) {
            cout << "Time's up maan" << endl;
            return 0;
        }

        cout << "Choose any number but " << iter << endl;
        cin >> input;

        if (input == iter) {
            cout << "You werent supposed to choose " << iter << "!" << endl;
            keep_asking = false;
        }

        iter++;
    } while(keep_asking);

    return 0;
}
