#include <iostream>

using namespace std;

// This is impossible, since case cannot be ranges, but rather have to be 
// defined constants. In this case I'd have to create a function to figure
// out which case this is. Which would defeat the purpose of switch()
int main() {
    int score;
    cout << "What is your score: " << endl;
    cin >> score;

    switch(score){
        case (score == 100):
            cout << "PERFECT" << endl;
            break;
        case (score > 90):
            cout << "A" << endl;
            break;
        case (score > 80):
            cout << "B" << endl;
            break;
        case (score > 70):
            cout << "C" << endl;
            break;
        case (score > 60):
            cout << "D" << endl;
            break;
        default:
            cout << "F" << endl;
    }
    
    return 0;
}
