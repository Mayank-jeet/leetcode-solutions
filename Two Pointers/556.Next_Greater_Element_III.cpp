/*
 * LeetCode: 556 - Next Greater Element III
 * Link: https://leetcode.com/problems/next-greater-element-iii/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(n)
 */ 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nextGreaterElement(int n) {
        string str=to_string(n);
        int idx=-1;
        int m=str.length();
        for(int i=m-2;i>=0;i--){
            if(str[i]<str[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1) return -1;
        for(int i=m-1;i>idx;i--){
            if(str[i]>str[idx]){
                swap(str[i],str[idx]);
                break;
            }
        }
        reverse(str.begin()+idx+1,str.end());
        double ans=stod(str);
        if(ans>pow(2,31)-1) return -1;
        return (int)ans;
    }
};