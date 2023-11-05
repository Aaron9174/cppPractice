
/**
 * Section 9 - Challenge
 * ------------------------------------------------------------------------------------------------------
 * Description
 *
 * This challenge is about using a list of integers and allowing the user to select options from a menu
 * to perform operations on the list.
 *
 * Your program should display a menu of options to the user as follows:
 *
 * P - Print numbers
 * A - Add a number
 * M - Display mean of the number
 * S - Display the smallest number
 * L - Display the largest number
 * Q - Quit
 *
 * Enter your choice:
 *
 * ------------------------------------------------------------------------------------------------------
 * Additional Notes:
 * - Only accept valid choices (uppers and lowers allowed)
 * - Illegal choices should display "Unknown selection, please try again"
 *      - Menu options should display afterwards
 *
 * Option 'P'
 * - If list is empty 'P' should display "[] - the list is empty"
 * - If the list is not empty, the list should be displayed with brackets [1 2 3 4 5]
 *
 * Option 'A'
 * - Prompt user to add number to the list: "Input a number to add to the list: "
 * - Should display "X added" where X is a valid integer
 * - Duplicates are allowed
 *
 * Option 'M'
 * - If empty, display "Unable to calculate mean - no data"
 *
 * Option 'S'
 * - Should display "The smallest number is X" where X is a valid integer
 * - If empty, display "Unable to determine the smallest number - list is empty"
 *
 * Option 'L'
 * - Should display "The largest number is X" where X is a valid integer
 * - If empty, display "Unable to determine the largest number - list is empty"
 *
 * Option 'Q'
 * - Should display "Goodbye"
 *
 *
 * ------------------------------------------------------------------------------------------------------
 */

#include <iostream>

// Program defined constants
// const std::string ADD_NUMBERS = "Aa";
// const std::string DISPLAY_LARGEST = "Ll";
// const std::string DISPLAY_MEAN = "Mm";
// const std::string DISPLAY_SMALLEST = "Ss";
// const std::string PRINT_LIST = "Pp";
// const std::string QUIT = "Qq";
// const std::string VALID_MAIN_MENU_SELECTIONS = "AaLlMmSsPpQk";

enum MenuSelections
{
    ADD_NUMBERS = "Aa",
    DISPLAY_LARGEST = "Ll",
    DISPLAY_MEAN = "Mm",
    DISPLAY_SMALLEST = "Ss",
    PRINT_LIST = "Pp",
    QUIT = "Qq",
    INVALID = "I",
};

/***********************************************************************************************************/
/***********************************************************************************************************/
void displayMainMenu()
{
    std::string mainMenu = "P - Print numbers \n"
                           "A - Add a number \n"
                           "M - Display mean of the number \n"
                           "S - Display the smallest number \n"
                           "L - Display the largest number \n"
                           "Q - Quit ";
    std::cout << mainMenu << std::endl;
}

/***********************************************************************************************************/
/***********************************************************************************************************/
MenuSelections getMainMenuSelection(std::string selection)
{
    switch (selection)
    {
    case to_underlying(MenuSelections::ADD_NUMBERS) == selection:
        return MenuSelections::ADD_NUMBERS;
    case to_underlying(MenuSelections::DISPLAY_LARGEST) == selection:
        return MenuSelections::DISPLAY_LARGEST;
    case to_underlying(MenuSelections::DISPLAY_MEAN) == selection:
        return MenuSelections::DISPLAY_MEAN;
    case to_underlying(MenuSelections::DISPLAY_SMALLEST) == selection:
        return MenuSelections::DISPLAY_SMALLEST;
    case to_underlying(MenuSelections::PRINT_LIST) == selection:
        return MenuSelections::PRINT_LIST;
    case to_underlying(MenuSelections::QUIT) == selection:
        return MenuSelections::QUIT;
    default:
        std::cout << "Unknown selection, please try again" << std::endl;
        return MenuSelections::INVALID;
    }
}

/***********************************************************************************************************/
/***********************************************************************************************************/
std::string getRawUserSelection()
{
    std::cout << "Enter your choice: ";
    std::string userSelection;
    std::cin >> userSelection;
    return userSelection;
}

/***********************************************************************************************************/
/***********************************************************************************************************/
bool handleQuit(MenuSelections selection)
{
    if (selection == MenuSelections::QUIT)
    {
        std::cout << "Goodbye" << std::endl;
        return true;
    }
    return false;
}

/***********************************************************************************************************/
/***********************************************************************************************************/
void handleSelection(std::string menuSelection)
{
    switch (menuSelection)
    {
    case MenuSelections::ADD_NUMBERS:
        break;
    case MenuSelections::DISPLAY_LARGEST:
        break;
    case MenuSelections::DISPLAY_MEAN:
        break;
    case MenuSelections::DISPLAY_SMALLEST:
        break;
    case MenuSelections::PRINT_LIST:
        break;
    default:
        std::cout << "Unknown selection, please try again" << std::endl;
    }
}

/***********************************************************************************************************/
/***********************************************************************************************************/
int runListProgram()
{

    while (true)
    {
        displayMainMenu();

        const std::string rawMenuSelection = getRawUserSelection();
        const MenuSelections selection = getMainMenuSelection(rawMenuSelection);
        if (selection == MenuSelections::INVALID)
        {
            continue;
        }

        if (handleQuit(menuSelection))
        {
            break;
        }
    }

    return 0;
}

/***********************************************************************************************************/
/***********************************************************************************************************/
int main()
{
    return runListProgram();
}
