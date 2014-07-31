#include <stdio.h>

#define POW_2 ((x)*(x))
#define POW_3 ((x)*(POW_2))
#define POW_5 ((POW_2)*(POW_3))
#define POW_6 ((x)*(POW_5))
#define POW_7 ((x)*(POW_6))

int    T;
double y, l, r, m, ans;

double res(double x)
{
    return (6*POW_7 + 8*POW_6 + 7*POW_3 + 5*POW_2 - y*x);
}/* res */

double fc(double x)
{
    return (42*POW_6 + 48*POW_5 + 21*POW_2 + 10*x - y);
}/* fc */

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lf", &y);
            
        l=0.0, r=100.0;
        while (r-l > 1e-6)
        {
            m = (l+r)/2.0;
            ans = fc(m);
            if (ans > 0)
                r = m - (1e-6);
            else
                l = m + (1e-6);
        }/* End of While */
        
        printf("%.4lf\n", res((l+r)/2.0));
    }/* End of While */
    
    return 0;
}
