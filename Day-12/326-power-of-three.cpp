/*
link -> https://leetcode.com/problems/power-of-three/

Approach:
It's a pretty straightforward question. You can get it just by seeing the code.
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        while(n)
        {
            if(n%3 && n!=1) return false;
            n = n/3;
        }
        return true;
    }
};

// Method 2:

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1) return true;
        if(n<=0 || n%3) return false;
        return isPowerOfThree(n/3);
    }
};
