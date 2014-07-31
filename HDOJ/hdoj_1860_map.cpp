/*
PROG:   Í³¼Æ×Ö·û
ID  :   ouyangyewei
LANG:   C++
*/
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory.h>
using namespace std;

const int maxn = 100010;

int  result[maxn];
map <char, int> index;
char line[maxn], ss[maxn];

int main()
{
    while ( gets(ss) )
    {
        if ( ss[0]=='#' )
            break;
        
        index.clear();
        for (int i=0; i<strlen(ss); ++i)
            index[ ss[i] ] = i+1;
        
        fflush(stdin);
        gets(line);
        
        memset(result, 0, sizeof(result));
        for (int i=0; i<strlen(line); ++i)
        {
            if ( index[ line[i] ]!=0 )
                result[ index[ line[i] ] ]++;
        }
             
        for (int i=0; i<strlen(ss); ++i)
            printf("%c %d\n", ss[i], result[ index[ ss[i] ] ]);

        fflush(stdin);
    }// End of while
    
    return 0;
}
