/*
PROG:   I Think I Need a Houseboat
ID  :   ouyangyewei
LANG:   C++
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define PI  3.1415926
#define EPS 1e-7

int    T, cas, years;
double x, y, r, area;

int main()
{
    while (~scanf("%d", &T))
    {
        for (cas=1; cas<=T; ++cas)
        {
            scanf("%lf %lf", &x, &y);
            
            r = sqrt( x*x+y*y );
            area = PI*r*r/2.0;  // point of area
            
            years = (int)( area/50.0 )+1;
            printf("Property %d: This property will begin eroding in year %d.\n", cas, years);
        }// Cases
        
        printf("END OF OUTPUT.\n");
    }// End of while
    
    return 0;
}
