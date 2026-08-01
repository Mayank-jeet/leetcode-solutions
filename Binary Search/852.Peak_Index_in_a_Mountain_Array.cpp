/*
 * LeetCode: 852 - Peak Index in a Mountain Array
 * Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/
 * Difficulty: Medium
 * Time: O(log(n))
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0,high=arr.size()-1,n=arr.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid>0 && mid<n && (arr[mid]>arr[mid-1]) && (arr[mid]>arr[mid+1])) return mid;
            else if(mid==0 || (arr[mid]<arr[mid+1])) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
};