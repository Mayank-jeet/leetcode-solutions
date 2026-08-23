/*
 * LeetCode: 4032 - Longest Subarray With at Most K Distinct Prime Factors
 * Link: https://leetcode.com/longest-subarray-with-at-most-k-distinct-prime-factors/
 * Difficulty: Medium
 * Time: O(n*√m) where n is size of input vector and m is maximum element is input vector
 * Space: O(k) where k is number of distinct elements in input vector
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void primeFactors(int el,int& size,unordered_map<int,int>& u_map) {
        for(int i=2;i*i<=el;i++) {
            while(el%i==0){
                u_map[i]++;
                if(u_map[i]==1) size++;
                el/=i;
            }
        }
        if(el>1){
            u_map[el]++;
            if(u_map[el]==1) size++;
        }
    }
    void delOccurance(int el,int& size,unordered_map<int,int>& u_map){
        for(int i=2;i*i<=el;i++) {
            while(el%i==0){
                u_map[i]--;
                if(u_map[i]==0) size--;
                el/=i;
            }
        }
        if(el>1){
            u_map[el]--;
            if(u_map[el]==0) size--;
        }
    }
    int longestSubarray(vector<int>& nums, int k) {
        int lower=0,ans=0,size=0;
        int n=nums.size();
        unordered_map<int,int> u_map;
        for(int i=0;i<n;i++){
            primeFactors(nums[i],size,u_map);
            if(size>k){
                while(size>k && lower<=i){
                    delOccurance(nums[lower],size,u_map);
                    lower++;
                }
            }
            if(size<=k) ans=max(ans,i-lower+1);
        }
        return ans;
    }
};