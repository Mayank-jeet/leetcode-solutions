/*
 * LeetCode: 33 - Search in Rotated Sorted Array
 * Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
 * Difficulty: Medium
 * Time: O(log(n))
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return mid;
            else if(target>nums[mid]){
                if(nums[mid]<=nums[low]){
                    if(nums[high]>=target) low=mid+1;
                    else high=mid-1;
                }
                else low=mid+1;
            }
            else if(target<nums[mid]){
                if(nums[mid]>=nums[low]){
                    if(nums[low]<=target) high=mid-1;
                    else low=mid+1;
                }
                else high=mid-1;
            }
        }
        return -1;
    }
};