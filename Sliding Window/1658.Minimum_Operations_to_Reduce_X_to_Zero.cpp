/*
 * LeetCode: 1658 - Minimum Operations to Reduce X to Zero
 * Link: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        int n=nums.size();
        int left=-1,right=n;
        for(int i=0;i<n;i++){
            if(sum>=x) break;
            sum+=nums[i];
            left++;
        }
        if(left==n-1){
            if(sum<x) return -1;
            else if(sum==x) return n;
        }
        int ans=INT_MAX;
        while(left>=0){
            if(sum>x){
                while(sum>x && left>=0){
                    sum-=nums[left];
                    left--;
                }
            }
            if(sum<x){
                while(sum<x && right>left && right>0){
                    right--;
                    sum+=nums[right];
                }
            }
            // sum of no. of elements in left and right of the window
            if(sum==x) {
                ans=min(ans,left+1+(n-right));
                if(left>=0){
                    sum-=nums[left];
                    left--;
                }
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};