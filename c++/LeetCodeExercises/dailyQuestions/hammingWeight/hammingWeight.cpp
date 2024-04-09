#include "stdio.h"
#include <iostream>

class Solution
{
public:
    int hammingWeight(int n)
    {
        int count = 0;
        while (n) // Break when the number zero's out
        {
            // This adds either 0 or 1 depending on the least significant bit result of n
            count += n & 1;
            // Bit shift n to get the next bit value of n
            n >>= 1;
        }
        return count;
    };
};

void displayAnswer(std::pair<int, int> &exampleSet, int answer)
{
    std::cout << "Number of bits in " << exampleSet.first << " is " << answer << ". The answer is " << exampleSet.second << std::endl;
}

int main()
{
    Solution solution;

    std::pair<int, int> exampleSolutionPair = {11, 3};
    int answer = solution.hammingWeight(exampleSolutionPair.first);
    displayAnswer(exampleSolutionPair, answer);

    exampleSolutionPair = {128, 1};
    answer = solution.hammingWeight(exampleSolutionPair.first);
    displayAnswer(exampleSolutionPair, answer);

    exampleSolutionPair = {2147483645, 30};
    answer = solution.hammingWeight(exampleSolutionPair.first);
    displayAnswer(exampleSolutionPair, answer);
}