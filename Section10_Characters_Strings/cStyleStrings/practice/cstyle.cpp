#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
    char firstName[20]{};
    char lastName[20]{};
    char fullName[50]{};
    char temp[50]{};

    // cout << firstName; // Should display garbage

    // cout << "-------------------------" << endl;
    // cout << "Please enter your first name: ";
    // cin >> firstName;

    // cout << "Please enter your last name: ";
    // cin >> lastName;
    // cout << "-------------------------" << endl;

    // cout << "Hello, " << firstName << " your first name has " << strlen(firstName) << " characters" << endl;
    // cout << "and your last name, " << lastName << " has " << strlen(lastName) << " characters" << endl;
    // cout << "-------------------------" << endl;

    // strcpy(fullName, firstName);
    // strcat(fullName, " ");
    // strcat(fullName, lastName);
    // cout << "Your full name is " << fullName << endl;
    // cout << "-------------------------" << endl;

    // cout << "Enter your full name: ";
    // cin >> fullName;
    // cout << "Your full name is " << fullName << endl;
    // cout << "-------------------------" << endl;

    cout << "Enter your full name: ";
    cin.getline(fullName, 50);
    cout << "Your full name is " << fullName << endl;
    cout << "-------------------------" << endl;

    strcpy(temp, fullName);
    if (strcmp(temp, fullName) == 0)
        cout << temp << " and " << fullName << " are the same" << endl;
    else
        cout << temp << " and " << fullName << " are different" << endl;
    cout << "-------------------------" << endl;

    for (size_t i{0}; i < strlen(fullName); ++i)
    {
        if (isalpha(fullName[i]))
            fullName[i] = toupper(fullName[i]);
    }
    cout << "Your full name is " << fullName << endl;

    cout << "-------------------------" << endl;
    if (strcmp(temp, fullName) == 0)
        cout << temp << " and " << fullName << " are the same" << endl;
    else
        cout << temp << " and " << fullName << " are different" << endl;

    cout << "-------------------------" << endl;
    cout << "Result of comparing " << temp << " and " << fullName << ": " << strcmp(temp, fullName) << endl;
    cout << "Result of comparing " << fullName << " and " << temp << ": " << strcmp(fullName, temp) << endl;
}