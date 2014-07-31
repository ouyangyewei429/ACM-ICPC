/*
PROG:   A Walk Through the Forest
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <algorithm>
using namespace std;

#define onlinejudge

const int maxn = 1004;

bool hash[maxn];
int  N, M, a, b, d, ans;
int  roads[maxn], graph[maxn][maxn];

int FindSet(int x)
{
    int k = x;
    while (k != roads[k])
        k = roads[k];
    
    return k;
}// FindSet

void Merge(int x, int y)
{
    int r1 = FindSet(x);
    int r2 = FindSet(y);
    
    if (r1 == r2)
        return ;
    
    if (r1 < r2)
        roads[r2] = r1;
    else
        roads[r1] = r2;
}// Merge

void dfs(int st)
{
    if (st == 2)
    {
        ++ans;
        return ;
    }// destination
    
    for (int i=2; i<=N; ++i)
    {
        if (graph[st][i] && !hash[i])
        {
            hash[i] = true;
            dfs(i);
            hash[i] = false;
        }
    }// End of For
}// dfs

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1142.txt", "r", stdin);
    freopen("E:\\hdoj_1142_ans.txt", "w", stdout);
#endif

    while (~scanf("%d", &N), N!=0)
    {
        memset(graph, 0, sizeof(graph));
        for (int i=1; i<=N; ++i)
            roads[i] = i;
            
        scanf("%d", &M);
        for (int i=1; i<=M; ++i)
        {
            scanf("%d %d %d", &a, &b, &d);
            graph[a][b] = graph[b][a] = d;
            Merge(a, b);
        }// End of For 
        
        int cnt = 0;
        for (int i=1; i<=N; ++i)
        {
            if (i == roads[i])
                ++cnt;
        }// count the set number
        
        if (cnt > 1)
            printf("0\n");
        else
        {
            printf("DFS\n");
            
            memset(hash, false, sizeof(hash));
            
            ans = 0, hash[1] = true;
            dfs(1);
            
            printf("%d\n", ans);
        }
    }/* End of While */
    
    return 0;
}
