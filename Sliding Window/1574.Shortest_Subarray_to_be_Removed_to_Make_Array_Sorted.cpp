/*
 * LeetCode: 1574 - Shortest Subarray to be Removed to Make Array Sorted
 * Link: https://leetcode.com/shortest-subarray-to-be-removed-to-make-array-sorted/
 * Difficulty: Medium
 * Time: O(n) where n is the size of input vector
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int ans=1,last=n-1;
        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1]) ans++;
            else {
                last=i-1;
                break;
            }
        }
        if(last==n-1) return n-ans;
        for(int i=n-1;i>=0;i--){
            if(last>=0 && arr[last]>arr[i]){
                while(last>=0 && arr[last]>arr[i]) last--;
            }
            if(i+1<n && arr[i]>arr[i+1]) break;
            ans=max(ans,last+n-i+1);
        }
        return n-ans;
    }
};