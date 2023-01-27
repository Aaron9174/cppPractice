#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const char LOGIN_INPUT[] = "login";
const char NEW_INPUT[] = "new";
const char EXIT_INPUT[] = "exit";

string getUserInput() {
    string input;
    getline(cin, input);
    return input;
}

void validateRegistrationInput(string input) {
    if (input == LOGIN_INPUT || input == NEW_INPUT || input == EXIT_INPUT) {
        return;
    } else {
        throw std::invalid_argument("User must input is different than expected.");
    }
}

void displayStartingMessage() {
    cout << "Welcome to CPP Practice Registration. ";
    cout << "Would you like to login (type '" << LOGIN_INPUT <<"'), create a new account (type '" << NEW_INPUT << "'), or exit the program (type '" << EXIT_INPUT << "')?" << endl;
}

class LoginData {
    public:
        string username, password;
};
ostream& operator<<(ostream &s, const LoginData &loginData) {
    return s << "username: " << loginData.username << ", password: " << loginData.password;
}
LoginData getLoginCredentials() {
    LoginData credentials;
    cout << "Please log in." << endl;
    cout << "Enter your username: ";
    credentials.username = getUserInput();
    cout << "\nEnter your password: ";
    credentials.password = getUserInput();
    return credentials;
}

bool validateLoginCredentials(LoginData credentials) {
    ifstream fileStream;
    fileStream.open("loginCredentials.txt");

    bool validCredentials = false;
    while(true) {
        string storedUsername;
        fileStream >> storedUsername;
        cout << "stored username: " << storedUsername << endl;

        if (storedUsername.length() == 0) {
            break;
        }
        if (storedUsername == credentials.username) {
            string storedPassword;
            fileStream >> storedPassword;

            if (storedPassword == credentials.password) {
                validCredentials = true;
                break;
            }
        }
    }
    fileStream.close();
    return validCredentials;
}

void startRegistration() {
    string userInput = "";
    while (userInput != EXIT_INPUT) {
        displayStartingMessage();
        userInput = getUserInput();

        // Validates the user input
        try {
            validateRegistrationInput(userInput);
            if (userInput == LOGIN_INPUT) {
                LoginData credentials = getLoginCredentials();
                cout << credentials << endl;
                bool validCredentials = validateLoginCredentials(credentials);
                cout << "Valid credentials: " << validCredentials << endl;
            }
        } catch (std::invalid_argument& e) {
            cerr << e.what() << endl;
        }
    }
}

// Entry point
int main () {
    startRegistration();
    return 0;
}
