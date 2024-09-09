/*
link -> https://leetcode.com/problems/spiral-matrix-iv/?envType=daily-question&envId=2024-09-09

Approach
Start by initializing the m x n matrix with all values set to -1, which will serve as a placeholder for any unfilled spaces.
Use four pointers (top, bottom, left, right) to define the current boundaries of the matrix. These will shrink as we move inward in a spiral pattern.
Traverse the matrix in four steps:
Move left to right along the top boundary.
Move top to bottom along the right boundary.
Move right to left along the bottom boundary.
Move bottom to top along the left boundary.
After each traversal, update the respective boundary pointers to move closer to the center of the matrix.
As the values from the linked list are inserted into the matrix, advance the pointer to the next node.
If the linked list is fully processed before the matrix is completely filled, leave the remaining cells as -1.
Return the filled matrix.
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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        int left = 0, top=0,right = n-1, bottom = m-1;
        
        while(head && top<=bottom && left<=right)
        {
            for(int i=left;i<=right && head;i++)
            {
                ans[top][i] = head->val;
                head = head->next;
            }
            top++;

            for(int i = top;i<=bottom && head;i++)
            {
                ans[i][right] = head->val;
                head = head->next;
            }
            right--;

            for(int i=right;i>=left && head;i--)
            {
                ans[bottom][i] = head->val;
                head = head->next;
            }
            bottom--;
            for(int i=bottom;i>=top && head;i--)
            {
                ans[i][left] = head->val;
                head = head->next;
            }
            left++;
        }
        return ans;
    }
};
