/*
PROG:   Design T-Shirt
ID  :   ouyangyewei
LANG:   C++
*/
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <algorithm> 
using namespace std;

double score;
int N, M, K, i, cnt, result[1004];

int main()
{
    while (~scanf("%d %d %d", &N, &M, &K))
    {
        map <int, double> data;
        for (i=1; i<=N; ++i)
        {
            for (int j=1; j<=M; ++j)
            {
                scanf("%lf", &score);
                data.insert( make_pair(j, score) );
            }
        }
        
        cnt = 0;
        map <int, double>::iterator iter;
        for (iter=data.begin(); iter!=data.end(); ++iter)
            result[cnt++] = iter->first;
        
        for (i=cnt-1; i>=0&&K; --i, --K)
            printf(i==cnt-1 ? "%d":" %d", result[i]);
        printf("\n");
    }// End of while
    
    return 0;
}
