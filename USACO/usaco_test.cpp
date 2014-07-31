/*
ID: ouyangy4
LANG:   C++
PROG:   test
*/
#include <stdio.h>

int a, b;

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    
    while (~scanf("%d %d", &a, &b))
    {
        printf("%d\n", a+b);
    }
    
    return 0;
}
