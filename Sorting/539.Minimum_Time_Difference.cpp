/*
 * LeetCode: 539 - Minimum Time Difference
 * Link: https://leetcode.com/problems/minimum-time-difference/
 * Difficulty: Medium
 * Time: O(nlog(n))
 * Space: O(1) or o(n) if we consider the space used fro storing ans
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        int n=timePoints.size();
        for(int i=0;i<n;i++){
            int hr=stoi(timePoints[i].substr(0,2));
            int mi=stoi(timePoints[i].substr(3,2));
            minutes.emplace_back(hr*60+mi);
        }
        sort(minutes.begin(),minutes.end());
        int ans=((1440-minutes[n-1])+minutes[0]);
        for(int i=1;i<n;i++){
            ans=min(ans,minutes[i]-minutes[i-1]);
        }
        return ans;
    }
};