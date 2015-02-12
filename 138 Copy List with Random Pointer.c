#include <stdio.h>
#include <stdlib.h>
/*
138 Copy List with Random Pointer
https://oj.leetcode.com/problems/copy-list-with-random-pointer/
*/
struct LinkedListNodeWithRandomPointer{
    int rank;
    struct LinkedListNodeWithRandomPointer* next;
    struct LinkedListNodeWithRandomPointer* jump;
};
typedef struct LinkedListNodeWithRandomPointer node;

#define NEWNODE (node*)malloc(sizeof(node))

/*
Copy a linked list with next and arbitrary pointer
http://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/
Method 2, a little modified
O(n) time, O(1) space
A similar method can be applied on binary tree copy
*/
/*
A specific copy method for "copyRandom"
Append "tag" node behind "src" node
*/
#define COPY(tag,src) \
    tag->rank = src->rank;\
    tag->next = src->next;\
    tag->jump = src->jump;\
    src->next = tag;  // insert
     
node* copyRandom(node* old){
    node* res;
    node* pold = old;
    node* pnew = res;
    
    if(pold == 0) return 0;
    
    // 0. insert new nodes
    while(pold != 0){
        pnew = NEWNODE;
        COPY(pnew,pold);
        pold = pnew->next;
    }
    // 1. modify jump nodes
    pnew = old;
    while(pnew != 0){
        pnew = pnew->next; // now at new node
        if(pnew->jump != 0) 
            pnew->jump = pnew->jump->next;
        pnew = pnew->next; // now at old node or NULL
    }
    // 2. split 2 lists
    pold = old;
    pnew = res;
    while(pnew->next != 0){
        pold->next = pnew->next;
        pold = pold->next;
        pnew->next = pold->next;
        pnew = pnew->next;
    }
    pold->next = 0;
    return res;
}

int main(){
    // TODO: test
    return 0; 
}