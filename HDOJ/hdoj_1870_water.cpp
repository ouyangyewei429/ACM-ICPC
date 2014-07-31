/*
PROG:   愚人节的礼物
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

const int maxn = 1024;

int  i, slen, cnt;
char package[maxn];

int main()
{
    while ( EOF!=scanf("%s", package) )
    {
        slen = strlen(package);
        for (i=0; i<=slen/2; ++i)
        {
            if ( package[i]=='B'||package[slen-i-1]=='B' )
            {
                printf("%d\n", i);
                break;
            }
        }/* Main Process */
    }/* End of while */
    
    return 0;
}
