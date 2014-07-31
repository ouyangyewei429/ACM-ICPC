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

bool hash[maxn][maxn];
int  NCity, K, T, dest[maxn], dist[maxn][maxn];
typedef struct node
{
    int local, costs, num;
}NODE;

int bfs()
{
    NODE c, n;
    queue <NODE> q;
    
    c.local=0, c.costs=0, c.num=0;
    hash[ c.local ][ c.local ] = true;
    
    q.push( c );
    while ( !q.empty() )
    {
        c = q.front();
        q.pop();
        
        if ( c.num==T )
            return c.costs;
        
        for (int i=0; i<K; ++i)
        {
            if ( dest[i]!=INF && !hash[c.local][dest[i]] )
            {                
                n.local = dest[i];
                n.num = c.num+1;
                n.costs = c.costs + dist[c.local][n.local];
                
                hash[c.local][dest[i]] = true;
                q.push( n );
            }
        }// Main Process
    }// End of while
}// bfs

int main()
{
    while (~scanf("%d", &NCity), NCity!=0)
    {
        int i, j, tmp;
        for (i=0; i<NCity; ++i)
        {
            for (j=0; j<NCity; ++j)
            {
                scanf("%d", &tmp);
                hash[i][j] = false;
                dist[i][j] = dist[j][i] = tmp;
            }    
        }// End of For
        
        scanf("%d", &K);
        for (i=0; i<K; ++i)
            scanf("%d", &dest[i]);
        
        T = K;
        for (i=0; i<K; ++i)
        {
            for (j=0; j<K; ++j)
            {
                if ( dest[j]==dest[i] )
                    dest[j] = INF;
            }
        }// remove the same destination

        printf("%d\n", bfs());
    }// End of while
    
    return 0;
}
