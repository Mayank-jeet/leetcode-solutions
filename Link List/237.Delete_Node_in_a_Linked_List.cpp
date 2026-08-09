/*
 * LeetCode: 237 - Delete Node in a Linked List
 * Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
 * Difficulty: Easy
 * Time: O(1)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=(node->next)->val;
        ListNode* delNode=node->next;
        node->next=node->next->next;
        delNode->next=nullptr;
        delete delNode;
    }
};