/*
 * LeetCode: 81 - Search in Rotated Sorted Array II
 * Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
 * Difficulty: Medium
 * Time: O(log(n))
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return true;
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                high--;
                low++;
            }else if(nums[low]<=nums[mid]){
                if(nums[low]<=target && nums[mid]>target) high=mid-1;
                else low=mid+1;
            }else{
                if(nums[mid]<target && target<=nums[high]) low=mid+1;
                else high=mid-1;
            }
        }
        return false;
    }
};