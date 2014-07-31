#include <stdio.h>

//#define onlinejudge

const int maxn = 8;

int T, dig[maxn], cnt, pos;
int graph[4][8] = { {7,3,1,4,5,8,6,2},
                    {7,4,1,3,6,8,5,2},
                    {2,5,8,6,3,1,4,7},
                    {2,6,8,5,4,1,3,7} };

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2514.txt", "r", stdin);
    freopen("E:\\hdoj_2514_ans.txt", "w", stdout);
#endif

    scanf("%d", &T);
    for (int cas=1; cas<=T; ++cas)
    {
        for (int i=0; i<8 ;++i)
            scanf("%d", &dig[i]);
        
        cnt = 0;
        for (int i=0; i<4; ++i)
        {
            bool flag = true;
            for (int j=0; j<8; ++j)
            {
                if (dig[j] && dig[j]!=graph[i][j])
                {
                    flag = false;
                    break;
                }    
            }
            if (flag)
                ++cnt, pos=i;
        }/* End of For */
        
        printf("Case %d:", cas);
        if (cnt == 0)
            printf(" No answer\n");
        else if (cnt > 1)
            printf(" Not unique\n");
        else
        {
            for (int i=0; i<8; ++i)
                printf(" %d", graph[pos][i]);
            printf("\n");
        }
    }/* End of For */
    
    return 0;
}

