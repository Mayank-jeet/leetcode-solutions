/*
 * LeetCode: 1685 - Sum of Absolute Differences in a Sorted Array
 * Link: https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
 * Difficulty: Medium
 * Time: O(n) where n size of the input vector
 * Space: O(n) considering space used by output vector, otherwise O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            sum+=(nums[i]-nums[0]);
        }
        vector<int> ans;
        ans.push_back(sum);
        int i=1;
        int step=n-2;
        while(step>=1){
            int diff=nums[i]-nums[i-1];
            ans.push_back(ans.back()-diff*step);
            step-=2;
            i++;
        }
        if(step==-1) step=1;
        else step=0;
        while(i!=n){
            int diff=nums[i]-nums[i-1];
            ans.push_back(ans.back()+diff*step);
            step+=2;
            i++;
        }
        return ans;
    }
};