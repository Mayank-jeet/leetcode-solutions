/*
 * LeetCode: 238 - Product of Array Except Self
 * Link: https://leetcode.com/problems/product-of-array-except-self/
 * Difficulty: Medium
 * Time: O(n) where n size of the input vector
 * Space: O(n) considerig space used for ans vector
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int prod=1;
        ans[0]=1;
        for(int i=1;i<n;i++){
            prod*=nums[i-1];
            ans[i]=prod;
        }
        prod=1;
        for(int i=n-2;i>=0;i--){
            prod*=nums[i+1];
            ans[i]*=prod;
        }
        return ans;
    }
};