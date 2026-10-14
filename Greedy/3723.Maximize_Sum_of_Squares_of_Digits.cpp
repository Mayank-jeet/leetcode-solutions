/*
 * LeetCode: 3723 - Maximize Sum of Squares of Digits
 * Link: https://leetcode.com/problems/maximize-sum-of-squares-of-digits/
 * Difficulty: Medium
 * Time: O(num)
 * Space: O(num) for ans string
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num) return "";
        string ans;
        for(int i=num-1;i>=0;i--){
            int el=min(sum,9);
            if(sum>0) sum-=el;
            ans.push_back(static_cast<char>('0'+el));
        }
        if(sum>0) return "";
        return ans;
    }
};