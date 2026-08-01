/*
 * LeetCode: 2126 - Destroying Asteroids
 * Link: https://leetcode.com/problems/destroying-asteroids/
 * Difficulty: Medium
 * Time: O(nlogn)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long longMass=mass;
        sort(asteroids.begin(),asteroids.end());
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]<=longMass) longMass+=asteroids[i];
            else return false;
        }
        return true;
    }
};