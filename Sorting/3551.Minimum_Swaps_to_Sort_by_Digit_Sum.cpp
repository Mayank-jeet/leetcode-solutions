/*
 * LeetCode: 3551 - Minimum Swaps to Sort by Digit Sum
 * Link: https://leetcode.com/minimum-swaps-to-sort-by-digit-sum/
 * Difficulty: Medium
 * Time: O(nlog(n)) where n is number of elements in input vector
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int digitSum(int el){
        int sum=0;
        while(el>0){
            sum+=el%10;
            el/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        vector<pair<int,int>> keyed;
        int n=nums.size();
        for(int el:nums){
            keyed.emplace_back(digitSum(el),el);
        }
        sort(keyed.begin(),keyed.end());
        unordered_map<int,int> u_map;
        for(int i=0;i<n;i++) u_map[keyed[i].second]=i;
        vector<int> home;
        for(int el:nums) home.push_back(u_map[el]);
        int count=0;
        for(int i=0;i<n;i++){
            while(home[i]!=i){
                int j=home[i];
                swap(home[i],home[j]);
                count++;
            }
        }
        return count;
    }
};