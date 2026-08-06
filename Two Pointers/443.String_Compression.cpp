/*
 * LeetCode: 443 - String Compression
 * Link: https://leetcode.com/problems/string-compression/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(n)
 */ 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void numInsert(vector<char>& vec,int n){
        if(n==1) return;
        vector<char> temp;
        while(n>0){
            char el=n%10+'0';
            n/=10;
            temp.emplace_back(el);
        }
        int sz=temp.size();
        for(int i=sz-1;i>=0;i--) vec.emplace_back(temp[i]);
    }
    int compress(vector<char>& chars) {
        int n=chars.size();
        int chunk=1;
        vector<char> ans;
        for(int i=0;i<n;i++){
            if(i!=(n-1) && chars[i]==chars[i+1]) chunk++;
            else{
                ans.emplace_back(chars[i]);
                numInsert(ans,chunk);
                chunk=1;
            }
        }
        chars=ans;
        return chars.size();
    }
};