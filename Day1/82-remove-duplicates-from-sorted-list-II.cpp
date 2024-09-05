/*
link -> https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* curr = head;
        ListNode* dummy = new ListNode(0,head);
        ListNode* prev = dummy;

        while(curr)
        {
            if(curr->next && curr->val==curr->next->val)
            {
                while(curr->next && curr->val==curr->next->val)
                {
                    curr = curr->next;
                }
                prev->next = curr->next;
            }
            else{
                prev = curr;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};
