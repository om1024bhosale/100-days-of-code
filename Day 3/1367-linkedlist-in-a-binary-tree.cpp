/*
link -> https://leetcode.com/problems/linked-list-in-binary-tree/?envType=daily-question&envId=2024-09-07

Approach:
1. Divide the Problem:
Separate the task into two main parts:
checks if the linked list matches a path starting from a specific node in the tree (matchfunction)
and
another that traverses the tree (dfsfunction).
2. Match Function:
This function match checks if the linked list starting from the current head node matches a path starting from the current root node of the tree.
3. Base cases:
If head is NULL, it means we've successfully matched all nodes in the linked list, so return true.
If root is NULL, it means the tree path ended before the linked list, so return false.
If root->val does not match head−>val, return false since the values don't match.
4. Recursive cases:
Recursively check both the left and right subtrees to see if either can match the next node in the linked list head−>next.
5. DFS Function:
This function dfs traverses the binary tree to initiate the matching process from each node.
6. Base cases:
Check if the path starting from the current root matches the linked list using the match function.
If a match is found, return true.
Otherwise, continue the search in the left and right subtrees.
7. isSubPath Function:
This function isSubPath initiates the depth-first search from the root of the binary tree.
*/

class Solution {
public:
    bool match(TreeNode* root, ListNode* head)
    {
        if(!head )return 1;
        if(!root) return 0;
        else if(root->val!=head->val) return 0;

        return match(root->left,head->next) || match(root->right, head->next);
        
    }

    bool dfs(TreeNode* root, ListNode* head)
    {
        if(!root) return 0;
        if(match(root,head)) return 1;
        return dfs(root->left,head) || dfs(root->right,head);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(root,head);
    }
};
