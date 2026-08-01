/*
 * LeetCode: 2064 - Minimized Maximum of Products Distributed to Any Store
 * Link: https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/
 * Difficulty: Medium
 * Time: O(nlog(m)) where n is the number of elements in the array and m is the maximum element in the array
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& quantities,int n, int maxEl){
        long long dist=0;
        for(int el:quantities){
            dist+=static_cast<long long> (((el-1)/maxEl)+1);
            if(dist>n) return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1;
        int high=*max_element(quantities.begin(),quantities.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(quantities,n,mid)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};