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

const int maxn = 34000;

bool IsSolved;
int  N, M, first, cnt=0, num[maxn]={0};
typedef struct node
{
    int a, b;
}NODE;
vector <NODE> result;

inline int compare(NODE c, NODE d)
{
    if (c.b == d.b)
        return c.a<d.a;
    else
        return c.b>d.b;
}/* compare */

inline bool bin_search(int target, int limit)
{
    int mid, left=0, right=limit-1;
    
    while (left <= right)
    {
        mid = (left+right<<1);
        if (num[mid] == target)
            return true;
        else if (num[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }/* End of While */
    
    return false;
}/* bin_search */

void dfs(int cur_depth, int st, int dif, int last, int limit)
{
    if (cur_depth == N)
    {
        IsSolved = true;
        return ;
    }/* End of IF */
    
    for (int i=st; i<limit; ++i)
    {
        if (cur_depth == 0)
            first = num[i];
        
        if (last==-1 && bin_search(num[i]+dif, limit))
            dfs(cur_depth+1, i+1, dif, num[i]+dif, limit);
        else if (last!=-1 && bin_search(last+dif, limit))
            dfs(cur_depth+1, i+1, dif, last+dif, limit);
        
        if (IsSolved)   return ;
    }/* End of For */
}/* dfs */

int main()
{
    while (~scanf("%d %d", &N, &M))
    {
        for (int i=0; i<=M; ++i)
        {
            for (int j=i+1; j<=M; ++j)
                num[cnt++] = i*i+j*j;
        }/* preprocess */
        
        sort(num, num+cnt);
        
        NODE temp;
        result.clear();
        for (int j=1; j<=M; ++j)
        {
            first = -1;
            IsSolved = false;
            dfs(0, 0, j, -1, cnt);  /* cur_depth, start_point, dif, last, limit */
            if (IsSolved)
            {
                temp.a = first, temp.b = j;
                result.push_back(temp);
            }
        }/* dfs */
        
        sort(result.begin(), result.end(), compare);
        for (int i=0; i<result.size(); ++i)
            printf("%d %d\n", result[i].a, result[i].b);
    }/* End of While */
    
    return 0;
}
