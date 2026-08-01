/*
 * LeetCode: 1760 - Minimum Limit of Balls in a Bag
 * Link: https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
 * Difficulty: Medium
 * Time: O(nlog(m)) where n is the number of elements in the array and m is the maximum element in the array
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums, int& maxOperations,int& maxEl){
        int operation=0;
        for(int el:nums){
            if(el<=maxEl) continue;
            else operation+=(el-1)/maxEl;
            if(operation>maxOperations) return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<high){
            int mid=low+(high-low)/2;
            if(check(nums,maxOperations,mid)) high=mid;
            else low=mid+1;
        }
        return low;
    }
};