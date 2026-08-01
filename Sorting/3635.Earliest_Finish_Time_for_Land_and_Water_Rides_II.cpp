/*
 * LeetCode: 3635 - Earliest Finish Time for Land and Water Rides II
 * Link: https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/
 * Difficulty: Medium
 * Time: O(nlogn)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rideTime(vector<int>& start1, vector<int>& duration1, vector<int>& start2, vector<int>& duration2){
        int finish1=100000000,ans=100000000;
        for(int i=0;i<start1.size();i++){
            finish1=min(finish1,(start1[i]+duration1[i]));
        }
        for(int i=0;i<start2.size();i++){
            ans=min(ans,(max(finish1,start2[i])+duration2[i]));
        }
        return ans;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landFirst=rideTime(landStartTime,landDuration,waterStartTime,waterDuration);
        int waterFirst=rideTime(waterStartTime,waterDuration,landStartTime,landDuration);
        return min(landFirst,waterFirst);
    }
};