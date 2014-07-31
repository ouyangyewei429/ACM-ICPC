/*
PROG: The Dole Queue
ID  : ouyangyewei
LANG: C++
*/
#include <cstdio>
#include <iostream>
using namespace std;

#define DEBUG 1

int N, K, M;
typedef struct Lists {
    int value;
    Lists *prior, *next;
    Lists() {value = 0, prior = NULL, next = NULL;}
}L;

void CreatLists(int nodeNums, L* &head) {
    L *front = head, *cur = NULL;
    
    for (int i = 1; i <= nodeNums; ++i) {
        cur = new Lists;
        cur -> value = i;
        if (i == 1) {
            front = head = cur;
        } else {
            front -> next = cur;
            cur -> prior = front;
            front = cur;
        }
    }
    
    cur -> next = head;
    head -> prior = cur;
    return ;
}// CreatLists

void DeleteNodes(L* &ptr, int &nodeNums, int f) {
    L *tempPtr = (f == 1 ? ptr -> next : ptr -> prior);
    
    --nodeNums;
    ptr -> prior -> next = ptr -> next;
    ptr -> next -> prior = ptr -> prior;
    ptr = tempPtr;
}// DeleteNodes

void DoleQueue(int nodeNums, L *head) {
    L *p1 = head;
    L *p2 = head -> prior;
    
    while (nodeNums) {  // simulation
        for (int i = 1; i < K; ++i) {  // choose off k persons
            // in clockwise count
            p1 = p1 -> next;
        }
        for (int j = 1; j < M; ++j) {  // choose off m persons 
            // in anticlockwise count
            p2 = p2 -> prior;
        }
        
        if (p1 -> value == p2 -> value) {
            printf("%3d,", p1 -> value);
        } else {
            printf("%3d%3d,", p1 -> value, p2 -> value);
        }
        DeleteNodes(p1, nodeNums, 1);
        DeleteNodes(p2, nodeNums, 2);
    }
}// DoleQueue

int main() {
#if DEBUG
    freopen("E:\\133.in", "r", stdin);
    freopen("E:\\133.out", "w", stdout);
#endif

    while (~scanf("%d %d %d", &N, &K, &M), N+K+M!=0) {
        Lists *head = NULL;
        CreatLists(N, head);
        DoleQueue(N, head);
    }// End of while
    
    return 0;
}
