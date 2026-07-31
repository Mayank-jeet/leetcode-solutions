/*
 * LeetCode: 1387 - Sort Integers by The Power Value
 * Link: https://leetcode.com/problems/sort-integers-by-the-power-value/
 * Difficulty: Medium
 * Time: O(n log n)
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int power(int num){
        if(num==1) return 0;
        if(num%2==0) num/=2;
        else num=num*3+1;
        return 1+power(num);
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> sortedVec;
        for(int i=lo;i<=hi;i++) sortedVec.emplace_back(power(i),i);
        sort(sortedVec.begin(),sortedVec.end());
        return sortedVec[k-1].second;
    }
};