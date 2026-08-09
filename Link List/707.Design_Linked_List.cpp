/*
 * LeetCode:  707 - Design Linked List
 * Link: https://leetcode.com/problems/design-linked-list/
 * Difficulty: Medium
 * Time: O(1) for get(), addAtHead() and addAtTail() operations, O(index) for addAtIndex() and deleteAtIndex() operations
 * Space: O(n) where n is the number elements in the list
 */
#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int k):val(k),next(nullptr){}
};
class MyLinkedList {
public:
    Node* head;
    Node* tail;
    MyLinkedList() {
        head=tail=nullptr;
    }
    
    int get(int index) {
        if(!head) return -1;
        Node* current=head;
        for(int i=0;i<index;i++){
            if(current) current=current->next;
            else return -1;
        }
        if(current) return current->val;
        return -1;
    }
    
    void addAtHead(int val) {
        Node* newNode=new Node(val);
        newNode->next=head;
        head=newNode;
        if(!tail) tail=head;
    }
    
    void addAtTail(int val) {
        if(!head) {
            addAtHead(val);
            return;
        }
        Node* newNode=new Node(val);
        tail->next=newNode;
        tail=newNode;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0) return;
        if(index>0 && !head) return;
        else if(index==0){
            addAtHead(val);
            return;
        }
        Node* current=head;
        for(int i=0;i<index-1;i++){
            if(current) current=current->next;
            else return;
        }
        if(current==nullptr) return;
        if(current==tail){
            addAtTail(val);
            return;
        }
        Node* newNode=new Node(val);
        newNode->next=current->next;
        current->next=newNode;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || !head) return;
        if(index==0){
            Node* delNode=head;
            head=delNode->next;
            if(tail==delNode) tail=nullptr;
            delete delNode;
            return;
        }
        Node* current=head;
        for(int i=0;i<index-1;i++){
            if(current) current=current->next;
            else return;
        }
        if(!current || !current->next) return;
        Node* delNode=current->next;
        current->next=current->next->next;
        if(delNode==tail) tail=current;
        delNode->next=nullptr;
        delete delNode;
    }
};