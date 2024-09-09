/*
link -> https://leetcode.com/problems/reverse-integer/description/

Appraoch:
1. Take a long long ans and run a loop until our given no becomes 0;
2. In while loop first find reamainder and update our ans as ans = x*10+rem and make x to x/10;
3.Handle the edge cases.
4. at last convert ans into integer.
*/

class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while(x!=0){
            int rem = x%10;
            ans= ans*10+rem;
            x/=10;
        }
        if(ans>INT_MAX||ans<INT_MIN){
            return 0;
        }
        return (int)ans;
    }
};
