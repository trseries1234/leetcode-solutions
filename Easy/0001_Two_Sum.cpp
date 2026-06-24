/*
 * Problem: Two Sum
 * Problem ID: 1
 * Difficulty: Easy
 * Language: C++
 * Runtime: 2 ms
 * Memory: 14.9 MB
 * Synced From: LeetCode
 * Date: 2026-06-24
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i};
            }
            
            num_map[nums[i]] = i;
        }
        
        return {};
    }
};
