/*
 * Problem: Add Two Numbers
 * Problem ID: 2
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 77.3 MB
 * Synced From: LeetCode
 * Date: 2026-06-24
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); // Dummy node to anchor the result list
        ListNode* tail = &dummy; // Pointer to track the last node in the result list
        int carry = 0;
        
        // Loop runs as long as there are digits left in l1 or l2, OR a remaining carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10; // Calculate new carry (either 0 or 1)
            
            // Create a new node with the current digit (sum % 10) and attach it
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }
        
        return dummy.next; // Return the head of the actual result list
    }
};
