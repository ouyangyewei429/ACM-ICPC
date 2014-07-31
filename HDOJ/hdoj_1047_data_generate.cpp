/*
PROG:   test
ID  :   ouyangyewei
LANG:   C++
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int T, len, dig, rt=0;

int main()
{
    freopen("E:\\hdoj_1715.txt", "w", stdout);
    
    srand( (unsigned)time(NULL) );
    
    T=100;
    printf("%d\n\n", T);
    for (int i=1; i<=T; ++i)
    {
        printf("%d\n", rand()%50+1);
    }
    
    return 0;
}
