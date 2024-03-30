#include <vector>
#include <stdint.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<uint32_t> twoSum(vector<uint32_t>& nums, uint32_t target) {
        for (uint32_t i = 0; i < nums.size(); i++)
        {
            for (uint32_t j = 0; j < nums.size(); j++)
            {
                uint32_t sum = nums.at(i) + nums.at(j);
                if (sum == target)
                {
                    return vector<uint32_t>({i, j});
                }
            }
        }
        return vector<uint32_t>();
    };
};

int main()
{
    Solution solution;
    vector<uint32_t> numbers = {1, 2, 3, 4};
    uint32_t target = 5;
    vector<uint32_t> solutionSet = solution.twoSum(numbers, target);
    for (const uint32_t num : solutionSet)
    {
        cout << num << endl;   
    }
}