/*
 * LeetCode: 22 - Generate Parentheses
 * Link: https://leetcode.com/problems/generate-parentheses/
 * Difficulty: Medium
 * Time: O(n*(Cn))
 * Space: O(n*(Cn))
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void generate(vector<string>& ans,string s,int& n,int sum,int concave){
        if(s.length()==2*n){
            ans.emplace_back(s);
            return;
        }
        if(concave<n) {
            s.push_back('(');
            generate(ans,s,n,sum+1,concave+1);
            s.pop_back();
        }
        if(sum>0){
            s.push_back(')');
            generate(ans,s,n,sum-1,concave);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(ans,"",n,0,0);
        return ans;
    }
};