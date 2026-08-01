/*
 * LeetCode: 2410 - Maximum Matching of Players With Trainers
 * Link: https://leetcode.com/problems/maximum-matching-of-players-with-trainers/
 * Difficulty: Medium
 * Time: O(nlogn)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int m=players.size(),n=trainers.size(),ans=0;
        int j=0;
        for(int i=0;i<n;i++){
            if(j>=m) break;
            if(players[j]<=trainers[i]){
                ans++;
                j++;
            }
        }
        return ans;
    }
};