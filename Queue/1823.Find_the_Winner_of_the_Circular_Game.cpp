/*
 * LeetCode: 1823 - Find the Winner of the Circular Game
 * Link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(k)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++) q.push(i);
        while(q.size()!=1){
            for(int i=1;i<k;i++){
                if(q.size()==1) return q.front();
                else {
                    q.push(q.front());
                    q.pop();
                }
            }
            q.pop();
        }
        return q.front();
    }
};