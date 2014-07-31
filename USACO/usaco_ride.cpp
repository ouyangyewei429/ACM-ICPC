/*
ID:     ouyangyewei
PROG:   ride
LANG:   C++
*/
#include <stdio.h>
#include <string.h>

int  c, g;
char a[10], b[10];

int main()
{
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    
    while (~scanf("%s %s", a, b))
    {
        c = g = 1;
        for (int i=0; i<strlen(a); ++i)
            c *= (a[i]-'A'+1);
        for (int i=0; i<strlen(b); ++i)
            g *= (b[i]-'A'+1);
        
        if (c%47 == g%47)
            printf("GO\n");
        else
            printf("STAY\n");
    }/* End of While */
    
    return 0;
}
