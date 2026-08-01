/*
 * LeetCode: 154 - Find Minimum in Rotated Sorted Array II
 * Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
 * Difficulty: Hard
 * Time: O(log(n)) where n is the number of elements in the array
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<nums[high]) high=mid;
            else if(nums[mid]>nums[high]) low=mid+1;
            else high--;
        }
        return nums[low];
    }
};