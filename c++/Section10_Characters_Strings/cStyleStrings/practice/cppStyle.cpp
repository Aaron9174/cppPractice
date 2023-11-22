#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1;
    string s2{"Aaron"};
    string s3{s2};
    string s4{"Aaron", 3};
    string s5{s3, 0, 2};
    string s6(3, 'A');

    cout << "s1 output: " << s1 << endl; // Empty
    cout << "s2 output: " << s2 << endl; // Aaron
    cout << "s3 output: " << s3 << endl; // Aaron
    cout << "s4 output: " << s4 << endl; // Aar
    cout << "s5 output: " << s5 << endl; // Aa
    cout << "s6 output: " << s6 << endl; // AAA

    string s7;
    s7 = "C++ Rocks!";
    string s8{"Hello"};
    s8 = s7;
    cout << "s7 output: " << s7 << endl; // C++ Rocks!
    cout << "s8 output: " << s8 << endl; // "C++ Rocks!"

    string part1{"C++"};
    string part2{"is a powerful"};
    string sentence;
    sentence = part1 + " " + part2 + " language!";
    cout << "sentence output: " << sentence << endl; // "C++ is a powerful language!"
    // Below is ILLEGAL, two c++ string literals are c-style strings and can't use these operators
    // sentence = "C++" + " is powerful";

    string s9{"Aaron"};
    cout << "s9[0] output: " << s9[0] << endl;       // A
    cout << "s9.at(0) output: " << s9.at(0) << endl; // A
    s9[0] = 'a';                                     // aaron
    s9.at(0) = 'k';                                  // karon

    string s10{"Aaron"};
    for (char c : s10)
        cout << c << endl; // Prints each character on a new line
    for (int c : s10)
        cout << c << endl; // Prints each integer that represents that character on a new line

    string s11{"Apple"};
    string s12{"Banana"};
    string s13{"Kiwi"};
    string s14{"apple"};
    string s15{s11};
    cout << "s11 equals s15 is " << (s11 == s15) << endl;         // True
    cout << "s11 equals s12 is " << (s11 == s12) << endl;         // False
    cout << "s11 does not equal s12 is " << (s11 != s12) << endl; // True
    cout << "s11 is less than s12 is " << (s11 < s12) << endl;    // True
    cout << "s12 is greater than s11 is " << (s12 > s11) << endl; // True
    cout << "s14 is less than s15 is " << (s14 < s15) << endl;    // False
    cout << "s11 equals \"Apple\" " << (s11 == "Apple") << endl;  // True

    // object.substr(start_index, length)
    string s16{"This is a test"};
    cout << "s16 output: " << s16 << endl;                                          // This
    cout << "s16 first 4 characters: " << s16.substr(0, 4) << endl;                 // This
    cout << "s16 2 characters after the 5th index: " << s16.substr(5, 2) << endl;   // is
    cout << "s16 4 characters after the 10th index: " << s16.substr(10, 4) << endl; // test

    // object.find(search_string)
    string s17{"This is a test"};
    cout << "s17 \"this\" is at index: " << s17.find("This") << endl; // 0
    cout << "s17 \"is\" is at index: " << s17.find("is") << endl;     // 2
    cout << "s17 \"test\" is at index: " << s17.find("test") << endl; // 10
    cout << "s17 \"e\" is at index: " << s17.find("e") << endl;       // 11
    cout << "s17 \"is\" is at index: " << s17.find("is", 4) << endl;  // 5
    cout << "s17 \"XX\" is at index: " << s17.find("XX") << endl;     // string::npos

    string s18{"Aaron"};
    cout << "s18 length output: " << s18.length() << endl; // 5
    s18 += " Hebson";
    cout << "s18 addition output: " << s18 << endl; // Aaron Hebson

    // TODO: investigate this section
    string s19;
    cout << "Please enter: \"Hello there\"" << endl;
    cin >> s19;                                                // User input: Hello there
    cout << "s19 extraction operator output: " << s19 << endl; // Only accepts up to the first white space!
    cout << "Please enter: \"Hello there\"" << endl;
    getline(cin, s19);                                      // User input: read entire line until \n
    cout << "s19 getline operator output: " << s19 << endl; // Hello there
    cout << "Please enter: \"HelloxThere\"" << endl;
    cin >> s19;             // User input: Hello there
    getline(cin, s19, 'x'); // User input: read until 'x' delimiter is hit

    // Concatenation
    string s20 = "Watermelon";
    cout << "\nConcatenation"
         << "\n-----------------------------------" << endl;
    cout << "s20: " << s20 << endl; // Apple and Banana juice
    s20 = s11 + " and " + s12 + " juice";
    cout << "s20 is now: " << s20 << endl; // Apple and Banana juice
    // s20 = "nice" + " cold" + s11 + "juice" // Compiler error due to string literals

    // for loop through string
    // s1 = "Apple";

    return 0;
};