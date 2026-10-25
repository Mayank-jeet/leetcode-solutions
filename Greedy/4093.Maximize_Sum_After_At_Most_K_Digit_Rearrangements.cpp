/*
 * LeetCode: 4093 - Maximize Sum After At Most K Digit Rearrangements
 * Link: https://leetcode.com/problems/maximize-sum-after-at-most-k-digit-rearrangements/
 * Difficulty: Medium
 * Time: O(n·d·log(d)+n·log(k)) wwhere d is the number of digits in a number ans n is the length of input vector
 * Space: O(k)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int formNew(int el){
        vector<int> digits;
        while(el>0){
            digits.push_back(el%10);
            el/=10;
        }
        sort(digits.begin(),digits.end(),greater<int>());
        int newEl=0;
        for(int el:digits){
            newEl*=10;
            newEl+=el;
        }
        return newEl;
    }
    long long maximizeSum(vector<int>& nums, int k) {
        set<pair<int,int>> set;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int newEl=formNew(nums[i]);
            int change=newEl-nums[i];
            if(newEl==nums[i]) continue;
            else if((int)set.size()<k) set.insert({change,i});
            else if(!set.empty() && set.begin()->first<change){
                set.erase(set.begin());
                set.insert({change,i});
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++) ans+=(long long)nums[i];
        for(auto el:set) ans+=(long long)el.first;
        return ans;
    }
};