/*
 * LeetCode: 34 - Find First and Last Position of Element in Sorted Array
 * Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * Difficulty: Medium
 * Time: O(log(n))
 * Space: O(n) if we consider the output array, otherwise O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={-1,-1};
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(high+low)/2;
            if(nums[mid]==target){
                int big=mid;
                int small=mid;
                while(true){
                    if(big>=nums.size() && small<0) break;
                    else if(big<nums.size() && small>=0 && nums[big]!=target && nums[small]!=target) break;
                    if(big<nums.size() && nums[big]==target) ans[1]=big;
                    if(small>=0 && nums[small]==target) ans[0]=small;
                    big++;
                    small--;
                }
                return ans;
            }
            else if(target<nums[mid]) high=mid-1;
            else if(target>nums[mid]) low=mid+1;
        }
        return ans;
    }
};