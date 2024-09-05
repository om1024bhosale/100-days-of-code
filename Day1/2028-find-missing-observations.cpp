/*
link -> https://leetcode.com/problems/find-missing-observations/description/

*/

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

        int sum = 0;
        int m = rolls.size();
        for(int i=0;i<m;i++)
        {
            sum+=rolls[i];
        }
        int rem = (mean*(n+m))-sum;
        if(rem>6*n || rem<n) return {};

        int remainder = rem%n;
        int q = rem/n;

        vector<int>ans(n,q);
        for(int i=0; i<remainder;i++)
        {
            ans[i]++;
        }
        return ans;
        
    }
};
