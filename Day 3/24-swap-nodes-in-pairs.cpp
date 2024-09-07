/*
link -> https://leetcode.com/problems/swap-nodes-in-pairs/

Approach:
1. Take two pointers curr and prev.
  Point curr = head->next and prev = head

2. Take a while loop which will run until curr!=NULL.
3. Swap the values of curr and prev.
4. After swapping check for curr->next if exists make prev =  curr->next and curr =  curr->next;
  After that we have to make curr to curr->next for proper swapping.
5. Edge cases heandle:
  Handle for head==NULL and head->next==NULL.
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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* curr = head->next;
        ListNode* prev = head;
        while(curr)
        {
            swap(curr->val,prev->val);
            if(curr->next){
                prev = curr->next;
                curr = curr->next;
            }
            curr = curr->next;

        }
        return head;
    }
};
