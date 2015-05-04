#include <stdio.h>
#include <stdlib.h>
/*
108 Convert Sorted Array to Binary Search Tree
https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
*/
#define MAX(a,b) (a)>(b)?(a):(b)

struct Binary_Search_Tree_Node
{
    int rank;
    struct Binary_Search_Tree_Node *pl;
    struct Binary_Search_Tree_Node *pr;
};
typedef struct Binary_Search_Tree_Node node;

void inorder(node* n)
{
    if(n != 0){
        inorder(n->pl);
        printf("%d ", n->rank);
        inorder(n->pr);
    }
}

void initInOrder(node* n, int* arr, int start, int end){
    int mid = (start+end)>>1;
    n->rank = arr[mid];
    
    if(start <= mid-1 || mid+1 <= end){
        if(start <= mid-1){
            n->pl = (node*)malloc(sizeof(node*));
            initInOrder(n->pl, arr, start, mid-1);
        }
        if(mid+1 <= end){
            n->pr = (node*)malloc(sizeof(node*));
            initInOrder(n->pr, arr, mid+1, end);
		}
    } else {
        n->pl = 0;
        n->pr = 0;
    }
}

#define NUM 7

int main(int argc, char** argv){
    int arr[NUM];
    int i;
    node* n = (node*)malloc(sizeof(node*));
    for(i=0;i<NUM;i++){
        arr[i] = i;
    }
    initInOrder(n,arr,0,NUM-1);
    inorder(n);
    return 0;
}
