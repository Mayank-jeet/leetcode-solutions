/*
 * LeetCode: 1877 - Minimize Maximum Pair Sum in Array
 * Link: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
 * Difficulty: Medium
 * Time: O(nlogn)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int first=0,last=nums.size()-1;
        int ans=-1,pairSum=0;
        while(first<last){
            pairSum=nums[first]+nums[last];
            if(ans<pairSum) ans=pairSum;
            first++;
            last--;
        }
        return ans;
    }
};