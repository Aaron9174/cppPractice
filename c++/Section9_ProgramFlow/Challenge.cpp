
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
#include <map>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <numeric>

const std::string UNKNOWN_SELECTION = "Unknown selection, please try again";

enum MenuSelection
{
    ADD_NUMBERS = 0,
    DISPLAY_LARGEST = 1,
    DISPLAY_MEAN = 2,
    DISPLAY_SMALLEST = 3,
    PRINT_LIST = 4,
    QUIT = 5,
    INVALID = 6,
};

std::map<std::string, MenuSelection> MENU_SELECTION_MAP = {{"A", ADD_NUMBERS}, {"a", ADD_NUMBERS}, {"L", DISPLAY_LARGEST}, {"l", DISPLAY_LARGEST}, {"M", DISPLAY_MEAN}, {"m", DISPLAY_MEAN}, {"S", DISPLAY_SMALLEST}, {"s", DISPLAY_SMALLEST}, {"P", PRINT_LIST}, {"p", PRINT_LIST}, {"Q", QUIT}, {"q", QUIT}};

class NumberList
{
public:
    /***********************************************************************************************************/
    /***********************************************************************************************************/
    int runListProgram()
    {
        NumberList numList;
        while (true)
        {
            displayMainMenu();

            const std::string rawMenuSelection = getRawUserSelection();
            const MenuSelection menuSelection = getMainMenuSelection(rawMenuSelection);

            if (menuSelection == MenuSelection::INVALID)
                continue;

            handleSelection(menuSelection);

            bool shouldQuit = handleQuit(menuSelection);
            if (shouldQuit)
                break;
        }

        return 0;
    }

private:
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
    MenuSelection getMainMenuSelection(std::string selection)
    {
        if (MENU_SELECTION_MAP.find(selection) == MENU_SELECTION_MAP.end())
        {
            std::cout << UNKNOWN_SELECTION << std::endl;
            return MenuSelection::INVALID;
        }
        return MENU_SELECTION_MAP[selection];
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
    bool handleQuit(MenuSelection selection)
    {
        if (selection == MenuSelection::QUIT)
        {
            std::cout << "Goodbye" << std::endl;
            return true;
        }
        return false;
    }

    /***********************************************************************************************************/
    /***********************************************************************************************************/
    int getNumberInput()
    {
        std::cout << "Input a number to add to the list: " << std::endl;
        int numSelection;
        std::cin >> numSelection;
        return numSelection;
    }

    /***********************************************************************************************************/
    /***********************************************************************************************************/
    void addNumberToList(int numSelection)
    {
        if (std::cin.good())
        {
            _list.push_back(numSelection);
            std::cout << numSelection << " added" << std::endl;
        }
        else
        {
            std::cin.clear();
            std::cout << UNKNOWN_SELECTION << std::endl;
        }
    }

    /***********************************************************************************************************/
    /***********************************************************************************************************/
    void displayLargest()
    {
        if (_list.size() == 0)
        {
            std::cout << "Unable to determine the largest number - list is empty" << std::endl;
            return;
        }

        const int maxValue = *max_element(_list.begin(), _list.end());
        std::cout << "The largest number is " << maxValue << std::endl;
    }

    /***********************************************************************************************************/
    /***********************************************************************************************************/
    void displayMean()
    {
        if (_list.size() == 0)
        {
            std::cout << "Unable to calculate mean - no data" << std::endl;
            return;
        }

        const float count = static_cast<float>(_list.size());
        const float mean = std::accumulate(_list.begin(), _list.end(), 0) / count;
        std::cout << "The mean is " << mean << std::endl;
    }

    /***********************************************************************************************************/
    /***********************************************************************************************************/
    void displaySmallest()
    {
        if (_list.size() == 0)
        {
            std::cout << "Unable to determine the smallest number - list is empty" << std::endl;
            return;
        }

        const int minValue = *min_element(_list.begin(), _list.end());
        std::cout << "The smallest number is " << minValue << std::endl;
    }

    /***********************************************************************************************************/
    /***********************************************************************************************************/
    void printList()
    {
        if (_list.size() == 0)
        {
            std::cout << "[] - the list is empty" << std::endl;
            return;
        }

        std::cout << "[";
        for (auto it = _list.begin(); it != _list.end(); ++it)
        {
            if (std::distance(it, _list.end()) != 1)
                std::cout << *it << " ";
            else
                std::cout << *it;
        }
        std::cout << "]" << std::endl;
    }

    /***********************************************************************************************************/
    /***********************************************************************************************************/
    void handleSelection(MenuSelection selection)
    {
        switch (selection)
        {
        case MenuSelection::ADD_NUMBERS:
            addNumberToList(getNumberInput());
            break;
        case MenuSelection::DISPLAY_LARGEST:
            displayLargest();
            break;
        case MenuSelection::DISPLAY_MEAN:
            displayMean();
            break;
        case MenuSelection::DISPLAY_SMALLEST:
            displaySmallest();
            break;
        case MenuSelection::PRINT_LIST:
            printList();
            break;
        case MenuSelection::QUIT:
            break; // Do nothing, handled elsewhere
        default:
            std::cout << UNKNOWN_SELECTION << std::endl;
        }
    }

    /// The list of numbers
    std::vector<int> _list;
};

/***********************************************************************************************************/
/***********************************************************************************************************/
int main()
{
    NumberList numList;
    return numList.runListProgram();
}
