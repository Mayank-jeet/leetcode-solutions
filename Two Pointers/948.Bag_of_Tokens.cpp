/*
 * LeetCode: 948 - Bag of Tokens
 * Link: https://leetcode.com/problems/bag-of-tokens/
 * Difficulty: Medium
 * Time: O(nlog(n)) for sorting input vector, else O(n) for while loop
 * Space: O(1)
 */
// This solutution can be simplified more, using map, but that will take more space O(n) in worst case
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int high=tokens.size()-1,low=0,score=0,ans=0;
        while(low<=high){
            if(tokens[low]<=power){
                power-=tokens[low];
                low++;
                score++;
            }else if(score>0){
                power+=tokens[high];
                high--;
                score--;
            }else break;
            ans=max(ans,score);
        }
        return ans;
    }
};