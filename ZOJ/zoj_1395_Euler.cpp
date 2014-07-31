/*
PROG:   Door Man
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define DEBUG 0

const int maxn = 24;

char buf[128];
int  N, M, oddNums, evenNums, doorNums, doors[maxn];

int ReadLine(char *s)
{
    int i;
    for (i=0; ( s[i]=getchar() )!='\n' && s[i]!=EOF; ++i);
    s[i] = '\0';
    
    return i;
}// ReadLine

int main()
{
#if DEBUG
    freopen("E:\\zoj_1395.txt", "r", stdin);
    freopen("E:\\zoj_1395_ans.txt", "w", stdout);
#endif

    while ( ReadLine( buf ) )
    {
        if ( buf[0]=='S' )
        {
            sscanf( buf, "%*s %d %d", &M, &N );
            for (int i=0; i<N; ++i)
                doors[i] = 0;
            
            doorNums = 0;
            for (int i=0; i<N; ++i)
            {
                ReadLine( buf );
                
                int j, k=0;
                while ( sscanf( buf+k, "%d", &j )==1 )
                {
                    ++doorNums;
                    ++doors[i], ++doors[j];
                    while ( buf[k]!='\0' && buf[k]==' ' ) ++k;
                    while ( buf[k]!='\0' && buf[k]!=' ' ) ++k;
                }
            }// N lines
            
            ReadLine( buf );    // read the "END"
            
            oddNums = evenNums = 0;
            for (int i=0; i<N; ++i)
            {
                if ( doors[i]&1 )
                    ++oddNums;
                else
                    ++evenNums;
            }// counting degree
            
            if ( oddNums==0 && M==0 )
                printf("YES %d\n", doorNums);
            else if ( oddNums==2 && (doors[M]&1) && (doors[0]&1) && M!=0 )
                printf("YES %d\n", doorNums);
            else
                printf("NO\n");
        }// case
        else if ( !strcmp(buf, "ENDOFINPUT") )
            break;
    }// End of while
    
    return 0;
}
