/*
link -> https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
*/

class Solution {
public:
    void reorderList(ListNode* head) {
       vector<int>arr;
       ListNode* temp = head;
       while(temp)
       {
        arr.push_back(temp->val);
        temp = temp->next;
       }
       int start = 0,end = arr.size()-1;
       temp = head;
       while(start<end)
       {
        temp->val = arr[start];
        temp = temp->next;
        temp->val = arr[end];
        start++;
        end--;
        temp = temp->next;
       }
       if(arr.size()%2) temp->val = arr[start];
       

    }
};
