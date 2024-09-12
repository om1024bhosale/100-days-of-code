/*
link -> https://leetcode.com/problems/count-the-number-of-consistent-strings/?envType=daily-question&envId=2024-09-12

Approach
Create a set of char type elements and put all characters of the string allowed in the set.
Create a counter variable cnt and initialise it with value 0.
Now, traverse through the words vector and inside the for loop you need to define a boolean variable isconsistent with initial value true.
Now traverse through each character of the current word of the words vector and check whether that character is present in set or not.
If any character of any word is not present in set then we will not increment the cnt else we will.
Finally, return cnt.
*/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> st(allowed.begin(), allowed.end());
        int cnt=0;
        for(int i=0; i<words.size(); ++i){
            bool isconsistent=true;
            for(auto x: words[i]){
                if(st.find(x)==st.end()){
                    isconsistent=false;
                    break;
                }
            }
            cnt+=isconsistent;
        }
        return cnt;
    }
};
