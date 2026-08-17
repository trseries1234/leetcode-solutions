/*
 * Problem: Longest Palindromic Substring
 * Problem ID: 5
 * Difficulty: Medium
 * Language: C++
 * Runtime: 4 ms
 * Memory: 9.4 MB
 * Synced From: LeetCode
 * Date: 2026-08-17
 */

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int maxLength = 1;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            // Case 1: Odd length palindromes (e.g., "aba", center is 'b')
            int low = i - 1;
            int high = i + 1;
            while (low >= 0 && high < n && s[low] == s[high]) {
                if (high - low + 1 > maxLength) {
                    start = low;
                    maxLength = high - low + 1;
                }
                low--;
                high++;
            }
            
            // Case 2: Even length palindromes (e.g., "abba", center is between 'b' and 'b')
            low = i;
            high = i + 1;
            while (low >= 0 && high < n && s[low] == s[high]) {
                if (high - low + 1 > maxLength) {
                    start = low;
                    maxLength = high - low + 1;
                }
                low--;
                high++;
            }
        }
        
        return s.substr(start, maxLength);
    }
};
