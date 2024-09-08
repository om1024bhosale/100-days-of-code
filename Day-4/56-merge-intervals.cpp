/*
link -> https://leetcode.com/problems/merge-intervals/

Approach:

Sort the Intervals: Sort the intervals based on their starting points to ensure overlapping intervals are adjacent.

Initialize Result: Add the first interval to the result list (ans) and set a variable temp to track the end of the last merged interval.

Iterate and Merge:

For each subsequent interval, check if it overlaps with the last merged interval (i.e., if the current start is less than or equal to temp).
If overlapping, update temp to the maximum end between the intervals and update the last interval in ans.
If no overlap, add the current interval to ans and update temp to the end of this new interval.
Return Result: After processing all intervals, return the merged intervals stored in ans.
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int temp = intervals[0][1];
        for(int i = 1;i<n;i++){
            if(temp >= intervals[i][0])
            {
                temp = max(intervals[i][1],temp);
                ans.back()[1] = temp;
            }
            else{
                ans.push_back(intervals[i]);
                temp = intervals[i][1];
            }
        }
        return ans;
    }
};
