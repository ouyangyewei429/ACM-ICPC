/*
PROG:   Reverse Text
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

const int maxn = 80;

int  T;
char line[maxn];

int main()
{
    scanf("%d", &T);
    getchar();
    while ( T-- )
    {
        gets( line );
        for (int i=strlen(line)-1; i>=0; --i)
            printf("%c", line[i]);
        printf("\n");
    }/*  End of while */
    
    return 0;
}
