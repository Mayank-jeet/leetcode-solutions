/*
 * LeetCode: 2337 - Move Pieces to Obtain a String
 * Link: https://leetcode.com/problems/move-pieces-to-obtain-a-string/
 * Difficulty: Medium
 * Time: O(n) 
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.length(),i=-1,j=-1;
        char sEl,tEl;
        while(i<n || j<n){
            i++;
            while(start[i]=='_' && i<n) i++;
            sEl=start[i];
            j++;
            while(target[j]=='_' && j<n) j++;
            tEl=target[j];
            if((i==n && j!=n) || (i!=n && j==n) || sEl!=tEl) return false;
            if(sEl=='L' && i<j) return false;
            else if(sEl=='R' && i>j) return false; 
        }
        return true;
    }
};