/*
 * LeetCode: 3969 - Valid Subarrays With Matching Sum Digits I
 * Link: https://leetcode.com/problems/valid-subarrays-with-matching-sum-digits-i/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            long long sum=0,p=1;
            int first=0,last=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                last=sum%10;
                if(sum/(p*10)!=0){
                    while(sum/(p*10)!=0) p*=10;
                }
                first=sum/p;
                if(first==x && last==x) ans++;
            }
        }
        return ans;
    }
};