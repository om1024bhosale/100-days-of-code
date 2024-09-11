/*
link -> https://leetcode.com/problems/two-sum/description/

Approach:
The approach is pretty straightforward check for the sum of every numbers from first to last if their sum matches the target return their indices.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; 
    }
};
