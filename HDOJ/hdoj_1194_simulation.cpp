/*
PROG:   Beat the Spread!
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

bool IsSolved;
int  T, sum, diff, i, j;

int main()
{
    scanf("%d", &T);
    while ( T-- )
    {
        scanf("%d %d", &sum, &diff);
        
        IsSolved = false;
        for (i=0; i<=(sum>>1); ++i)
        {
            if ( sum-2*i==diff )
            {
                IsSolved = true;
                printf("%d %d\n", sum-i, i);
                break;
            }
        }// Main Process
        if ( !IsSolved )
            printf("impossible\n");
    }// End of while
    
    return 0;
}
