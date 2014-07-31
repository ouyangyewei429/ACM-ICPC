#pragma warnning (disable : 4786)
#pragma warnning (disable : 4530)

#include <map>
#include <queue>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

const int MAXN = 1005;
const int INF = 0x3F3F3F3F;

bool inq[MAXN];
int N, M, dist[MAXN], edge[MAXN][MAXN];
map<string, int> mp;
struct Node {
    int id, degree;
}deg[MAXN];

void init() {
    mp.clear();
    for (int i = 0; i <= N; ++i) {
        dist[i] = INF;
        inq[i] = false;
        for (int j = 0; j <= N; ++j)
            edge[i][j] = INF;
    }// End of for
}

void readData() {
    string a, b;
    for (int i = 1; i <= N; ++i) {
        cin >> a;
        mp[a] = i;
        deg[i].id = i, deg[i].degree = 0;
    }// End of for
    
    scanf("%d", &M);
    for (int j = 1; j <= M; ++j) {
        cin >> a >> b;
        edge[mp[a]][mp[b]] = edge[mp[b]][mp[a]] = 1;
        ++deg[mp[a]].degree;
        ++deg[mp[b]].degree;
    }// End of for
}

void spfa(int src) {
    int u;
    queue<int> q;
    
    dist[src] = 0;
    inq[src] = true;
    q.push(src);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        inq[u] = false;
        
        for (int i = 1; i <= N; ++i) {
            if (dist[u] + edge[u][i] < dist[i]) {
                dist[i] = dist[u] + edge[u][i];
                if (!inq[i]) {
                    q.push(i);
                    inq[i] = true;
                }
            }
        }
    }// End of while
}

void process() {
    int minId, minDeg = INF;
    for (int i = 1; i <= N; ++i) {
        if (minDeg > deg[i].degree)
            minId = deg[i].id, minDeg = deg[i].degree;
    }
    spfa(minId);
    
    int maxLen = -1;
    for (int i = 1; i <= N; ++i) {
        if (maxLen < dist[i])
            maxLen = dist[i];
    }// End of for
    if (maxLen != INF)
        printf("%d\n", maxLen);
    else
        printf("-1\n");
}

void debug() {
    for (int i = 1; i <= N; ++i)
        cout << deg[i].id << " " << deg[i].degree << endl;
    
    cout << "================" << endl;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j)
            cout << edge[i][j] << " ";
        cout << endl;
    }
}

int main() {
    while (~scanf("%d", &N), N) {
        init();
        readData();
        process();
//        debug();
    }// End of while
    return 0;
}
