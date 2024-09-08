/*
link -> https://leetcode.com/problems/median-of-two-sorted-arrays/description/

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vect1(nums1.size() + nums2.size());
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),vect1.begin());
        int start=0,end=vect1.size()-1,mid;
        double ans;
        
        if((vect1.size())%2==0){
            mid=start+(end-start)/2;
            ans=vect1[mid]+vect1[mid+1];
            return ans/2;
        }
        else{
            mid=start+(end-start)/2;
            ans =vect1[mid];
            return ans;
        }
        ans=(vect1[0]+vect1[1])/2;
        return ans;
    }
};
