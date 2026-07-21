/*
 * Problem: Maximize Active Section with Trade I
 * Problem ID: 3805
 * Difficulty: Medium
 * Language: C++
 * Runtime: 179 ms
 * Memory: 176.1 MB
 * Synced From: LeetCode
 * Date: 2026-07-21
 */

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (char c : s)
            if (c == '1') ones++;

        string t = "1" + s + "1";

        vector<pair<char, int>> runs;
        int i = 0, m = t.size();

        while (i < m) {
            int j = i;
            while (j < m && t[j] == t[i]) j++;
            runs.push_back({t[i], j - i});
            i = j;
        }

        int maxZero = 0;
        for (auto &r : runs)
            if (r.first == '0')
                maxZero = max(maxZero, r.second);

        int ans = ones;

        // Internal 1-runs only (surrounded by 0-runs)
        for (int k = 1; k + 1 < (int)runs.size(); k++) {
            if (runs[k].first != '1') continue;

            int oneLen = runs[k].second;
            int leftZero = runs[k - 1].second;
            int rightZero = runs[k + 1].second;

            // Fill the merged zero block
            ans = max(ans, ones + leftZero + rightZero);

            // Fill some other existing zero block
            ans = max(ans, ones - oneLen + maxZero);
        }

        return ans;
    }
};