/*
 * LeetCode:  382 - Linked List Random Node
 * Link: https://leetcode.com/problems/linked-list-random-node/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the linked list
 * Space: O(1)
 */
#include <bits/stdc++.h>
#include <random>
using namespace std;
class Solution {
public:
    int size=0;
    ListNode* root;
    Solution(ListNode* head):root(head) {
        ListNode* copy=root;
        while(copy){
            copy=copy->next;
            size+=1;
        }
    }
    
    int getRandom() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(0,size-1);
        int x = dist(gen);
        ListNode* copy=root;
        for(int i=1;i<=x;i++){
            copy=copy->next;
        }
        return copy->val;
    }
};