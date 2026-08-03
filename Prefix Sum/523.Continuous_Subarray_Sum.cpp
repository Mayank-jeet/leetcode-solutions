/*
 * LeetCode: 523 - Continuous Subarray Sum
 * Link: https://leetcode.com/problems/continuous-subarray-sum/
 * Difficulty: Medium
 * Time: O(n) where n size of the input vector
 * Space: O(n) space used for unordered_map
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<2) return false;
        unordered_map<int,int> u_map={{0,-1}};
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;
            if(u_map.count(rem)!=0){
                if(i-u_map[rem]>1) return true; 
            }else  u_map[rem]=i;
        }
        return false;
    }
};