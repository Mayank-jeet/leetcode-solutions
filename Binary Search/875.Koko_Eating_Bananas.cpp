/*
 * LeetCode: 875 - Koko Eating Bananas
 * Link: https://leetcode.com/problems/koko-eating-bananas/
 * Difficulty: Medium
 * Time: O(nlog(m)) where n is the number of elements in the array and m is the maximum element in the array
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long time(vector<int>& piles,int mid){
        long long count=0;
        for(int el:piles) count+=((long long)el + mid - 1) / mid;
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high=*max_element(piles.begin(),piles.end());
        int low=1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(time(piles,mid)<=h) high=mid-1;
            else low=mid+1; 
        }
        return low;
    }
};