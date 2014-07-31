/*
PROG:   »­8
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char alpha;
int  T, i, j, col, rowup, rowdown, height, rt=0;

int main()
{
    scanf("%d", &T);
    while ( T-- )
    {
        if ( rt )   printf("\n");
        rt = 1;
        
        getchar();
        scanf("%c %d", &alpha, &height);
        
        col = height/6+1;
        rowup = (height-3)/2;
        rowdown = (height-3)/2+(height-3)%2;
        
        for (i=1; i<=col; ++i)  printf(" ");
        for (i=1; i<=rowdown; ++i)  printf("%c", alpha);
        printf("\n");
        
        for (i=1; i<=rowup; ++i)
        {
            for (j=1; j<=col; ++j)  printf("%c", alpha);
            for (j=1; j<=rowdown; ++j)  printf(" ");
            for (j=1; j<=col; ++j)  printf("%c", alpha);
            printf("\n");
        }
        
        for (i=1; i<=col; ++i)  printf(" ");
        for (i=1; i<=rowdown; ++i)  printf("%c", alpha);
        printf("\n");
        
        for (i=1; i<=rowdown; ++i)
        {
            for (j=1; j<=col; ++j)  printf("%c", alpha);
            for (j=1; j<=rowdown; ++j)  printf(" ");
            for (j=1; j<=col; ++j)  printf("%c", alpha);
            printf("\n");
        }
        
        for (i=1; i<=col; ++i)  printf(" ");
        for (i=1; i<=rowdown; ++i)  printf("%c", alpha);
        printf("\n");
    }/* End of while */
    
    return 0;
}
