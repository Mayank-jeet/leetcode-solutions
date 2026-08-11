/*
 * LeetCode:  2924 - Find Champion II
 * Link: https://leetcode.com/problems/find-champion-ii/
 * Difficulty: Medium
 * Time: O(n) where n number of vertices in graph
 * Space: O(n) used for unordered_set
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_set<int> set;
        int sum=0;
        for(int i=0;i<edges.size();i++){
            if(set.count(edges[i][1])==0){
                sum+=edges[i][1];
                set.insert(edges[i][1]);
            }
        }
        int possible_winner=((n-1)*n/2)-sum;
        if(possible_winner>=n) return -1;
        else if(possible_winner!=0 && set.count(0)==0) return -1;
        else if(set.count(possible_winner)==1) return -1;
        return possible_winner;
    }
};