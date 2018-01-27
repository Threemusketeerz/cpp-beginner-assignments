#include <iostream>
#include <string>
using namespace std;

int calc_guess(int high, int low){
    return (high - low)/2 + low;
}

int main(){
    int tries = 0;
    int guess = 0;
    int high = 100;
    int low = 0;
    int initial_answ;
    bool keep_playing = true;

    cout << "Let's play a game." << endl;
    cout << "All you have to do is choose a number between 1-100." << endl;
    cout << "Since this is obviously math, the programme will know if you're cheating." << endl;
    cout << "The only catch is you have to tell be if I guessed too high or too low." << endl;
    cout << "You do this by typing 0 for low, ";
    cout << "and 1 for too high. I'll know if you don't u fucker, ";
    cout << "as the young kids say nowadays" << endl;

    cout << "Now you little bitch, write a number down" << endl;

    // initial try
    if(tries == 0){
        cout << "I'll start with a generic number." << endl;
        cout << "Is the number you chose 50?" << endl;
        cout << "2 if 50 is correct, 1 for too high, 0 for too low" << endl;
        cin >> initial_answ;
        cout << endl;
        switch(initial_answ){
            case 0:
                low = 50;
                break;
            case 1:
                high = 50;
                break;
            case 2:
                return 0;
                break;

            default:
                cout << "Think i'm stupid? IM A COMPUTER FFS, be reasonable." << endl;
                break;
        }
    }
    
    while(keep_playing == true) {
        int input;
        string answer;
        if(tries == 7){
            cout << "Your number can only be: " << guess << endl;
            return guess;
            keep_playing = false;
        }

        // DEN MOEDER DET HER FOERST
        guess = calc_guess(high, low);
        cout << "Is your number " << guess << "?" << endl;
        cout << "2 for correct answer;\n1 for too high;\n0 for too low;" << endl;
        cin >> input;
        switch(input){
            case 0:
                low = guess;
                break;
            case 1:
                high = guess;
                break;
            case 2:
                keep_playing = false;
                cout << "YOUR NUMBER IS: " << guess << endl;
                return guess;
            default:
                cout << "Think i'm stupid? IM A COMPUTER FFS, be reasonable." << endl;
                break;
        }
        tries++;
    }
    return 0;
}
