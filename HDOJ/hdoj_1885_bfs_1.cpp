/*
PROG:   Key Task
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

const int maxn = 104;

char maze[maxn][maxn];
bool IsSolved, hash[maxn][maxn][20];
int  N, M, sx, sy, exits;
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
typedef struct node
{
    int x, y, t, keys;
}NODE;

int key_number(char c)
{
    if (c=='b' || c=='B')   return 8;
    if (c=='y' || c=='Y')   return 4;
    if (c=='r' || c=='R')   return 2;
    if (c=='g' || c=='G')   return 1;
}/* key_number */

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
        
        if (maze[c.x][c.y] == 'X')
        {
            IsSolved = true;
            printf("Escape possible in %d steps.\n", c.t);
            return ;
        }/* Reach to Exit */
        
        for (int i=0; i<4; ++i)
        {
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            char pos = maze[n.x][n.y];
            
            if (n.x<0 || n.y<0 || n.x>=N || n.y>=M || pos=='#')
                continue;
            
            if (pos=='b' || pos=='y' || pos=='r' || pos=='g')
            {
                n.keys = c.keys|key_number(pos);
            }/* The keys */
            else if (pos=='B' || pos=='Y' || pos=='R' || pos=='G')
            {
                if (c.keys & key_number(pos))
                    n.keys = c.keys;
                else
                    continue;
            }/* The doors */
            else
            {
                n.keys = c.keys;
            }/* The Empty place or the end point */
            
            if (hash[n.x][n.y][n.keys])
                continue;
            
            n.t = c.t + 1;
            hash[n.x][n.y][n.keys] = true;
            q.push(n);
        }/* End of For */
    }/* End of While */
    if (!IsSolved)
        printf("The poor student is trapped!\n");
    
    return ;
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1885.txt", "r", stdin);
    freopen("E:\\hdoj_1885_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &N, &M), N+M!=0)
    {
        //memset(maze, 0, sizeof(maze));
        memset(hash, false, sizeof(hash));
        
        exits = 0;
        for (int i=0; i<N; ++i)
        {
            getchar();
            for (int j=0; j<M; ++j)
            {
                //cin >> maze[i][j];
                scanf("%c", &maze[i][j]);
                if (maze[i][j] == '*')
                    sx=i, sy=j, maze[i][j]='.';
                if (maze[i][j] == 'X')
                    ++exits;
            }
        }/* End of For */
        
        if (exits == 0)
        {
            printf("The poor student is trapped!\n");
            continue;
        }/* Case of No Exit */
        
        bfs();
    }/* End of While */
    
    return 0;
}
