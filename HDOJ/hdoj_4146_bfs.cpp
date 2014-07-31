/*
PROG:   Flip Game
ID  :   ouyangyewei
LANG:   C++
*/
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

//#define onlinejudge

const int maxn = 4;

int  T, sum;
char chess[maxn*maxn];
bool IsSolved, hash[66000];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
typedef struct node
{
    int t, bin;
}NODE;

bool IsOut(int x, int y)
{
    return (x<0 || y<0 || x>=4 || y>=4);
}/* IsOut */

int bin_changes(int x, int y, int k, int fig)
{
    fig ^= (1<<(15-k));
    for (int i=0; i<4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        int nk = nx*4 + ny;
        
        if (IsOut(nx, ny))
            continue;
        
        fig ^= (1<<(15-nk));
    }/* End of For */
    
    return fig;
}/* bin_changes */

void bfs()
{
    NODE    c, n;
    queue <NODE> q;
    
    c.t=0, c.bin=sum;
    IsSolved=false, hash[sum]=true;
    
    q.push(c);
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        if (c.bin==0 || c.bin==65535)
        {
            IsSolved = true;
            printf("%d\n", c.t);
            return ;
        }/* destination */
        
        for (int i=0; i<16; ++i)
        {
            int nx = i/4, ny = i%4;
            
            n.bin = bin_changes(nx, ny, i, c.bin);
            if (hash[n.bin])
                continue;
            
            n.t = c.t + 1;
            hash[n.bin] = true;
            q.push(n);
        }/* End of For */
    }/* End of While */
    if (!IsSolved)
        printf("Impossible\n");
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\zoj_2050.txt", "r", stdin);
    freopen("E:\\zoj_2050_ans.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--)
    {
        sum = 0;
        for (int i=0; i<16; ++i)
        {
            cin >> chess[i];
            
            sum <<= 1;
            if (chess[i] == 'b')
                sum++;
        }/* preprocess */
        
        if (sum==0 || sum==65535)
        {
            printf("0\n");
            continue;
        }
        else
        {
            memset(hash, false, sizeof(hash));
            bfs();
        }
    }/* End of While */
    
    return 0;
}
