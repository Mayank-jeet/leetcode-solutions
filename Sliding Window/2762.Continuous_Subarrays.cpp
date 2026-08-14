/*
 * LeetCode: 2762 - Continuous Subarrays
 * Link: https://leetcode.com/problems/continuous-subarrays/
 * Difficulty: Medium
 * Time: O(n) where n is the size of input vector, while loop will not search all the elements from 0 to j-1, as it means that all the elements will satisfy the condition, but if that's the case then if condition will be implemented instead of else   
 * Space: O(1)
 */
// This solutution can be simplified more, using map, but that will take more space O(n) in worst case
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=1;
        int j=0,n=nums.size();
        int l=nums[0]-2,r=nums[0]+2;
        for(int i=1;i<n;i++){
            if(nums[i]>=l && nums[i]<=r){
                l=max(l,nums[i]-2);
                r=min(r,nums[i]+2);
            }else{
                j=i-1;
                l=nums[i]-2;
                r=nums[i]+2;
                while(nums[j]>=l && nums[j]<=r){
                    l=max(l,nums[j]-2);
                    r=min(r,nums[j]+2);
                    j--;
                }
                j++;
            }
            ans+=(i-j+1);
        }
        return ans;
    }
};