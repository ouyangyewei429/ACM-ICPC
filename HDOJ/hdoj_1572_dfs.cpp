/*
PROG:   下沙小面的(2)
ID  :   ouyangyewei
LANG:   C++
*/
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <algorithm>
using namespace std;

const int maxn = 35;
const int INF = 0x3F3F3F3F;

bool hash[maxn];
int  NCity, K, T, result, dest[maxn], dist[maxn][maxn];

void dfs(int cnt, int ss, int dis)
{
    if ( cnt==T )
    {
        if (result > dis)
            result = dis;
            
        return ;
    }// destination
    
    for (int i=0; i<K; ++i)
    {
        if ( dest[i]!=INF && !hash[dest[i]] )
        {
            hash[dest[i]] = true;
            dfs(cnt+1, dest[i], dis+dist[ss][dest[i]]);
            hash[dest[i]] = false;
        }
    }// Main Process
    
    return ;
}// dfs

int main()
{
    int i, j, tmp;
    while (~scanf("%d", &NCity), NCity!=0)
    {
        memset(hash, false, sizeof(hash));
        
        for (i=0; i<NCity; ++i)
        {
            for (j=0; j<NCity; ++j)
            {
                scanf("%d", &tmp);
                dist[i][j] = dist[j][i] = tmp;
            }    
        }// End of For
        
        scanf("%d", &K);
        for (i=0; i<K; ++i)
            scanf("%d", &dest[i]);
        
        T = K;
        for (i=0; i<K; ++i)
        {
            for (j=i+1; j<K; ++j)
            {
                if ( dest[j]==dest[i] )
                    --T, dest[j]=INF;
            }
        }// remove the same destination

        hash[0]=true, result=INF;
        dfs(0, 0, 0);/* dfs(cnt, start, dist) */
        printf("%d\n", result);
    }// End of while
    
    return 0;
}
