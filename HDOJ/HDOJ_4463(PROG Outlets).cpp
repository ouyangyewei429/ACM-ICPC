#pragma warnning (disable : 4786)
#pragma warnning (disable : 4530)

#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 60;
const int INF = 0x3F3F3F3F;

bool vis[MAXN];
int N, p, q;
double edge[MAXN][MAXN], dist[MAXN];
struct Node {
    int x, y;
}point[MAXN];

void init() {
    for (int i = 0; i <= N; ++i) {
        dist[i] = INF;
        vis[i] = false;
        for (int j = 0; j <= N; ++j)
            edge[i][j] = INF;
    }// End of for
}

void readData() {
    scanf("%d %d", &p, &q);
    for (int i = 1; i <= N; ++i)
        scanf("%d %d", &point[i].x, &point[i].y);
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            double dx = (double)(point[i].x - point[j].x);
            double dy = (double)(point[i].y - point[j].y);
            edge[i][j] = hypot(dx, dy);
        }
    }// End of for
}

void prim() {
    for (int i = 1; i <= N; ++i)
        dist[i] = edge[p][i];
    
    dist[p] = 0;
    vis[p] = vis[q] = true;
    double lowcost = dist[q];
    for (int j = 1; j <= N; ++j) {
        if (!vis[j] && edge[q][j] < dist[j])
            dist[j] = edge[q][j];
    }
    
    for (int i = 2; i < N; ++i) {
        int u;
        double minValue = 10000.0;
        for (int j = 1; j <= N; ++j) {
            if (!vis[j] && minValue > dist[j])
                u = j, minValue = dist[j];
        }
        
        vis[u] = true;
        lowcost += dist[u];
        for (int j = 1; j <= N; ++j) {
            if (!vis[j] && edge[u][j] < dist[j])
                dist[j] = edge[u][j];
        }
    }// End of for
    printf("%.2lf\n", lowcost);
}

void debug() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            printf("%.2lf ", edge[i][j]);
        }
        printf("\n");
    }
}

int main() {
    while (~scanf("%d", &N), N) {
        init();
        readData();
        prim();
//        debug();
    }// End of while
    return 0;
}
