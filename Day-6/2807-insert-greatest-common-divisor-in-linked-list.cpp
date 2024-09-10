/*
link -> https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/?envType=daily-question&envId=2024-09-10

Approach:
It's a very easy question.
In this, first take two pointers first is curr on head->next and prev on head.
Now take a function of gcd and pass the values of curr->val and prev->val to that function which will return the gcd of two no.
After create a new node with value == gcd
and add in between of curr and prev now point prev = curr and move curr to next node.
Edge case for a LL with one node just return the head

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
int gcd(int a, int b)  
{  
   
    if (a == 0)  
       return b; 
    if (b == 0)
       return a;
     
    if (a == b)  
        return a; 
    
   
    if (a > b)  
    return gcd(a-b, b);  

    return gcd(a, b-a);   
}  
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next) return head;
        ListNode* curr = head->next;
        ListNode* prev = head;

        while(curr)
        {
            int gcdno = gcd(curr->val,prev->val);
            ListNode* node = new ListNode(gcdno);
            node->next = curr;
            prev->next = node;
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};
