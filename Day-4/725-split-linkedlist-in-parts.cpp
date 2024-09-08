/*
link -> https://leetcode.com/problems/split-linked-list-in-parts/description/?envType=daily-question&envId=2024-09-08

Approach:

Calculate the Size of the Linked List:

Traverse the linked list and count the total number of nodes (size).
Determine the Split Sizes:

Each part will have a minimum size of size // k.
There may be some leftover nodes (size % k) which need to be distributed to the first few parts. Therefore, the first size % k parts will have an extra node.
Splitting the List into Parts:

Initialize a ListNode[] ans of size k to store the resulting parts.
For each part, calculate its size. For the first size % k parts, the size will be splitSize + 1. For the remaining parts, the size will be splitSize.
For each part, traverse the corresponding number of nodes, and then break the list by setting the next pointer of the last node in the current part to null.
Continue this process for all parts and assign the heads of each part to ans[i].
Return the Result:

Return the array ans which contains the heads of the k parts.

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
        vector<ListNode*>ans(k,NULL);
        ListNode* temp = head;
        while(temp)
        {
            size++;
            temp = temp->next;
        }
        
        int nodes = size/k;
        int remaining = size%k;

        ListNode* curr = head;
        ListNode* prev = NULL;

        for(int i=0; curr && i<k;i++)
        {
            ans[i] = curr;
            for(int j=0;j<nodes;j++)
            {
                prev = curr;
                curr = curr->next;
            }
            if(remaining>0)
            {
                prev = curr;
                curr= curr->next;
                remaining--;
            }
            prev->next = NULL;
        }

        return ans;
        
    }
};
