/*
link -> https://leetcode.com/problems/copy-list-with-random-pointer/description/

*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        //creating a copy nodes in between the two nodes
        while(temp)
        {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = temp->next->next;
        }

        //pointng the random pointers of copy nodes.
        temp = head;
        while(temp)
        {
            if(temp->random)
            {
                temp->next->random = temp->random->next;
            }
            else
            {
                temp->next->random = NULL;
            }
            temp = temp->next->next;
        }
        //removing old list pointers from new list pointers

        temp = head;
        Node* dummy = new Node(0);
        Node* ans = dummy;
        while(temp)
        {
            ans->next = temp->next;
            ans = ans->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};
