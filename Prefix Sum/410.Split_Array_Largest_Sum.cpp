/*
 * LeetCode: 410 - Split Array Largest Sum
 * Link: https://leetcode.com/problems/split-array-largest-sum/
 * Difficulty: Hard
 * Time: O(n*log(high-low)) where high is the sum of all elements in the input vector and low is the maximum element in the input vector
 * Space: O(1)
 */ 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& nums,int maxSum, int k){
        int n=nums.size(),count=0,sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]+sum>maxSum){
                sum=0;
                count++;
            }
            if(count>=k) return false;
            sum+=nums[i];
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(nums,mid,k)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};