/*
PROG:   Basically Speaking
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

const int maxn = 80;

char num[maxn];
int  result[maxn];
int  dig, base, tarBase, cnt, r, i;

int main()
{
    while ( EOF!=scanf("%s %d %d", num, &base, &tarBase) )
    {
        dig = 0;
        for (i=0; i<strlen(num); ++i)
        {
            if ( num[i]>='0'&&num[i]<='9' )
                dig = dig*base + (num[i]-'0');
            else
                dig = dig*base + (num[i]-'A'+10);
        }// convert to digit
        
        cnt=0, r=dig;
        while ( r!=0 )
        {
            result[cnt++] = r%tarBase;
            r /= tarBase;
        }// convert to target base
        
        if ( cnt>7 )
            printf("  ERROR\n");
        else
        {
            for (i=1; i<=7-cnt; ++i)    printf(" ");
            for (i=cnt-1; i>=0; --i)
            {
                if ( result[i]>9 )
                    printf("%c", result[i]-10+'A');
                else
                    printf("%c", result[i]+'0');
            }
            printf("\n");
        }
    }// End of while
    
    return 0;
}
