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

const int maxn = 30;

int N, M, K, i, j, dif, cnt, limit, list[maxn], fig[maxn];
struct NODE
{
    int a, b;
}node;

inline int compare(struct NODE c, struct NODE d)
{
    if (c.b == d.b)
        return c.a<d.a;
    else
        return c.b<d.b;
}/* compare */

inline bool bin_search(int target)
{
    int mid, left=0, right=K-1;
    
    while (left <= right)
    {
        mid = (left+right)>>1;
        if (list[mid] == target)
            return true;
        else if (list[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }/* End of While */
    
    return false;
}/* bin_search */

int main()
{
    while (~scanf("%d %d", &N, &M))
    {
        K = 0;
        for (i=0; i<=M; ++i)
        {
            for (j=i+1; j<=M; ++j)
                list[K++] = i*i+j*j;
        }/* preprocess */

        sort(list, list+K);   /* sort in ascending order */
        vector <NODE> result;

        cnt=0;
        for (dif=1; dif<=M; ++dif)
        {
            for (j=0; j<K&&cnt<=N; ++j)
            {
                if (cnt == 0)
                    fig[cnt++]=list[j];
                else if (bin_search(fig[cnt-1]+dif))
                    fig[cnt++]=list[j];
            }/* Loop_2 */
            if (cnt >= N)
            {
                node.a=fig[0], node.b=dif;
                result.push_back(node);
            }
        }/* Loop_1 */

        sort(result.begin(), result.end(), compare);
        for (i=0; i<result.size(); ++i)
            printf("%d %d\n", result[i].a, result[i].b);
        printf("\n");
    }/* End of While */
    
    return 0;
}
