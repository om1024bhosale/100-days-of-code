/*
link -> https://leetcode.com/problems/valid-parentheses/description/

Approach:

Initialize an empty stack.

Traverse the input string character by character.

If the current character is an opening bracket (i.e., '(', '{', '['), push it onto the stack.

If the current character is a closing bracket (i.e., ')', '}', ']'), check if the stack is empty. If it is empty, return false, because the closing bracket does not have a corresponding opening bracket. Otherwise, pop the top element from the stack and check if it matches the current closing bracket. If it does not match, return false, because the brackets are not valid.

After traversing the entire input string, if the stack is empty, return true, because all opening brackets have been matched with their corresponding closing brackets. Otherwise, return false, because some opening brackets have not been matched with their corresponding closing brackets.

*/

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(inti i=0;i<s.size();i++)
        {
            if(st.empty()) st.push(s[i]);
            else
            {
                if(!st.empty()||s[i]=='('||s[i]=='['||s[i]=='{')
                {
                    st.push(s[i]);
                }
                else
                {
                    if(st.empty()||(s[i]==')'&&st.top()=='(')
                    ||(s[i]==))
                }
            }
        }
    }
};
