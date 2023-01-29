#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

const char LOGIN_INPUT[] = "login";
const char NEW_INPUT[] = "new";
const char EXIT_INPUT[] = "exit";
const char CRED_FILENAME[] = "loginCredentials.txt";
const string USERNAME_PASSWORD_DELIMITER = " ";

string getUserInput() {
    string input;
    getline(cin, input);
    return input;
}

void validateRegistrationInput(string input) {
    if (input == LOGIN_INPUT || input == NEW_INPUT || input == EXIT_INPUT) {
        return;
    } else {
        throw invalid_argument("User must input is different than expected.");
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
    fileStream.open(CRED_FILENAME);

    bool validCredentials = false;
    while(true) {
        string storedUsername;
        fileStream >> storedUsername;

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
        } else {
            cout << "ignoring until next new line" << endl;
            fileStream.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    fileStream.close();
    return validCredentials;
}

void validateNewUsernameEntry(string newUsername) {
    ifstream fileStream;
    fileStream.open(CRED_FILENAME);
    while(true) {
        string storedUsername;
        fileStream >> storedUsername;

        if (storedUsername.length() == 0) {
            break;
        }

        if (storedUsername == newUsername) {
            throw invalid_argument("Username already exists.");
        }
    }

    fileStream.close();
}

void createAccount() {
    bool enterUsernameState = true;
    LoginData newCredentials;
    while(enterUsernameState) {
        cout << "Please type a username containing only letters and numbers." << endl;
        newCredentials.username = getUserInput();
        try {
            validateNewUsernameEntry(newCredentials.username);
            enterUsernameState = false;
        } catch (invalid_argument const& ex) {
            cout << ex.what() << endl;
        }
    }

    cout << "Please type in your password." << endl;
    newCredentials.password = getUserInput();

    ofstream fileStream;
    fileStream.open(CRED_FILENAME, ios::app);
    cout << "writing" << newCredentials << " to file " << CRED_FILENAME << endl;
    fileStream << newCredentials.username;
    fileStream << " ";
    fileStream << newCredentials.password;
    fileStream << "\n";
    fileStream.close();
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
                
                if (!validCredentials) {
                    cerr << "Sorry, credentials not valid. Try again." << endl;
                } else {
                    cout << "Logged in!" << endl;
                }
            } else if (userInput == NEW_INPUT) {
                createAccount();
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
