/*
 * LeetCode:  641 - Design Circular Deque
 * Link: https://leetcode.com/problems/design-circular-deque/
 * Difficulty: Medium
 * Time: O(1) for all operations except deleteLast() which is O(n) where n is the number of elements in the deque
 * Space: O(n) where n is the number elements in the deque
 */
#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int data): val(data),next(nullptr){}
};
class MyCircularDeque {
public:
    int max;
    Node* head;
    Node* tail;
    int size;
    MyCircularDeque(int k):head(nullptr),tail(nullptr),max(k),size(0) {
        
    }
    
    bool insertFront(int value) {
        if(size>=max) return false;
        Node* newNode=new Node(value);
        newNode->next=head;
        head=newNode;
        if(!head->next) tail=head;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(size>=max) return false;
        size++;
        Node* newNode=new Node(value);
        if(!head){
            head=newNode;
            tail=newNode;
            return true;
        }
        tail->next=newNode;
        tail=newNode;
        return true;
    }
    
    bool deleteFront() {
        if(size==0) return false;
        size--;
        Node* delNode=head;
        head=head->next;
        if(!head) tail=head;
        delNode->next=nullptr;
        return true;
    }
    
    bool deleteLast() {
        if(size==0) return false;
        size--;
        if(!head->next){
            head=nullptr;
            tail=nullptr;
            return true;
        }
        Node* prev=head;
        while(prev->next->next!=nullptr) prev=prev->next;
        prev->next=nullptr;
        tail=prev;
        return true;
    }
    
    int getFront() {
        if(!head) return -1;
        return head->val;
    }
    
    int getRear() {
        if(!tail) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==max;
    }
};
