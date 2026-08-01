/*
 * LeetCode: 153 - Find Minimum in Rotated Sorted Array
 * Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 * Difficulty: Medium
 * Time: O(log(n))
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int ans=0;
        while(low<=high){
            int middle=low+(high-low)/2;
            if(nums[middle]<nums[ans]) ans=middle;
            if(nums[middle]<nums[high]){
                high=middle-1;
            }else{
                low=middle+1;
            }
        }
        return nums[ans];
    }
};