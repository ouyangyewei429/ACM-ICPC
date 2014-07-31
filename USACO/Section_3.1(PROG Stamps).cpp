/*
PROG:   stamps
ID  :   ouyangyewei
LANG:   C++
*/
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <algorithm>
using namespace std;

namespace   
{
    bool hash[2000002];
    int  K, N, ans, stValue[52];
    struct STAMP
    {
        int cents, coins;
    };
}// Non Name Space

void ReadData()
{
    scanf("%d %d", &K, &N);
    for ( int i=0; i<N; ++i )
        scanf("%d", &stValue[i]);
}// ReadData

void Bfs()
{
    STAMP c, n;
    queue <STAMP> q;
    
    ans = 0;    // record the number of contiguous postage values
    c.cents=0, c.coins=0;
    q.push( c );
    while ( !q.empty() )
    {
        c = q.front();
        q.pop();
        
        for ( int i=0; i<N; ++i )
        {
            n.cents = c.cents+stValue[i];
            n.coins = c.coins+1;
            if ( n.coins>K || hash[ n.cents ] ) continue;
            
            //----------
            //printf("%2d %d %d\n", n.cents, n.coins, ans+1);
            //------------------------------------
            
            ++ans;
            hash[ n.cents ] = true;
            q.push( n );
        }
    }// End of while
    
    printf("%d\n", ans);
    return ;
}// Bfs

int main()
{
    freopen("E:\\stamps.in", "r", stdin);
    freopen("E:\\stamps.out", "w", stdout);
    
    ReadData();
    Bfs();
    
    return 0;
}
/*
5 2
1 3

13
-----------
2 4
1 2 4 8

6
-----------
*/
