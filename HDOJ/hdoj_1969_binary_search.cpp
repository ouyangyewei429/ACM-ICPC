/*
PROG:   Pie
ID  :   ouyangyewei
LANG:   C++
*/
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
//using namespace std;

//#define onlinejudge

//#define PI (acos(-1))

const int maxn = 10000;
const double PI = 3.1415926535897931;
const double EPS = 1e-6;

int T, N, F, rad, i;
double sum, pie[maxn];

inline bool judge(double mid)
{
    int j, cnt=0;
    for (j=0; j<N; ++j)
        cnt += (int)(pie[j]/mid);
    
    if (cnt >= F+1)
        return true;
    else
        return false;
}/* judge */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1969.txt", "r", stdin);
    freopen("E:\\hdoj_1969_ans.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &N, &F);
        for (i=0, sum=0.0; i<N; ++i)
        {
            scanf("%d", &rad);
			pie[i] = rad*rad*PI;
            sum += rad*rad*PI;
        }/* input */
        
        double mid, left=0, right=sum/(F+1);
        while (right-left >= EPS)
        {
            mid = (left+right)/2.0;
            if (judge(mid))
                left = mid;
            else
                right = mid;
        }/* End of While */
        
        printf("%.4lf\n", mid);
    }/* End of While */
    
    return 0;
}
