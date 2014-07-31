/*
PROG:   humble(TLE)
ID  :   ouyangyewei
LANG:   C++
*/
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <assert.h>
#include <memory.h>
#include <algorithm>

using namespace std;

#define DEBUG 1
#define INF 2147483647

namespace {

set<int> ss;
priority_queue<int> q;
int N, K, S[102]={0};
    
}// namespace

void ReadData() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }    
}// ReadData

void Dfs(long long factor, int depth) {
    if (factor != 1 && ss.find(factor) == ss.end()) {
        if (q.size() < K || factor < q.top()) {  // push into max heap
            ss.insert(factor);
            q.push(factor);
        }
        if (q.size() > K) {  // elem in max heap is more than K
            q.pop();
        }
    }
    
    if (depth == N) {  // Cycle termination condition
        return ;
    }
    
    while (factor < INF) {  // repeat
        if (q.size() == K && factor > q.top()) {
            break;
        }
            
        Dfs(factor, depth+1);
        factor *= S[depth];
    }
}// Dfs

int main() {
#if DEBUG
    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);
#endif

    ReadData();
    Dfs(1, 0);  // Dfs(factor, depth)
    cout << q.top() << endl;
  
    return 0;
}
/*
Test Data:
4 19
2 3 5 7

27
---------
1 20
2

1048576
*/
