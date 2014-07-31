/*
PROG:   Blurred Vision
ID  :   ouyangyewei
LANG:   C++
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
using namespace std;

#define DEBUG 0

const int maxn = 12;

int  R, C, i, j;
char cmd[maxn], graph[maxn][maxn];

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1218.txt", "r", stdin);
    freopen("E:\\hdoj_1218_ans.txt", "w", stdout);
#endif

    while ( cin >> cmd )
    {   // EOF!=scanf("%s", cmd)
        if ( !strcmp(cmd, "ENDOFINPUT") )
            break;
        
        if ( !strcmp(cmd, "START") )
        {
            memset(graph, 0, sizeof(graph));
            
            scanf("%d %d", &R, &C);
            for (i=0; i<R; ++i)
            {
                getchar();
                for (j=0; j<C; ++j)
                    scanf("%c", &graph[i][j]);
            }// Input
            
            for (i=0; i<R-1; ++i)
            {
                for (j=0; j<C-1; ++j)
                    graph[i][j] = ( (graph[i][j]-'0')+(graph[i+1][j]-'0')
                    +(graph[i][j+1]-'0')+(graph[i+1][j+1]-'0') )/4 + '0';
            }// graph compress
        }
        else if ( !strcmp(cmd, "END") )
        {
            for (i=0; i<R-1; ++i)
            {
                for (j=0; j<C-1; ++j)
                    printf("%c", graph[i][j]);
                printf("\n");
            }// display
        }
        
        //getchar();
    }// End of while
    
    return 0;
}
