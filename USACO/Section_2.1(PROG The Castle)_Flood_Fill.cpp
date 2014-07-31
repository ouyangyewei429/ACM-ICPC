/*
PROG:   castle
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>

#define DEBUG   0

const int maxn = 55;

char dir;
bool hash[maxn][maxn]={false};
int  dx[] = {1, 0, -1, 0};
int  dy[] = {0, 1, 0, -1};
int  N, M, t, row, col, color=1, rSize=-1, maxSize=-1;
int  roomSize[maxn*maxn]={0}, castle[maxn][maxn][5]={0};

void Flood_Fill(int x, int y)
{
    hash[x][y] = true;
    roomSize[ color ]++;
    castle[x][y][4] = color;
    for (int i=0; i<4; ++i)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if ( nx<0 || ny<0 || nx>=N || ny>=M )   continue;
        if ( hash[nx][ny] || castle[x][y][i] )  continue;
        
        Flood_Fill( nx, ny );
    }
    
    return ;
}// Flood_Fill

void Merge(int x, int y)
{
    int sum;
    if ( x>=1 && castle[x-1][y][4]!=castle[x][y][4] )
    {
        sum = roomSize[ castle[x-1][y][4] ]+roomSize[ castle[x][y][4] ];
        if ( sum > maxSize )
        {
            maxSize = sum;
            row = x, col = y, dir = 'N';
        }
    }// remove the wall to north
    if ( y<M-1 && castle[x][y+1][4]!=castle[x][y][4] )
    {
        sum = roomSize[ castle[x][y+1][4] ]+roomSize[ castle[x][y][4] ];
        if ( sum > maxSize )
        {
            maxSize = sum;
            row = x, col = y, dir = 'E';
        }
    }// remove the wall to east
    
    return ;
}// Merge

int main()
{
#if DEBUG
    freopen("E:\\castle.txt", "r", stdin);
    freopen("E:\\castle_ans.txt", "w", stdout);
#endif

    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);

    scanf("%d %d", &M, &N);
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<M; ++j)
        {
            scanf("%d", &t);
            for (int k=3; k>=0; --k)
            {
                castle[i][j][k] = t%2;
                t >>= 1;
            }
            
            castle[i][j][4] = 0;
        }
    }// creat the graph

    // Coloring
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<M; ++j)
        {
            if ( !hash[i][j] )
            {
                roomSize[ color ]=0;
                Flood_Fill( i, j );
                ++color;
            }
        }
    }// End of for
    
    // Find the maximum size of room before removing wall
    for (int i=1; i<color; ++i)
    {
        if ( rSize < roomSize[ i ] )
            rSize = roomSize[ i ];
    }
    
    // Find the maximum size of room when removing wall
    for (int i=0; i<M; ++i)
    {
        for (int j=N-1; j>=0; --j)
            Merge( j, i );
    }// End of for
    
    printf("%d\n%d\n%d\n%d %d %c\n", color-1, rSize, maxSize, row+1, col+1, dir);

    //system("pause");
    return 0;
}
