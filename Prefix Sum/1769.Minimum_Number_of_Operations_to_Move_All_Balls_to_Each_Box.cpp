/*
 * LeetCode: 1769 - Minimum Number of Operations to Move All Balls to Each Box
 * Link: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
 * Difficulty: Medium
 * Time: O(n) where n size of the input vector
 * Space: O(n) considering space used by output vector, otherwise O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int right=0;
        if(boxes[0]=='1') right++;
        int n=boxes.length(),sumR=0,sumL=0;
        for(int i=1;i<n;i++){
            if(boxes[i]=='1'){
                right++;
                sumR+=i;
            }
        }
        vector<int> ans;
        int left=0;
        for(int i=0;i<n;i++){
            if(boxes[i]=='1') {
                right--;
            }
            ans.push_back(sumR+sumL);
            sumR-=(right);
            if(boxes[i]=='1') {
                left++;
            }
            sumL+=left;
        }
        return ans;
    }
};