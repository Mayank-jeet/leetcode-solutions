/*
 * LeetCode: 1471 - The k Strongest Values in an Array
 * Link: https://leetcode.com/problems/the-k-strongest-values-in-an-array/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(n) for storing the answer otherwise O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        if(arr.size()==1) return arr;
        sort(arr.begin(),arr.end());
        int n=arr.size(),m=(n-1)/2;
        int last=n-1,first=0,middle=arr[m];
        vector<int> ans;
        while(ans.size()<k && last>m && first<m){
            if((arr[last]-middle)>=(middle-arr[first])){
                ans.push_back(arr[last]);
                last--;
            }else{
                ans.push_back(arr[first]);
                first++;
            }
        }
        if(ans.size()<k && last>m){
            while(ans.size()<k) {
                ans.push_back(arr[last]);
                last--;
            }
        }else if(ans.size()<k && first<m){
            while(ans.size()<k) {
                ans.push_back(arr[first]);
                first++;
            }
        }
        return ans;
    }
};