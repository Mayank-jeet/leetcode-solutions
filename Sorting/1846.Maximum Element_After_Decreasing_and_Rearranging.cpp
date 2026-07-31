/*
 * LeetCode: 1846 - Maximum Element After Decreasing and Rearranging
 * Link: https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging//
 * Difficulty: Medium  
 * Time: O(nlogn)
 * Space: O(1)
 */
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        arr[0]=1;
        for(int i=1;i<n;i++){
            if((arr[i]-arr[i-1])>1)  arr[i]=arr[i-1]+1;
        }
        return arr[n-1];
    }
};