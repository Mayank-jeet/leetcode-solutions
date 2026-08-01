/*
 * 3169 - Count Days Without Meetings
 * Link: https://leetcode.com/problems/count-days-without-meetings/
 * Difficulty: Medium
 * Time: O(nlogn)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int ans=(meetings[0][0]-1);
        int n=meetings.size();
        for(int i=1;i<n;i++){
            if(meetings[i-1][1]<meetings[i][0]) ans+=(meetings[i][0]-meetings[i-1][1]-1);
            else if(meetings[i-1][1]>meetings[i][1]) meetings[i][1]=meetings[i-1][1];
        }
        ans+=(days-meetings.back()[1]);
        return ans;
    }
};