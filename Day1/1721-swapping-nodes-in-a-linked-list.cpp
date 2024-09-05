/*
link -> https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/
*/

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while(temp)
        {
            count++;
            temp = temp->next;
        }
        int first = k;
        int last = count-k;
        temp = head;
        ListNode* temp2 = head;
        first--;
        while(first--)
        {
            temp = temp->next;
        }
        while(last--)
        {
            temp2 = temp2->next;
        }
        swap(temp->val,temp2->val);
        return head;
    }
};
