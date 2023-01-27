/**
 * ~ Problem 2 ~
 * Write a program that outputs every even number from 2 to 100
 */

#include <iostream>
using namespace std;

// Constant variables
const int MAX_LOOP_COUNT = 100;
const int STARTING_LOOP_POS = 2;
const int MOD_CHECKER = 2;

int main() {
    for (int i = STARTING_LOOP_POS; i <= MAX_LOOP_COUNT; i++) {
        if (i % MOD_CHECKER == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}