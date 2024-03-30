#include <vector>
#include <stdint.h>
#include <iostream>
using namespace std;
/**
 * DESCRIPTION
 *******************************************************************************************************************************
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 *******************************************************************************************************************************
 * EXAMPLE 1
 *******************************************************************************************************************************
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 *******************************************************************************************************************************
 * EXAMPLE 2
 *******************************************************************************************************************************
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 *******************************************************************************************************************************
 * EXAMPLE 3
 *******************************************************************************************************************************
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 *******************************************************************************************************************************
 * Input: nums = [3,3], target = 6
 *******************************************************************************************************************************
 * CONSTRAINTS
 *******************************************************************************************************************************
 * 2 <= nums.length <= 104
 * -109 <= nums[i] <= 109
 * -109 <= target <= 109
 * Only one valid answer exists.
 * Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?  
 *******************************************************************************************************************************
*/

class Solution {
public:
    vector<uint32_t> twoSum(vector<uint32_t>& nums, uint32_t target) {
        for (uint32_t i = 0; i < nums.size(); i++)
        {
            for (uint32_t j = i+1; j < nums.size(); j++)
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

void displayAnswer(vector<uint32_t> answer)
{
    cout << "[";
    for (uint32_t i = 0; i < answer.size(); i++)
    {
        if (i < answer.size() - 1)
        {
            cout << answer.at(i) << ",";
        }
        else
        {
            cout << answer.at(i) << "]" << endl;
        }
    }
}

int main()
{
    Solution solution;
    
    // Example 1
    vector<uint32_t> ex1ProblemSet = {2,7,11,15};
    uint32_t ex1Target = 9;
    vector<uint32_t> ex1SolutionSet = solution.twoSum(ex1ProblemSet, ex1Target);
    displayAnswer(ex1SolutionSet);

    // Example 2
    vector<uint32_t> ex2ProblemSet = {3, 2, 4};
    uint32_t ex2Target = 6;
    vector<uint32_t> ex2SolutionSet = solution.twoSum(ex2ProblemSet, ex2Target);
    displayAnswer(ex2SolutionSet);
    
    // Example 3
    vector<uint32_t> ex3ProblemSet = {3, 3};
    uint32_t ex3Target = 6;
    vector<uint32_t> ex3SolutionSet = solution.twoSum(ex3ProblemSet, ex3Target);
    displayAnswer(ex3SolutionSet);
}