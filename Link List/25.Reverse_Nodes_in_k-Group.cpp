/*
 * LeetCode: 25 - Reverse Nodes in k-Group
 * Link: https://leetcode.com/problems/remove-nodes-from-linked-list/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the list
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* localBack=nullptr;
        ListNode* prev=nullptr;
        ListNode* current=head;
        ListNode* nextNode=head->next;
        ListNode* lastNode=nullptr;
        ListNode* ansHead=nullptr;
        while(current){
            localBack=current;
            for(int i=0;i<k;i++){
                if(current){
                    current->next=prev;
                    prev=current;
                    current=nextNode;
                    if(nextNode) nextNode=nextNode->next;
                }else{
                    ListNode* nextLocal=prev->next;
                    ListNode* prevLocal=nullptr;
                    while(prev){
                        prev->next=prevLocal;
                        prevLocal=prev;
                        prev=nextLocal;
                        if(nextLocal) nextLocal=nextLocal->next;
                    }
                    if(lastNode) lastNode->next=prevLocal;
                    if(ansHead) return ansHead;
                    else return head;
                }
            }
            if(!ansHead) ansHead=prev;
            localBack->next=current;
            if(lastNode) lastNode->next=prev;
            lastNode=localBack;
            prev=nullptr;
        }
        return ansHead;
    }
};