/*
 * LeetCode: 1031 - Maximum Sum of Two Non-Overlapping Subarrays
 * Link: https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
 * Difficulty: Medium
 * Time: O(n) for the sliding window approach
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calSum(vector<int>& nums,int len,int start){
        int sum=0;
        for(int i=start;i<start+len;i++) sum+=nums[i];
        return sum;
    }
    int findAns(vector<int>& nums,int& firstLen,int& secondLen){
        int leftSum=calSum(nums,firstLen,0);
        int rightSum=calSum(nums,secondLen,firstLen);
        int first=firstLen,second=firstLen+secondLen,n=nums.size(),maxSum=leftSum;
        int ans=leftSum+rightSum;
        for(int i=0;second<n;i++){
            rightSum-=nums[first];
            rightSum+=nums[second];
            leftSum-=nums[i];
            leftSum+=nums[first];
            maxSum=max(maxSum,leftSum);
            ans=max(maxSum+rightSum,ans);
            first++;
            second++;
        }
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(findAns(nums,firstLen,secondLen),findAns(nums,secondLen,firstLen));
    }
};