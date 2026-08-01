/*
 * LeetCode: 540 - Single Element in a Sorted Array
 * Link: https://leetcode.com/problems/single-element-in-a-sorted-array/
 * Difficulty: Medium
 * Time: O(log(n)) where n is the number of elements in the array
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1 || nums[0]!=nums[1]) return nums[0];
        else if(nums[nums.size()-1]!=nums[nums.size()-2]) return nums[nums.size()-1];
        int low=1,high=nums.size()-2;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==nums[mid+1] || nums[mid]==nums[mid-1]){
                if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2!=0 && nums[mid]==nums[mid-1])) low=mid+1;
                else high=mid-1;
            }else return nums[mid];
        }
        return -1;
    }
};