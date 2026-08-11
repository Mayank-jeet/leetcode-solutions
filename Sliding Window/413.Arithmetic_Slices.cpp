/*
 * LeetCode: 413 - Arithmetic Slices
 * Link: https://leetcode.com/problems/arithmetic-slices/
 * Difficulty: Medium
 * Time: O(n) where n is the size of input vector
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3) return 0;
        int ans=0,length=1,n=nums.size(),diff=nums[1]-nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]==diff) length++;
            else{
                if(length>=3) ans+=(length-2)*(length-1)/2;
                length=2;
                diff=nums[i]-nums[i-1];
            }
        }
        if(length>=3) ans+=(length-2)*(length-1)/2;
        return ans;
    }
};