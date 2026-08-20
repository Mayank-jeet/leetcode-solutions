/*
 * LeetCode: 719 - Find K-th Smallest Pair Distance
 * Link: https://leetcode.com/problems/find-k-th-smallest-pair-distance/
 * Difficulty: Hard
 * Time: O(nlog(max))+O(nlog(n)) where n is the size of input vector, and max is the maximum possible difference in input vector
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int max=nums[n-1]-nums[0],min=0;
        while(min<max){
            int mid=min+(max-min)/2;
            int last=0,count=0;
            for(int i=0;i<n;i++){
                if(nums[i]-nums[last]>mid){
                    while(last<i && nums[i]-nums[last]>mid) last++;
                }
                count+=i-last;
            }
            if(count>=k) max=mid;
            else min=mid+1;    
        }
        return max;
    }
};