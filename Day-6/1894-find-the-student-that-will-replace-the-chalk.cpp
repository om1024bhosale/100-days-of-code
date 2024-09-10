/*
link -> https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
Appraoch:
We can just get the sum of all the chalk elements and mod them with the k so we get to know how many remains and update value of k as this remainder. 
Now we simple iterate the chalk array one more time this time we sure there will be no circular traversals anymore as we have already did mod previously.
In this iteration we simply do as is given in the question i.e. decrease the k value till chalk[i](index i) <= k then return i;
*/

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(int i=0;i<chalk.size();i++)
        {
            sum+=chalk[i];
        }
        k=k%sum;
        for(int i=0;i<chalk.size();i++)
        {
            if(k<chalk[i])
            {
                return i;
            }
            k-=chalk[i];
        }
        return 0;
    }
};
