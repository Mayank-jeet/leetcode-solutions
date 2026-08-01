/*
 * LeetCode: 1482 - Minimum Number of Days to Make m Bouquets
 * Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
 * Difficulty: Medium
 * Time: O(nlog(m)) where n is the number of elements in the array and m is the maximum element in the array
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int isPossible(vector<int>& bloomDay,int day,int k){
        int n=bloomDay.size(),count=0,sum=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=day) sum++;
            else sum=0;
            if(sum>=k){
                count++;
                sum=0;
            }
        }
        return count;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>bloomDay.size()) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end()),high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(m>isPossible(bloomDay,mid,k)) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};