/*
PROG:   Tempter of the Bone II
ID  :   ouyangyewei
LANG:   C++
*/
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
using namespace std;

//#define onlinejudge

const int maxn = 10;

char maze[maxn][maxn];
bool IsSolved, hash[maxn][maxn][60];
int  N, M, sx, sy, tx, ty;
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
typedef struct node
{
    int x, y, t, explodes;
    bool operator < (const node &a) const
    {
        return a.t < t;
    }
}NODE;

void bfs()
{
    NODE    c, n;
    priority_queue <NODE> q;
    
    c.x=sx, c.y=sy, c.t=0, c.explodes=0;
    IsSolved=false, hash[sx][sy][0]=true;
    
    q.push(c);
    while (!q.empty())
    {
        c = q.top();
        q.pop();

		//---------------------------------
		//printf("%d %d %d %d\n", c.x, c.y, c.t, c.explodes);
        //------------------------------------

        if (c.x==tx && c.y==ty)
        {
            IsSolved = true;
            printf("%d\n", c.t);
            return ;
        }/* End of IF */
        
        for (int i=0; i<4; ++i)
        {
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
                
            if (n.x<0 || n.y<0 || n.x>=N || n.y>=M)
                continue;
            
			if (maze[n.x][n.y] == '.')
			{
				n.t = c.t + 1, n.explodes = c.explodes;
                if (hash[n.x][n.y][n.explodes]) continue;

				hash[n.x][n.y][n.explodes] = true;
                q.push(n);
			}
            else if (maze[n.x][n.y]>='1' && maze[n.x][n.y]<='9')
            {
                n.explodes=c.explodes+(maze[n.x][n.y]-'0');
				n.t=c.t+1, maze[n.x][n.y] = '.';;
                if (hash[n.x][n.y][n.explodes]) continue;

				hash[n.x][n.y][n.explodes] = true;
                q.push(n);
            }
            else if (maze[n.x][n.y]=='X' && c.explodes>0)
            {
                maze[n.x][n.y]='.';
				n.explodes=c.explodes-1, n.t=c.t+2;
                if (hash[n.x][n.y][n.explodes]) continue;

				hash[n.x][n.y][n.explodes] = true;
                q.push(n);
            }    
        }/* End of For */
    }/* End of While */
    if (!IsSolved)
        printf("-1\n");
    
    return ;
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2128.txt", "r", stdin);
    freopen("E:\\hdoj_2128_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &N, &M), N+M!=0)
    {
        memset(hash, false, sizeof(hash));
        
        for (int i=0; i<N; ++i)
        {
            getchar();
            for (int j=0; j<M; ++j)
            {
                scanf("%c", &maze[i][j]);
                if (maze[i][j] == 'S')
                    sx=i, sy=j, maze[i][j]='.';
                if (maze[i][j] == 'D')
                    tx=i, ty=j, maze[i][j]='.';
            }
        }/* prepare */
        
        bfs();
    }/* End of While */
    
    return 0;
}
