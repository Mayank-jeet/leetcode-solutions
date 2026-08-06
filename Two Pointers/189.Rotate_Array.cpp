/*
 * LeetCode: 189 - Rotate Array
 * Link: https://leetcode.com/problems/rotate-array/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(n) considering the output array, otherwise O(1)
 */ 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n);
        k%=n;
        for(int i=0;i<n;i++){
            int index=(n-k+i)%n;
            ans[i]=nums[index];
        }
        nums=ans;
    }
};