/*
 * LeetCode: 658 - Find K Closest Elements
 * Link: https://leetcode.com/problems/find-k-closest-elements/
 * Difficulty: Medium
 * Time: O(nlog(n)) (for sorting ans vector) else O(n)
 * Space: O(1) or O(n) is we consider the space used for storing ans
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int index=n-1;
        for(int i=0;i<n;i++){
            if(arr[i]>=x) {
                index=i;
                break;
            }
        }
        vector<int> ans;
        int left=index-1,right=index;
        while(ans.size()<k && left!=-1 && right!=n){
            int leftAbs=x-arr[left];
            int rightAbs=arr[right]-x;
            if(leftAbs<=rightAbs) {
                ans.emplace_back(arr[left]);
                left--;
            }else {
                ans.emplace_back(arr[right]);
                right++;
            }
        }
        if(ans.size()<k && left==-1){
            while(ans.size()<k){
                ans.emplace_back(arr[right]);
                right++;
            }
        }else if(ans.size()<k && right==n){
            while(ans.size()<k){
                ans.emplace_back(arr[left]);
                left--;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};