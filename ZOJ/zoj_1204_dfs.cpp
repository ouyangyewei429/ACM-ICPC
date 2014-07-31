/*
PROG:   Additive equations
ID  :   ouyangyewei
LANG:   C++
*/
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
using namespace std;

const int maxn = 35;

vector <int> result;
bool IsSolved;
int  T, N, num[maxn];

inline int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}/* compare */

inline bool bin_search(int target)
{
    int low, high, mid;
    
    low=0, high = N-1;
    while (low <= high)
    {
        mid = (low+high)>>1;
        if (num[mid] == target)
            return true;
        else if (num[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }/* End of While */

    return false;
}/* bin_search */

void dfs(int st, int cur_depth, int dest_depth, int sum)
{
    if (cur_depth>dest_depth || sum>num[N-1])
        return ;
    
    if (cur_depth == dest_depth)
    {
        if (bin_search(sum))
        {
            IsSolved = true;
            for (int i=0; i<dest_depth-1; ++i)
                printf("%d+", result[i]);
            printf("%d=%d\n", result[dest_depth-1], sum);
        }
    }/* destinarion_depth */
    else
    {
        for (int i=st; i<N; ++i)
        {
            if (cur_depth < result.size())
                result[cur_depth] = num[i];
            else
                result.push_back(num[i]);
            
            dfs(i+1, cur_depth+1, dest_depth, sum+num[i]);
        }
    }/* before the destination depth */
}/* dfs */

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        for (int i=0; i<N; ++i)
            scanf("%d", &num[i]);
        
        if (N < 3)
        {
            printf("Can't find any equations.\n\n");
            continue;
        }/* Case : N<3 */
        
        qsort(num, N, sizeof(num[0]), compare);
        
        IsSolved = false;
        for (int j=2; j<N; ++j)
            dfs(0, 0, j, 0); /* start_point, current_depth, destination_depth, sum */
        
        if (!IsSolved)
            printf("Can't find any equations.\n");
        printf("\n");
        
        result.clear();
    }/* End of While */
    
    return 0;
}
