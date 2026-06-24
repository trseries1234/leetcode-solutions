/*
 * Problem: Zigzag Conversion
 * Problem ID: 6
 * Difficulty: Medium
 * Language: C++
 * Runtime: 4 ms
 * Memory: 13.9 MB
 * Synced From: LeetCode
 * Date: 2026-06-24
 */

class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case: if only 1 row is requested or the string is too short, no change is needed
        if (numRows <= 1 || s.length() <= numRows) {
            return s;
        }
        
        // Create an array of strings for each row
        vector<string> rows(min(numRows, (int)s.length()));
        
        int current_row = 0;
        bool going_down = false; // Flag to track the direction of movement
        
        for (char c : s) {
            rows[current_row] += c;
            
            // Reverse direction if we hit the top or bottom row
            if (current_row == 0 || current_row == numRows - 1) {
                going_down = !going_down;
            }
            
            // Move to the next row based on the current direction
            current_row += going_down ? 1 : -1;
        }
        
        // Combine all rows into a single string
        string result = "";
        for (const string& row : rows) {
            result += row;
        }
        
        return result;
    }
};
