/*
 * LeetCode: 1104 - Path In Zigzag Labelled Binary Tree
 * Link: https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/
 * Difficulty: Medium
 * Time: O(log(n))
 * Space: O(log(n)) - considering the space used for the answer vector, otherwise O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int index=log2(label);
        vector<int> ans;
        int left=pow(2,index);
        int right=2*left-1;
        while(index!=0){
            ans.push_back(label);
            left/=2;
            right/=2;
            label/=2;
            int dist=0;
            if(index%2==0){
                dist=label-left;
                label=right-dist;
            }else{
                dist=right-label;
                label=left+dist;
            }
            index--;
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
