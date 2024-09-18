/*
link -> https://leetcode.com/problems/search-insert-position/description/

Approach
Initialization:
Define the initial low pointer as 0.
Define the initial high pointer as the length of the array.
Edge Cases:
If the target is greater than the last element in the array, return high (which is the size of the array).
If the target is less than the first element in the array, return low (which is 0).
Binary Search:
Use a while loop to perform binary search (low <= high).
Calculate the mid index as the average of low and high.
If the element at the mid index is equal to the target, return mid.
If the target is less than the element at the mid index, move the high pointer to mid - 1.
If the target is greater than the element at the mid index, move the low pointer to mid + 1.
If the loop ends without finding the target, return low as the position where the target should be inserted.
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1,mid=0,ans=nums.size();
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target)
            {
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};
