#include <iostream>
using namespace std;

int main() {
	string input;

	cout << "Please enter your name: " << endl;
	getline(cin, input);
	cout << "Hello, " << input << " welcome to class!" << endl;

	return 0;
}
