/*
 * LeetCode: 1477 - Find Two Non-overlapping Sub-arrays Each With Target Sum
 * Link: https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
 * Difficulty: Medium
 * Time: O(n) where n is size of input vector
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int res=n+1,tot=0,i=0;
        vector<int> dp(n+1,n);
        for(int j=0;j<n;j++){
            tot+=arr[j];
            while(tot>target){
                tot-=arr[i];
                i+=1;
            }
            dp[j+1]=dp[j];
            if (tot==target){
                int Len=j-i+1;
                res=min(res,Len+dp[i]);
                dp[j+1]=min(dp[j],Len); 
            }
        }       
        if(res==n+1) return -1;
        return res;
    }
};