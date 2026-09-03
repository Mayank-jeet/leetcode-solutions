/*
 * LeetCode: 3876 - Construct Uniform Parity Array II
 * Link: https://leetcode.com/problems/construct-uniform-parity-array-ii/
 * Difficulty: Medium
 * Time: O(n*√m) where n is size of input vector and m is maximum element is input vector
 * Space: O(k) where k is number of distinct elements in input vector
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallestOdd=INT_MAX;
        bool odd=true,even=true;
        for(int el:nums1){
            if(el%2==1) smallestOdd=min(smallestOdd,el);
        }
        for (int el:nums1){
            if(el%2==0){
                if(smallestOdd>=el) odd=false;
            }
            else{
                if(smallestOdd>=el) even=false;
            }
        }
        return odd || even;
    }
};