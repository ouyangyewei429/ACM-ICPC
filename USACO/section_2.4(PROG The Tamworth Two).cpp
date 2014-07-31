/*
PROG:   ttwo
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 20;

char graph[maxn][maxn];
int  fx, fy, cx, cy;
int  dx[] = {-1, 0, 1, 0};
int  dy[] = {0, 1, 0, -1};
int  cow[maxn][maxn][4], farmer[maxn][maxn][4];

void ReadData()
{// read the forests
    for ( int i=0; i<10; ++i )
    {
        for ( int j=0; j<10; ++j )
        {
            scanf("%c", &graph[i][j]);
            if ( graph[i][j]=='C' )
                cx=i, cy=j, graph[i][j]='.';
            if ( graph[i][j]=='F' )
                fx=i, fy=j, graph[i][j]='.';
        }

		getchar();
    }
}// ReadData

bool IsOut( int x, int y )
{
    return ( x<0 || y<0 || x>=10 || y>=10 );
}// IsOut

void Simulation()
{
    int  k, fnx, fny, cnx, cny, ti=0;
    int  fstep=0, cstep=0, fdir=0, cdir=0;
    
    while ( fstep<=400 && cstep<=400 )
    {
        if ( fx==cx && fy==cy )
            break;
        
        // Farmer John
        fnx = fx+dx[ fdir ], fny = fy+dy[ fdir ];
        if ( !IsOut( fnx, fny ) && graph[fnx][fny]!='*' )
            fx=fnx, fy=fny, ++fstep;
        else
            fdir = ( fdir+1 )%4;
        
        // Cow
        cnx = cx+dx[ cdir ], cny = cy+dy[ cdir ];
        if ( !IsOut( cnx, cny ) && graph[cnx][cny]!='*' )
            cx=cnx, cy=cny, ++cstep;
        else
            cdir = ( cdir+1 )%4;
        
        ++ti;
    }// End of while
    if ( fstep<=400 && cstep<=400 )
        printf("%d\n", ti);
    else
        printf("0\n");
}// simulation

int main()
{
    freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w", stdout);

    ReadData();
    Simulation();
    
//    system("pause");
    return 0;
}
