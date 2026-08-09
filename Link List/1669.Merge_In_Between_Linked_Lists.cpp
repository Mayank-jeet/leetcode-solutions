/*
 * LeetCode:  1669 - Merge In Between Linked Lists
 * Link: https://leetcode.com/problems/merge-in-between-linked-lists/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the list
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head=list1;
        for(int i=0;i<a-1;i++) list1=list1->next;
        ListNode* temp=list1->next;
        list1->next=list2;
        int i=0;
        while(i<b-a || list1->next){
            if(i<b-a) temp=temp->next;
            if(list1->next) list1=list1->next;
            i++;
        }
        list1->next=temp->next;
        temp->next=nullptr;
        return head;
    }
};