/*
PROG:   前m大的数
ID  :   ouyangyewei
LANG:   C++
*/
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
using namespace std;

const int maxn = 3004;

int N, M, i, j, data[maxn];

inline int compare(int c, int d)
{
    return c > d;
}// compare

int main()
{
    while (~scanf("%d %d", &N, &M))
    {
        for (i=0; i<N; ++i)
            scanf("%d", &data[i]);

        vector <int> result;
        for (i=0; i<N; ++i)
        {
            for (j=i+1; j<N; ++j)
                result.push_back(data[i]+data[j]);
        }// plus between two figures
        
        sort(result.begin(), result.end(), compare);
        for (i=0; i<M; ++i)
            printf(i==0 ? "%d":" %d", result[i]);
        printf("\n");
    }/* End of While */
    
    return 0;
}
