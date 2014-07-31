/*
PROG:   Can you solve this equation?
ID  :   ouyangyewei
LANG:   C++
*/
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
using namespace std;

#define POW_2 ((x)*(x))
#define POW_3 ((x)*POW_2)
#define POW_4 (POW_2*POW_2)

const double EPS = 1e-6;

int T;
double y, left, right, mid;

inline double fx(double x)
{
    return (8*POW_4+7*POW_3+2*POW_2+3*x+6);
}// fx

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lf", &y);
        
        if (y<fx(0.0) || y>fx(100.0))
        {
            printf("No solution!\n");
            continue;
        }// No x for Y will be negative figure
        
        left=0.0, right=100.0;
        while (right-left >= EPS)
        {
            mid = (left+right)/2.0;
            if (fx(mid) > y)
                right = mid-EPS;
            else
                left = mid+EPS;
        }// binary_search

        printf("%.4lf\n", (left+right)/2.0);
    }/* End of While */
    
    return 0;
}
