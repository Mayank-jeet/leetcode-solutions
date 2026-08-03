/*
 * LeetCode: 1004 - Max Consecutive Ones III
 * Link: https://leetcode.com/problems/max-consecutive-ones-iii/
 * Difficulty: Medium
 * Time: O(n) where n size of the input vector
 * Space: O(n) space used for queue
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int> q;
        int n=nums.size(),ans=0,current=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(k!=0){
                    if(q.size()<k){
                        current++;
                    }else{
                        current=i-q.front();
                        q.pop();
                    }
                    q.push(i);
                }else current=0;
            }else current++;
            ans=max(current,ans);
        }
        return ans;
    }
};