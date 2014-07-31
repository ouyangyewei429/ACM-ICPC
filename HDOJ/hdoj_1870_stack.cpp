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

int  i, top, cnt;
char package[maxn], stack[maxn];

int main()
{
    while ( EOF!=scanf("%s", package) )
    {
        top = -1;
        memset(stack, 0, sizeof(stack));
        for (i=0; i<strlen(package); ++i)
        {
            if ( package[i]=='('||package[i]=='B' )
                stack[++top] = package[i];
            else if ( package[i]==')' )
            {
                if ( stack[top]=='(' )
                    stack[top--]='0';
                else
                    stack[++top]=package[i];
            }
        }// simulation
        
        cnt = 0;
        for (i=0; i<top; ++i)
        {
            if ( stack[i]=='(' )
                ++cnt;
        }// counting
        
        printf("%d\n", cnt);
    }// End of while
    
    return 0;
}
