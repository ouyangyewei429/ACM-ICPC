/*
PROG:   Ê¤Àû´óÌÓÍö(Ðø)
ID  :   ouyangyewei
LANG:   C++
*/
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory.h>
using namespace std;

//#define onlinejudge

const int maxn = 24;

char maze[maxn][maxn];
bool IsSolved, hash[maxn][maxn][1030];
int  N, M, T, sx, sy, tx, ty;
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
int  key_number[] = {1,2,4,8,16,32,64,128,256,512};
typedef struct node
{
    int x, y, t, keys;
}NODE;

void bfs()
{
    NODE    c, n;
    queue <NODE> q;
    
    c.x=sx, c.y=sy, c.t=0, c.keys=0;
    IsSolved=false, hash[sx][sy][0]=true;
    
    q.push(c);
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        if (c.x==tx && c.y==ty)
        {
			if (c.t < T)
			{
				IsSolved = true;
				printf("%d\n", c.t);
			}

            break;
        }/* Reach to Exit */
        
        for (int i=0; i<4; ++i)
        {
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            char pos = maze[n.x][n.y];
            
            if (n.x<0 || n.y<0 || n.x>=N || n.y>=M || pos=='*')
                continue;
            
            if (pos>='a' && pos<='j')
            {
                n.keys = c.keys|key_number[pos-'a'];
            }/* keys */
            else if (pos>='A' && pos<='J')
            {
                if (c.keys & key_number[pos-'A'])
                    n.keys = c.keys;
                else
                    continue;
            }/* doors */
            else
                n.keys = c.keys;
            
            if (hash[n.x][n.y][n.keys])
                continue;
            
            n.t = c.t + 1;
            hash[n.x][n.y][n.keys] = true;
            q.push(n);
        }/* End of For */
    }/* End of While */
    if (!IsSolved)
        printf("-1\n");
    
    return ;
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1429.txt", "r", stdin);
    freopen("E:\\hdoj_1429_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d %d", &N, &M, &T))
    {
        memset(hash, false, sizeof(hash));
        
        for (int i=0; i<N; ++i)
        {
            //getchar();
            for (int j=0; j<M; ++j)
            {
				cin >> maze[i][j];
                //scanf("%c", &maze[i][j]);
                if (maze[i][j] == '@')
                    sx=i, sy=j, maze[i][j]='.';
                if (maze[i][j] == '^')
                    tx=i, ty=j, maze[i][j]='.';
            }
        }/* End of For */
        
        bfs();
    }/* End of While */
    
    return 0;
}
