/**
 * ~ Assignment 3 ~
 * Enter the value for one edge of a cube and calculate:
 * 1) The surface area of the cube
 * 2) The volume of the cube
 * Then, print both of these values
 */

#include <iostream>
using namespace std;

int main() {
    // Constants
    const char enterNumQueryMsg[] = "Please enter a number that represents one side of the cube: ";
    const int TOTAL_SIDES_OF_CUBE = 6;

    double cubeSide;
    double surfaceArea;
    double volume;

    // Get user input
    cout << enterNumQueryMsg;
    cin >> cubeSide;
    cout << endl;

    // Equation for the surface area of a cube
    surfaceArea = TOTAL_SIDES_OF_CUBE * (cubeSide * cubeSide);
    // Equation for the volume of a cube
    volume = cubeSide * cubeSide * cubeSide;

    cout << "The surface area of the cube is " << surfaceArea << " and the volume is " << volume << endl;
}