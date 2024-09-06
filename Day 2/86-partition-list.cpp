/*
link -> https://leetcode.com/problems/partition-list/

Approach:
Create Two Lists: Initialize two dummy nodes, before and after, to store nodes less than x and nodes greater than or equal to x, respectively.

Traverse Original List: Iterate through the original list, comparing each node's value with x.

If the node's value is less than x, append it to the before list.
If the node's value is greater than or equal to x, append it to the after list.
Terminate Lists: Ensure both the before and after lists end with NULL.

Concatenate Lists: Connect the end of the before list to the head of the after list.

Return the Partitioned List: Return the head of the before list, which now contains the partitioned nodes.
*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* before = new ListNode(0);
        ListNode* after = new ListNode(0);
        ListNode* tb = before;
        ListNode* ta = after;
        while(head)
        {
            if(head->val < x)
            {
                tb->next = head;
                tb = tb->next;
                head = head->next;
                tb->next = NULL;
                
            }
            else{
                ta->next = head;
                ta = ta->next;
                head = head->next;
                ta->next = NULL;
            }
        }
        tb->next = after->next;
        return before->next;
    }
};
