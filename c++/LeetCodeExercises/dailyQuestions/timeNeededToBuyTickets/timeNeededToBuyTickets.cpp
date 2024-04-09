#include "stdio.h"
#include <vector>
#include <iostream>

class Solution
{
public:
    void debugDisplayArray(std::vector<int> &tickets)
    {
        std::cout << "[ ";
        for (const int ticket : tickets)
        {
            std::cout << ticket << " ";
        }
        std::cout << "]" << std::endl;
    }

    /**
     * My solution is good on memory, but not so good on efficiency
     */
    int timeRequiredToBuy(std::vector<int> &tickets, int k)
    {
        int seconds = 0;
        size_t i = 0;
        while (true)
        {
            i %= tickets.size();
            if (tickets.at(i) > 0)
            {
                tickets.at(i)--;
                seconds++;
            }

            if (tickets.at(k) == 0)
            {
                return seconds;
            }

            i++;
        }
    };

    /**
     * Solution answer
     */
    int timeRequiredToBuyAnswer(std::vector<int> &tickets, int k)
    {
        int res = 0, target = tickets[k];
        // Parsing the queue up to k, included
        for (int i = 0; i <= k; i++)
        {
            // Get minimum between the current value and target
            res += std::min(tickets[i], target);
        }
        // Parsing the queue up from k, excluded
        target--;
        for (int i = k + 1, lmt = tickets.size(); i < lmt; i++)
        {
            // Getting the minimum between the current value and target
            res += std::min(tickets[i], target);
        }
        return res;
    }
};

void displaySolution(int seconds, int k)
{
    std::cout << "The number of seconds for the " << k << "th person in line to buy all of their tickets is " << seconds << std::endl;
}

int main()
{
    Solution solution;

    std::vector<int> tickets = {2, 3, 2};
    int k = 2;
    int answer = 0;

    answer = solution.timeRequiredToBuy(tickets, k);
    displaySolution(answer, k);

    tickets = {5, 1, 1, 1};
    k = 0;
    answer = solution.timeRequiredToBuy(tickets, k);
    displaySolution(answer, k);

    tickets = {5, 3, 2, 1};
    k = 2;
    answer = solution.timeRequiredToBuy(tickets, k);
    displaySolution(answer, k);
}
