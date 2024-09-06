/*
link -> https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/?envType=daily-question&envId=2024-09-06
Appraoch:
In order to remove the nodes from the linked list efficiently, we can use a hashset or boolean array (like I did in Java) to improve the lookup time to check if each value in the linked list is in the array nums.

We can define a hashset or boolean array s and add all the values from nums into it. Then we need two pointers prev and curr (representing the previous and current node respectively) to itearte through the linked list so that we can properly change the pointers for nodes that point to deleted nodes.

While going through the linked list, if the current node's value is in our set s, we change the previous node's next pointer to point to the node after the current node, (i.e prev.next = curr.next). If prev is still NULL that means it's the head of the linked list, so we simply set curr and head equal to head.next to update both nodes. Otherwise if the current node's value is not in our set, we advance both prev and curr by setting prev equal to curr and curr equal to curr.next.

Complexity
Time complexity: O(n+m)
Space complexity: O(n)
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>s (nums.begin(),nums.end()); // Adding nums to hashset
        ListNode* prev = NULL, *curr = head;
        while(curr)
        {
            if(s.count(curr->val))
            {
                if(!prev){// Curr is at first node
                curr = head= head->next;
                } 
                else{// set link prev to curr and move curr to next node
                prev->next = curr = curr->next;
                }
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
