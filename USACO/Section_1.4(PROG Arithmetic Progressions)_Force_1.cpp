/*
PROG:   ariprog
ID  :   ouyangyewei
LANG:   C++
*/
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <algorithm>
using namespace std;

const int maxn = 130001;

bool IsSolved, hash[maxn]={false};
int  N, M, K, i, j, a, b, limit, s[maxn]={0};

int main()
{
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);

    while (~scanf("%d %d", &N, &M))
    {
        for (i=0; i<=M; ++i)
        {
            for (j=i; j<=M; ++j)
                hash[i*i+j*j] = true;
        }/* preprocess */
        
        K=1, limit=2*M*M;
        for (i=0; i<=limit; ++i)
        {
            if (hash[i])
                s[K++] = i;
        }/* save the ingeter */
        
        K--;    /* K start from 1 */
        for (b=1; b*(N-1)<=limit; ++b)
        {
            for (i=1; i<=K-N&&s[i]+b*(N-1)<=limit; ++i)
            {   // i<=K-N&&s[i]+b*(N-1)<=limit
                a = s[i];
                for (j=N-1; j>=1; --j)
                {
                    if (!hash[a+b*j])
                        break;
                }/* Length N-1 */
                if (j == 0)
                {
                    IsSolved = true;
                    printf("%d %d\n", a, b);
                }
            }
        }/* search */
        if (!IsSolved)
            printf("NONE\n");
    }/* End of While */
    
    return 0;
}
