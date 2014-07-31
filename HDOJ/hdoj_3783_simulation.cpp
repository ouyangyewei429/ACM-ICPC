/*
PROG:   ZOJ
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int  zoj[3];
char bunch[104];

int main()
{
    while ( ~scanf("%s", bunch), bunch[0]!='E' )
    {
        zoj[0]=zoj[1]=zoj[2]=0;
        for (int i=0; i<strlen(bunch); ++i)
        {
            if ( bunch[i]=='Z' )
                zoj[0]++;
            else if ( bunch[i]=='O' )
                zoj[1]++;
            else if ( bunch[i]=='J' )
                zoj[2]++;
        }// counting
        
        for (; zoj[0]!=0||zoj[1]!=0||zoj[2]!=0; )
        {
            if ( zoj[0]!=0 )
            {
                --zoj[0];
                printf("Z");
            }
            if ( zoj[1]!=0 )
            {
                --zoj[1];
                printf("O");
            }
            if ( zoj[2]!=0 )
            {
                --zoj[2];
                printf("J");
            }
        }// output
        
        printf("\n");
    }// End of while
    
    return 0;
}
