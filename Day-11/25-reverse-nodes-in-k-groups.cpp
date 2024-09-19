/*
link -> https://leetcode.com/problems/reverse-nodes-in-k-group/description/

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
    void reverse(ListNode* head){
        ListNode* prev = NULL, *curr = head;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
    }

    ListNode* findKthNode(ListNode* head, int k){
        int cnt = 1;
        while(cnt<k and head!=NULL){
            head = head->next;
            cnt++;
        }
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while(temp!=NULL){
            ListNode* kthNode = findKthNode(temp, k);
            if(kthNode == NULL){
                if(prevNode!=NULL) prevNode->next = temp;
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverse(temp);
            if(temp==head){
                head = kthNode;
            }
            else{
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }

        return head;
    }
};
