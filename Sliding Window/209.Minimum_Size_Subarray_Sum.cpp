/*
 * LeetCode: 209 - Minimum Size Subarray Sum
 * Link: https://leetcode.com/problems/minimum-size-subarray-sum/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=0,total=0,leftSum=0;
        int n=nums.size(),i=0,j=-1;
        while(i<n){
            total+=nums[i];
            if((total-leftSum)>=target){
                while((j+1)<i && (total-(leftSum+nums[j+1]))>=target){
                    j++;
                    leftSum+=nums[j];
                }
                if(ans==0) ans=i-j;
                else ans=min(ans,i-j);
            }
            i++;
        }
        return ans;
    }
};