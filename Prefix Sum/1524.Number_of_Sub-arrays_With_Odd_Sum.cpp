/*
 * LeetCode: 1524 - Number of Sub-arrays With Odd Sum
 * Link: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(1) 
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int oddCount=0,evenCount=0;
        int n=arr.size(),sum=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum%2==0){
                evenCount++;
                ans+=(long long)oddCount;
            }else{
                oddCount++;
                ans+=(long long)(evenCount+1);
            }
            ans%=1000000007;
        }
        return ans;
    }
};