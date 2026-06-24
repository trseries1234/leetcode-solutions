/*
 * Problem: Longest Substring Without Repeating Characters
 * Problem ID: 3
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 11 MB
 * Synced From: LeetCode
 * Date: 2026-06-24
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Array to store the last seen index of each ASCII character (initialized to -1)
        vector<int> last_seen(128, -1);
        
        int max_len = 0;
        int left = 0; // Left boundary of the sliding window
        
        for (int right = 0; right < s.length(); ++right) {
            char current_char = s[right];
            
            // If the character was seen before and is inside the current window
            if (last_seen[current_char] >= left) {
                // Move the left boundary right past the previous occurrence
                left = last_seen[current_char] + 1;
            }
            
            // Update the last seen position of the character
            last_seen[current_char] = right;
            
            // Calculate the current window size and update max_len
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};
