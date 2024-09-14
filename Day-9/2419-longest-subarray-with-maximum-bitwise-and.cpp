/*
link ->https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/

Find the Maximum Element: First, we find the maximum value in the array, which will help us identify which subarrays can potentially have the maximum bitwise AND.

Traverse the Array:

Start from the first element and find contiguous subarrays where each element is equal to the maximum value.
Keep track of the longest subarray that contains this maximum value.
Return the Length of the Longest Subarray: Finally, return the length of the longest subarray where all elements equal the maximum value.
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int maxi = *max_element(nums.begin(),nums.end());
        int ans = 1;
        int count = 0;
        int i = 0;
        while(i < nums.size())
        {
            if(nums[i] == maxi)
            {
                while(i < nums.size() and nums[i++] ==maxi) count++;
                ans = max(ans,count);
                count = 0;
            }
            else i++;
        }
        return ans;
    }
};
