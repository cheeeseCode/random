#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
#include <unistd.h>
#include <vector>

int highScore(vector<int> records){
    int max = 1000;
    int length = records.size();  // Use records.size() to get the number of elements in the vector
    for(int i = 0; i < length; i++){  // Loop until i < length, not <=
        if(records[i] <= max){
            max = records[i];
        }
    }
    return max;
}

int guess(){
    srand((unsigned) time(NULL));
    int random = rand() % 100 + 1;
    int n;
    int i = 0;
    cout << "Enter a number from 1 to 100 to test your intuition or enter 0 to cancel: ";
    do {
        cin >> n;
        if(n < random && n != 0){
            cout << "Higher, try again or enter 0 to forfeit: ";
            i++;
        }
        else if(n > random){
            cout << "Lower, try again or enter 0 to forfeit: ";
            i++;
        }
        else if(n == random && n != 0){
            cout << "Correct! Your number: " << n << " matches the random number: " << random << " and you only needed: " << i << " attempts to get it right";
        }
        if(n == 0){
            cout << "You forfeited, couldn't guess a number.";
        }
    } while(n != random && n != 0);

    sleep(2);
    return i;
}

int main(){

    vector<int> records = {};  // Start with an empty vector

    // Play the first game and store the score
    int i = guess();
    records.push_back(i);

    // Print the highest score so far
    int highestnumber = highScore(records);
    cout << '\n' << "This is your highest score so far: " << highestnumber;

    bool tryAgain = true;
    char input;
    while(tryAgain){
        cout << '\n' << "Type Y if you want to play again, or type N to exit: ";
        cin >> input;
        if(input == 'y' || input == 'Y'){
            i = guess();  // Play again
            records.push_back(i);  // Add the new score to the records
            highestnumber = highScore(records);  // Update the highest score
            cout << '\n' << "This is your highest score so far: " << highestnumber;
        }
        else{
           tryAgain = false;
           return 0;
        }
    }
}
