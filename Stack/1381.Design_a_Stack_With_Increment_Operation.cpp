/*
 * LeetCode: 1381 - Design a Stack With Increment Operation
 * Link: https://leetcode.com/problems/design-a-stack-with-increment-operation/
 * Difficulty: Medium
 * Time: O(k) for increment operation where k is the number of elements to increment, O(1) for push and pop operations
 * Space: O(n) for forming the stack
 */
#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int data):val(data),next(nullptr),prev(nullptr){}
};
class CustomStack {
public:
    int size;
    int maxSize;
    Node* head;
    Node* tail;
    CustomStack(int maxSize):size(0),maxSize(maxSize),head(nullptr),tail(nullptr) {
        
    }
    
    void push(int x) {
        if(size>=maxSize) return;
        size++;
        Node* newNode=new Node(x);
        if(!head) {
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
    
    int pop() {
        if(!head) return -1;
        Node* delNode=tail;
        tail=tail->prev;
        if(!tail) head=nullptr;
        else tail->next=nullptr;
        int ans=delNode->val;
        delete delNode;
        size--;
        return ans;
    }
    
    void increment(int k, int val) {
        Node* temp=head;
        for(int i=0;i<k;i++){
            if(!temp) break;
            temp->val+=val;
            temp=temp->next;
        }
    }
};