/*
PROG:   castle
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>

const int maxn = 256;

bool hash[maxn][maxn];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
int  maze[maxn][maxn]={0};
int  N, M, t, roomNums, maxRooms, wallRooms;

void dfs_Rooms(int x, int y, int sum)
{
    if ( sum>maxRooms ) maxRooms=sum;
    
    hash[x][y] = true;
    for ( int i=0; i<4; ++i )
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        
        if ( nx<1 || ny<1 || nx>N+N || ny>M+M ) continue;
        if ( maze[nx][ny]!=-1 && !hash[nx][ny] )
            dfs_Rooms( nx, ny, sum+maze[nx][ny] );
    }// Main Process
    
    return ;
}// dfs

int main()
{
    freopen("E:\\castle.txt", "r", stdin);
    freopen("E:\\castle_ans.txt", "w", stdout);

    scanf("%d %d", &M, &N);
    for (int i=0; i<=N+N+1; ++i)
    {
        for (int j=0; j<=M+M+1; ++j)
        {
            if ( i==0 || i==N+N+1 )
                maze[i][j] = -1;
            if ( j==0 || j==M+M+1 )
                maze[i][j] = -1;
        }
    }// preprocess
    
    for (int i=1, x=1; i<=N&&x<=N+N; ++i, x+=2)
    {
        for (int j=1, y=1; j<=M&&y<=M+M; ++j, y+=2)
        {
            maze[x][y] = 1;
            scanf("%d", &t);
            switch ( t )
            {
                case 1: maze[x][y-1]=-1; break;
                case 2: maze[x-1][y]=-1; break;
                case 4: maze[x][y+1]=-1; break;
                case 8: maze[x+1][y]=-1; break;
                case 3: maze[x][y-1]=maze[x-1][y]=-1; break;
                case 5: maze[x][y-1]=maze[x][y+1]=-1; break;
                case 9: maze[x][y-1]=maze[x+1][y]=-1; break;
                case 10: maze[x-1][y]=maze[x+1][y]=-1; break;
                case 6: maze[x-1][y]=maze[x][y+1]=-1; break;
                case 12: maze[x][y+1]=maze[x+1][y]=-1; break;
                case 7: maze[x][y-1]=maze[x][y+1]=-1, maze[x-1][y]=-1; break;
                case 11: maze[x-1][y]=maze[x+1][y]=-1, maze[x][y-1]=-1; break;
                case 13: maze[x][y-1]=maze[x][y+1]=-1, maze[x+1][y]=-1; break;
                case 14: maze[x-1][y]=maze[x+1][y]=-1, maze[x][y+1]=-1; break;
                case 15: maze[x-1][y]=maze[x+1][y]=-1, maze[x][y-1]=maze[x][y+1]=-1; break;
            }
        }
    }// preprocess

    roomNums=0, maxRooms=-1;
    for ( int i=1; i<=N+N; ++i )
    {
        for ( int j=1; j<=M+M; ++j )
        {
            if ( !hash[i][j] && maze[i][j]!=-1 )
            {
                ++roomNums;
                dfs_Rooms( i, j, maze[i][j] ); /* coordinate x and y, room_sizes */
            }
        }
    }// counting the rooms
    
    printf("%d\n%d\n", roomNums, maxRooms);
    
    //system("pause");
    return 0;
}
/*
    for (int i=0; i<=N+N+1; ++i)
    {
        for (int j=0; j<=M+M+1; ++j)
        {
            if ( maze[i][j]==-1 )
                printf("#");
            else if ( maze[i][j]==1 )
                printf("*");
            else if ( maze[i][j]==0 )
                printf("0");
        }
        printf("\n");
    }// preprocess
*/
