#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct person {
    int number;
    int pancakes_eaten;
};

//void write_vec(const vector<person>& vec){
    //for (vector<char>::const_iterator iter = vec.begin();
        //iter != vec.end(); ++iter){
        //cout << *iter << ' ';
    //}
//}

bool has_eaten_more(const person x, const person y){
    return x.pancakes_eaten > y.pancakes_eaten;
}

void clearscr() {
    for (int i = 0; i < 100; i++) {
        cout << "\n\n";
    }
}

int main() {
    vector<person> people;

    for (int i = 1; i <= 5; i++){
        int input;
        cout << "How many pancakes has person " << i << " eaten?" << endl;
        cout << "Enter number of pancakes: ";
        cin >> input;

        person p = {i, input};
        people.push_back(p);
    }

    sort(people.begin(), people.end(), has_eaten_more);

    // Clear screen
    clearscr();
    
    for(int i = 0; i < people.size(); i++){
        cout << "Person: " << people[i].number << endl;
        cout << "Pancakes eaten: " << people[i].pancakes_eaten << endl;
        cout << endl; 
    }
}
