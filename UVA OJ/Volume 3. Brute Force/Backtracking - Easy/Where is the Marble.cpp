/*
PROG:   Where is the Marble?
ID  :   ouyangyewei
LANG:   C++
*/
#pragma warnning (disable : 4786)

#include <set>
#include <map>
#include <vector>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define DEBUG 0

const int MAXN = 10010;

int N, Q, tmp, cnt, array[MAXN], cas = 1;
struct Tree {
    int val;
    Tree *lson, *rson;
    Tree() {
        val = 0, lson = rson = NULL;
    }
};
typedef struct Tree T;

void insertNode(T *&rt, int &data) {
    if (rt == NULL) {
        rt = new Tree();
        rt -> val = data;
        rt -> lson = rt -> rson = NULL;
        return ;
    } else if (data <= rt -> val) {
        insertNode(rt -> lson, data);
    } else {
        insertNode(rt -> rson, data);
    }
}

void inOrder(T *&rt) {
    if (rt != NULL) {
        inOrder(rt -> lson);
        array[cnt++] = rt -> val;
        inOrder(rt -> rson);
    }
}

int isFound(int &data) {
    for (int i = 0; i < N; ++i) {
        if (array[i] == data)
            return i + 1;
    }
    return -1;
}

int main() {
#if DEBUG
    freopen("E:\\10474.in", "r" ,stdin);
    freopen("E:\\10474.out", "w", stdout);
#endif

    while (~scanf("%d %d", &N, &Q) && N + Q) {
        T *root = NULL;
        for (int i = 0; i < N; ++i) {
            scanf("%d", &tmp);
            insertNode( root, tmp );
        }
        cnt = 0;
        inOrder( root );
        
        printf("CASE# %d:\n", cas++);
        for (int j = 0; j < Q; ++j) {
            scanf("%d", &tmp);
            int index = isFound( tmp );
            if ( index != -1 ) {
                printf("%d found at %d\n", tmp, index);
            } else {
                printf("%d not found\n", tmp);
            }
        }
        
        delete root;
    }// End of while

    return 0;
}

