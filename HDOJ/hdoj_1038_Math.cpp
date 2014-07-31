/*
PROG:   Biker's Trip Odometer
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

const double PI = 3.1415927;

int r, cas=1;
double d, t, s, v;

int main()
{
    while (~scanf("%lf %d %lf", &d, &r, &t))
    {
        if ( r==0 ) break;
        
        s = PI*d*r/63360, v = 3600.0*s/t;
        printf("Trip #%d: %.2lf %.2lf\n", cas++, s, v);
    }// End of while
    
    return 0;
}
