/*
 * LeetCode: 2374 - Node With Highest Edge Score
 * Link: https://leetcode.com/problems/node-with-highest-edge-score/
 * Difficulty: Medium
 * Time: O(n) where n is size of input vector edges
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        vector<long long> score(n,0);
        for(int i=0;i<n;i++) score[edges[i]]+=i;
        return max_element(score.begin(),score.end())-score.begin();
    }
};