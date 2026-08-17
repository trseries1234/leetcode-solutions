/*
 * Problem: Two Sum
 * Problem ID: 1
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 14.8 MB
 * Synced From: LeetCode
 * Date: 2026-08-17
 */

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Maps the number value to its index
        std::unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // Check if the complement already exists in the map
            if (numMap.find(complement) != numMap.end()) {
                // Return the indices of the complement and the current number
                return {numMap[complement], i};
            }
            
            // If not found, add the current number and its index to the map
            numMap[nums[i]] = i;
        }
        
        // Return an empty vector if no solution is found (though the problem guarantees one)
        return {};
    }
};
