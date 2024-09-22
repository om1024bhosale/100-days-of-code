/*
link -> https://leetcode.com/problems/reverse-string/description/

Approach:
Take 2 pointers start and end. As the meaning suggest, start = 0 and  end = s.size()-1.
The two pointers will be there until start is less than end
Just swap start and elements we will get our answer
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start=0, end = s.size()-1;
        while(start<end)
        {
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
};
