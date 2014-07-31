/*
PROG:   Keep on Truckin'
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int X, height, rt=1;

int main()
{
    X = -1;
    for (int i=1; i<=3; ++i)
    {
        scanf("%d", &height);
        if ( rt && height<168 )
            rt=0, X=height;
    }
    
    if ( X==-1 )
        printf("NO CRASH\n");
    else
        printf("CRASH %d\n", X);
        
    return 0;
}
