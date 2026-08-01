/*
 * LeetCode: 2594 - Minimum Time to Repair Cars
 * Link: https://leetcode.com/problems/minimum-time-to-repair-cars/
 * Difficulty: Medium
 * Time: O(nlog(maxEl-minEl)) where n is the number of elements in the array and maxEl and minEl are the minEl*cars*cars and minimum elements in the array
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(long long& maxTime,vector<int>& ranks,int& cars){
        int done=0;
        for(int rank:ranks){
            done+=sqrt(maxTime/rank);
            if(done>=cars) return true;
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int minEl=*min_element(ranks.begin(),ranks.end());
        long long low=minEl,high=(long long)minEl*cars*cars;
        while(low<high){
            long long mid=(low+high)/2;
            if(check(mid,ranks,cars)) high=mid;
            else low=mid+1;
        }
        return low;
    }
};