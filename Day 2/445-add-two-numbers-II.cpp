/*
link -> https://leetcode.com/problems/add-two-numbers-ii/

Approach:
Use Stacks for Reversal: Push all digits from both linked lists into two stacks (s1 and s2). This allows us to process the digits from least significant to most significant.

Add Digits: Initialize a carry variable and iterate while either stack is not empty. Pop digits from the stacks, add them along with the carry, and create a new node for the digit's unit place of the sum.

Manage Carry: Update the carry for the next iteration. If there's a carry left after processing both stacks, add a new node for it.

Build Result List: Construct the result list in reverse order using a temporary pointer.

Return Result: Return the head of the result linked list.
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
        stack<int> s1, s2;

        while (l1) {
            s1.push(l1 -> val);
            l1 = l1 -> next;
        }

        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        int totalSum = 0;
        ListNode *ans = new ListNode();
        ListNode *temp = NULL;

        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                totalSum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                totalSum += s2.top();
                s2.pop();
            }
            carry = totalSum / 10;
            ListNode* newHead = new ListNode(totalSum % 10);
            newHead -> next = temp;
            temp = newHead;
            totalSum = carry;
        }

        if (carry) {
            ListNode* newHead = new ListNode(carry);
            newHead->next = temp;
            temp = newHead;
        }
        return temp;
    }
};
