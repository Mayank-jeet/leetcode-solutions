/*
 * LeetCode: 1283 - Find the Smallest Divisor Given a Threshold
 * Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
 * Difficulty: Medium
 * Time: O(nlog(m)) where n is the number of elements in the array and m is the maximum element in the array
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& nums, int threshold,int div){
        long long sum=0;
        for(int el:nums){
            sum+=static_cast<long long>((el-1)/div+1);
            if(sum>threshold) return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(nums,threshold,mid)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};