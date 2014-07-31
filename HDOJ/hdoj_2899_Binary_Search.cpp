/*
PROG:   Strange fuction
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
using namespace std;

#define POW_2 ((x)*(x))
#define POW_3 ((x)*POW_2)
#define POW_5 (POW_2*POW_3)
#define POW_6 (POW_3*POW_3)
#define POW_7 ((x)*POW_6)

const double EPS = 1e-6;

int T;
double y, left, right, mid, value;

inline double fx(double x)
{
    return 6*POW_7+8*POW_6+7*POW_3+5*POW_2-y*x;
}// f(x)

inline double gx(double x)
{
    return 42*POW_6+48*POW_5+21*POW_2+10*x-y;
}// g(x)

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lf", &y);
        
        left=0.0, right=100.0;
        while (right-left >= EPS)
        {
            mid = (left+right)/2.0;
            
            value = gx(mid);
            if (value > 0)
                right = mid-EPS;
            else
                left = mid+EPS;
        }/* End of while */
        
        printf("%.4lf\n", fx(mid));
    }/* End of While */
    
    return 0;
}
