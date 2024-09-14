/*
link ->https://leetcode.com/problems/palindrome-number/description/

1) Negative Number Check:

The function first checks if 𝑥 is negative or if 𝑥 ends with a zero (but is not zero itself). If either condition is true, the number is not a palindrome.
2) Reversing Half the Number:

The function then reverses the second half of the number and compares it to the first half. This is done by initializing a reversed variable to 0 and then iteratively appending the last digit of 𝑥 to reversed while removing the last digit from 𝑥.
3) Comparison:

Finally, the function checks if the first half of 𝑥 is equal to reversed or if the first half of 𝑥 is equal to reversed / 10. The second comparison accounts for the case where the number has an odd number of digits.
*/

class Solution {
    public boolean isPalindrome(int x) {
        int num = 0;
        int temp = x;
        while(x>0){
            int rem = x%10;
            num = num*10+rem;
            x=x/10;
        }
        if(num==temp){
            return true;
        }
        else{
            return false;
        }
    }
}
