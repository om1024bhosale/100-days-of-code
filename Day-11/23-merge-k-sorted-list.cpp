/*
link -> https://leetcode.com/problems/merge-k-sorted-lists/

Approach
Priority Queue Initialization:
->First, we create a custom comparator class compare that allows the priority queue to sort ListNode* based on the val in ascending order.
We then initialize a priority queue pq and push the head of each non-empty linked list into the queue.

Merging Process:
->We initialize two pointers, head and tail, which will keep track of the start and end of the merged linked list.
While the priority queue is not empty, we repeatedly extract the smallest element (the top of the priority queue), append it to the merged list, and advance the tail pointer.
If the node that was just added to the merged list has a next node, we push that next node into the priority queue. This ensures that the smallest element among the remaining nodes is always at the top of the queue.

Result:
->After the loop, the head pointer will point to the merged sorted linked list, which we return as the result.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        priority_queue<int, vector<int>, greater<int>>q;
        for(int i=0;i<lists.size();i++)
        {
            temp = lists[i];
            ListNode* temp1 = temp;
            while(temp1)
            {
                q.push(temp1->val);
                temp1 = temp1->next;
            }
        }
         temp = head;
        while(!q.empty())
        {
            ListNode* node = new ListNode(q.top());
            q.pop();
            temp->next = node;
            temp = temp->next;
        }
        return head->next;
    }
};
