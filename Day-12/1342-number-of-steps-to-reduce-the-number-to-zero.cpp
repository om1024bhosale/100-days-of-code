/*
link -> https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/description/


*/

class Solution {
public:
    int numberOfSteps(int num) {
        int n=num;
        int count=0;
        while(n){
            if(n%2==0){
                n/=2;
            }
            else{
                n-=1;
            }
            count++;
        }
        return count;
    }
};
