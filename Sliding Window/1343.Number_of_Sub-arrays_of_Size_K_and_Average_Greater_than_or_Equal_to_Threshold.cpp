/*
 * LeetCode: 1343 - Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
 * Link: https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
 * Difficulty: Medium
 * Time: O(n) for the sliding window approach
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum=0,ans=0,n=arr.size();
        for(int i=0;i<k;i++) sum+=arr[i];
        int lastEl=0,i=k-1;
        do{
            i++;
            if((sum/k)>=threshold) ans++;
            sum-=arr[lastEl];
            lastEl++;
            if(i<n) sum+=arr[i];
        }while(i<n);
        return ans;
    }
};