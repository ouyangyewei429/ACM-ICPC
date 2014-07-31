#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
using namespace std;

//#define onlinejudge

int i, casenum, N, ans;
double sum, r[604];

int compare(double a, double b)
{
    return a>b;
}/* compare */

int main()
{
#ifdef onlinejudge
    freopen("E:\\nyist_6.txt", "r", stdin);
    freopen("E:\\nyist_6_ans.txt", "w", stdout);
#endif

    scanf("%d", &casenum);
    while (casenum--)
    {
        scanf("%d", &N);
        for (i=0; i<N; ++i)
            scanf("%lf", &r[i]);
        
        sort(r, r+N, compare);
        
        /******
        for (i=0; i<N; ++i)
            printf("%lf ", r[i]);
        ******/

        for (i=0,sum=0; i<N; ++i)
        {
            sum += 2.0*sqrt(r[i]*r[i]-1.0);
            if (sum-20.0 >= 0.0000001)
                break;
        }/* End of For */
        
        printf("%d\n", i+1);
    }/* End of While */
    
    return 0;
}
