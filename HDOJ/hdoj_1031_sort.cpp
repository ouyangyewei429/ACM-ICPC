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

double temp;
int N, M, K, i, j, result[1004];
struct DATA
{
    int num;
    double score;
}data[1004];

int compare(const void *a, const void *b)
{
    DATA *c = (DATA *)a;
    DATA *d = (DATA *)b;
    
    if ( c->score == d->score )
        return ( c->num - d->num );
    else
        return ( d->score>c->score ? 1:-1 );
}// compare

int cmp(int c, int d)
{
    return c>d;
}// cmp

int main()
{
    while (~scanf("%d %d %d", &N, &M, &K))
    {
        memset(data, 0, sizeof(data));
        for (i=1; i<=N; ++i)
        {
            for (int j=0; j<M; ++j)
            {
                scanf("%lf", &temp);
                data[j].num=j+1, data[j].score+=temp;
            }
        }// Input
        
        qsort(data, M, sizeof(data[0]), compare);
        for (i=0; i<K; ++i)
        {
            //printf("%d %.2lf\n", data[i].num, data[i].score);
            result[i] = data[i].num;
        }// remove the same score

        sort(result, result+K, cmp);
        for (i=0; i<K; ++i)
            printf(i==0 ? "%d":" %d", result[i]);
        printf("\n");
    }// End of while
    
    return 0;
}
