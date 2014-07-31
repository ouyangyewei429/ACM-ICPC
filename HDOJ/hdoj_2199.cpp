#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define POW_2 ((x)*(x))
#define POW_3 ((x)*(POW_2))
#define POW_4 ((POW_2)*(POW_2))

int    T;
double y, l, r, m, ans;

double fc(double x)
{
    return (8*POW_4 + 7*POW_3 + 2*POW_2 + 3*x + 6);
}/* fc */

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lf", &y);
        if (y<fc(0.0) || y>fc(100.0))
        {
            printf("No solution!\n");
            continue;
        }/* End of IF */
            
        l=0.0, r=100.0;
        while (r-l > 1e-6)
        {
            m = (l+r)/2.0;
            ans = fc(m);
            if (y < ans)
                r = m - (1e-6);
            else
                l = m + (1e-6);
        }/* End of While */
        
        printf("%.4lf\n", (l+r)/2.0);
    }/* End of While */
    
    return 0;
}
