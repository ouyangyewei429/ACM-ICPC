/*
PROG:   Prerequisites?
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <memory.h>

const int maxn = 1004;

int  result[maxn];
char ss[maxn], line[maxn];

int main()
{
    while ( gets( ss ) )
    {
        if ( ss[0]=='#' )   break;

        gets( line );
        memset(result, 0, sizeof(result));
        for (int i=0; i<strlen(line); ++i)
        {
            for (int j=0; j<strlen(ss); ++j)
            {
                if (ss[j] == line[i])
                    result[j]++;
            }
        }// Main Process
        
        for (int i=0; i<strlen(ss); ++i)
            printf("%c %d\n", ss[i], result[i]);
    }// End of while
    
    return 0;
}
