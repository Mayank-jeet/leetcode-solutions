/*
 * LeetCode: 1011 - Capacity To Ship Packages Within D Days
 * Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
 * Difficulty: Medium
 * Time: O(nlog(m)) where n is the number of elements in the array and m is the maximum element in the array
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool ifPossible(vector<int>& weights,int maxSum,int days){
        int n=weights.size(),sum=0,count=0;
        for(int i=0;i<n;i++){
            if(weights[i]+sum>maxSum){
                sum=0;
                count++;
            }
            if(count>=days) return false;
            sum+=weights[i];
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ifPossible(weights,mid,days)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};