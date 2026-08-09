/*
 * LeetCode: 1423 - Maximum Points You Can Obtain from Cards
 * Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans=0,n=cardPoints.size();
        for(int i=0;i<k;i++) ans+=cardPoints[i];
        int sum=ans;
        if(k==n) return ans;
        for(int i=k-1;i>=0;i--){
            sum+=cardPoints[n-k+i]-cardPoints[i];
            ans=max(ans,sum);
        }
        return ans;
    }
};