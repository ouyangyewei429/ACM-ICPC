/*
PROG:   Getting in Line
ID  :   ouyangyewei
LANG:   C++
*/
//#pragma warnning (disable : 4786)

#include <set>
#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define DEBUG 1
#define INF 10000

const int MAXN = 10;
//const double INF = 10000;

//typedef pair<int, int> PII;
//typedef vector<PII> VPII;

int N, cas = 1;
bool vis[MAXN];
double dist[MAXN];
double graph[MAXN][MAXN];
struct Point {
    int x, y;
}p[MAXN];

void readPoint() {
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &p[i].x, &p[i].y);
    }
}

void calPointDist() {
    memset(graph, INF, sizeof(graph));
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int x1 = p[i].x;
            int y1 = p[i].y;
            int x2 = p[j].x;
            int y2 = p[j].y;
            double dist = hypot(1.0 * abs(x1 - x2), 1.0 * abs(y1 - y2));
            graph[i][j] = graph[j][i] = dist + 16;
        }
    }
}

void prim(int src) {
    int u, v, i, j, k, x1, y1, x2, y2;
    double minValue, lowcost = 0;
    
    for (k = 0; k < N; ++k) {
        vis[k] = false;
        dist[k] = graph[src][k];
    }
    
    u = v = src;
    dist[src] = 0;
    vis[src] = true;
    for (i = 0; i < N; ++i) {
        u = v, minValue = INF;
        for (j = 0; j < N; ++j) {
            if (!vis[j] && minValue > dist[j]) {
                v = j;
                minValue = dist[j];
            }
        }
        
        vis[v] = true;
        lowcost += dist[v];
        int x1 = p[u].x, y1 = p[u].y;
        int x2 = p[v].x, y2 = p[v].y;
        double dis = (dist[v] * 100 + 0.5) / 100.0;
        printf("Cable requirement to connect (%d,%d) \
to (%d,%d) is %.2lf feet.\n", x1, y1, x2, y2, dis);
        for (j = 0; j < N; ++j) {
            if (!vis[j] && dist[j] > graph[v][j])
                dist[j] = graph[v][j];
        }
    }
    printf("Number of feet of cable required is %.2lf.\n", lowcost);
}

int main() {
#if DEBUG
    freopen("E:\\216.in", "r" ,stdin);
    freopen("E:\\216.out", "w", stdout);
#endif

    while (~scanf("%d", &N) && N) {
        printf("**********************************************************\n");
        printf("Network #%d\n", cas++);
        readPoint();
        calPointDist();
        prim( 0 );
    }// End of while

    return 0;
}

