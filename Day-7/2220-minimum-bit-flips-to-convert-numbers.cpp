/*
link -> https://leetcode.com/problems/minimum-bit-flips-to-convert-number/?envType=daily-question&envId=2024-09-11

Approach:
XOR the two numbers: Perform a bitwise XOR between start and goal. The result will have 1 in positions where the bits are different between the two numbers.
Count the number of 1s in the XOR result: This tells us the number of positions where the bits differ and hence the number of bit flips required.
Bit counting: Use a loop to repeatedly check the last bit of the XOR result using & 1. Right shift the XOR result (>> 1) to process the next bit. Continue until all bits are processed.
*/

class Solution {
public:
    int minBitFlips(int start, int goal) {
        if(start==goal) return 0;
        int ans = 0;
        int xorres = start ^ goal;

        while(xorres)
        {
            ans+=xorres & 1;
            xorres>>=1;
        }
        return ans;
    }
};
