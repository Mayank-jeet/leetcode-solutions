/*
 * LeetCode: 611 - Valid Triangle Number
 * Link: https://leetcode.com/problems/rotate-arrayvalid-triangle-number/
 * Difficulty: Medium
 * Time: O(nlog(n)) for sorting + O(n^2) for two pointers
 * Space: sO(1)
 */ 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3) return 0;
        sort(nums.begin(),nums.end());
        int ans=0,n=nums.size();
        for(int k=n-1;k>=2;k--){
            int i=0,j=k-1;
            while(j>i){
                int sum=nums[i]+nums[j];
                if(sum<=nums[k]){
                    i++;
                }else{
                    ans+=(j-i);
                    j--;
                }
            }
        }
        return ans;
    }
};