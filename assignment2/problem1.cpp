/**
 * ~ Problem 1 ~
 * 1) Accept two numbers from the user
 * 2) Display one of the following messages:
 *      - First is larger
 *      - Second is larger
 *      - Numbers are equal
 */

#include <iostream>
using namespace std;

int main() {
    // Displayable messages
    const char firstIsLargerMsg[] = "First is larger";
    const char secondIsLargerMsg[] = "Second is larger";
    const char numAreEqlMsg[] = "Numbers are equal";
    const char headerMsg[] = "~ Number Comparison ~";
    const char firstNumQueryMsg[] = "Type the first number: ";
    const char secondNumQueryMsg[] = "Type the second number: ";

    // Declare variables for user input
    float number1;
    float number2;

    // Querying and getting user input
    cout << headerMsg << endl;
    cout << firstNumQueryMsg << endl;
    cin >> number1;
    cout << secondNumQueryMsg << endl;
    cin >> number2;

    // Comparison and displaying of messages
    if (number1 > number2) {
        cout << firstIsLargerMsg << endl;
    } else if (number1 < number2) {
        cout << secondIsLargerMsg << endl;
    } else {
        cout << numAreEqlMsg << endl;
    }
}
