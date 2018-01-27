#include <iostream>
using namespace std;

int main(){
    int score;
    cout << "Please enter your grade: ";
    cin >> score;
    
    if (score == 100) {
        cout << "PERFECT SCORE" << endl;
    }
    
    else if (score > 90) {
        cout << "You're graded A" << endl;
    }

    else if (score > 80) {
        cout << "You're graded B" << endl;
    }

    else if (score > 70) {
        cout << "You're graded C" << endl;
    }

    else if (score > 60) {
        cout << "Your're graded D" << endl;
    }
    
    else {
        cout << "Your're graded F" << endl;
    }
    
    return 0;
}
