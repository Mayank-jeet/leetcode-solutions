/*
 * LeetCode: 633 - Sum of Square Numbers
 * Link: https://leetcode.com/problems/sum-of-square-numbers/
 * Difficulty: Medium
 * Time: O(n) where n is the square root of the input number
 * Space: O(1)
 */ 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
        int high=(int)sqrt(c),low=0;
        while(low<=high){
            long long square=(long long)low*low + high*high;
            if(square==c) return true;
            else if(square<c) low++;
            else high--;
        }
        return false;
    }
};