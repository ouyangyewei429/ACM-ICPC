/*
PROG:   еецШ
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <iostream>
#include <algorithm>
using namespace std;

//#define onlinejudge

const int maxn = 1004;

int i, j, N, M, G, num, cnt, score[12];
struct STUDENT
{
    char id[24];
    int m, tot_score;
}stu[maxn];

inline int compare(const void *a, const void *b)
{
    struct STUDENT *c = (struct STUDENT *)a;
    struct STUDENT *d = (struct STUDENT *)b;
    
    if (c->tot_score == d->tot_score)
	{
        if (memcmp(c->id, d->id, 20) > 0)
			return 1;
		else if (memcmp(c->id, d->id, 20) == 0)
			return 0;
        else
            return -1;
	}
	else
        return (d->tot_score - c->tot_score);
}/* compare */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1236.txt", "r", stdin);
    freopen("E:\\hdoj_1236_ans.txt", "w", stdout);
#endif

    while (~scanf("%d", &N), N!=0)
    {
        memset(score, 0, sizeof(score));
        memset(stu, 0, sizeof(stu));
        
        scanf("%d %d", &M, &G);
        for (i=1; i<=M; ++i)
            scanf("%d", &score[i]);
        
        for (i=0, cnt=0; i<N; ++i)
        {
            cin >> stu[i].id >> stu[i].m;
            for (j=0,stu[i].tot_score=0; j<stu[i].m; ++j)
            {
                scanf("%d", &num);
                stu[i].tot_score += score[num];
            }// loop_2
            if (stu[i].tot_score >= G)
                ++cnt;
        }// input
        
        qsort(stu, N, sizeof(stu[0]), compare);
        
        printf("%d\n", cnt);
        for (i=0; i<cnt; ++i)
            printf("%s %d\n", stu[i].id, stu[i].tot_score);
    }/* End of While */
    
    return 0;
}
