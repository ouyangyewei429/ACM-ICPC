/*
PROG:   The Frog's Games
ID  :   ouyangyewei
LANG:   C++
*/
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
using namespace std;

//#define onlinejudge

const int maxn = 500004;

int L, N, M, stone[maxn]={0};

int main()
{
#ifdef onlinejudge
	freopen("E:\\hdoj_4004.txt", "r", stdin);
	freopen("E:\\hdoj_4004_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d %d", &L, &N, &M))
    {
        if (N==0)
        {
            printf("%d\n", L);
            continue;
        }
        
        for (int i=1; i<=N; ++i)
            scanf("%d", &stone[i]);
        
        stone[0]=0, stone[N+1]=L;
        sort(stone+1, stone+N+2);   // sort in ascending order

		int max_dis = 0;
		for (int k=1; k<=N+1; ++k)
		{
			if (stone[k]-stone[k-1] > max_dis)
				max_dis = stone[k]-stone[k-1];
		}// Find the greatest value between two figure
        
        int mid, left=max_dis, right=L;
        while (left <= right)
        {
            mid = (left+right)>>1;
            
            int pos=0, cnt=0;
            for (int j=1; j<=N; ++j)
            {
				if (stone[j]-stone[pos]<=mid && stone[j+1]-stone[pos]>mid)
				    ++cnt, pos=j;
            }/* Jump over the river */
            
            ++cnt;
            if (cnt <= M)
                right = mid-1;
            else
                left = mid+1;
        }// Binary_Search
        
        printf("%d\n", left);
    }/* End of While */
    
    return 0;
}
