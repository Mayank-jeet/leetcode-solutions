/*
 * LeetCode: 2517 - Maximum Tastiness of Candy Basket
 * Link: https://leetcode.com/problems/maximum-tastiness-of-candy-basket/
 * Difficulty: Medium
 * Time: O(nlog(m)) where n is the number of elements in the array and m is the maximum element in the array
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& price,int minDiff,int k){
        int lastIndex=0,count=1,n=price.size();
        for(int i=1;i<n;i++){
            if(price[i]-price[lastIndex]>=minDiff){
                count++;
                lastIndex=i;
            }
            if(count>=k) return true;
        }
        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int low=0,high=price[price.size()-1]-price[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(price,mid,k)) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};