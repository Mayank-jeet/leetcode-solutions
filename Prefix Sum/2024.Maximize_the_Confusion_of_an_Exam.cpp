/*
 * LeetCode: 2024 - Maximize the Confusion of an Exam
 * Link: https://leetcode.com/problems/maximize-the-confusion-of-an-exam/
 * Difficulty: Medium
 * Time: O(n) 
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(string answerKey, int k,char C){
        int ans=0,current=0,n=answerKey.length();
        queue<int> q;
        for(int i=0;i<n;i++){
            if(answerKey[i]==C){
                if(q.size()<k){
                    current++;
                }else{
                    current=i-q.front();
                    q.pop();
                }
                q.push(i);
            }else current++;
            ans=max(current,ans);
        }
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(check(answerKey,k,'T'),check(answerKey,k,'F'));
    }
};