/*
ID: ouyangyewei
LANG:   C++
PROG:   beads
*/
#include <stdio.h>
#include <string.h>

const int maxn = 400;

int  j, N, max, cnt;
char color, beans[maxn];

int main()
{
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);

    while (~scanf("%d", &N))
    {
        scanf("%s", beans);
        
        max = -1;
        for (int i=0; i<N; ++i)
        {
            cnt = 0, color='w';
            for (j=i; ; ++j)
            {
                if (beans[j%N]=='w' || beans[j%N]==color)
                {
                    if (cnt >= N)
                        break;
                    else
                        ++cnt;
                }    
                else if (color=='w' && beans[j%N]!='w')
                    ++cnt, color = beans[j%N];
                else if (beans[j%N]!='w' && color!='w' && color!=beans[j%N])
                    break;
            }/* End of For */
            
            color=beans[j%N];
            for (; ; ++j)
            {
                if (beans[j%N]=='w' || beans[j%N]==color)
                {
                    if (cnt >= N)
                        break;
                    else
                        ++cnt;
                }    
                else if (color=='w' && color!=beans[j%N])
                    ++cnt, color = beans[j%N];
                else if (beans[j%N]!='w' && color!='w' && color!=beans[j%N])
                    break;
            }/* End of For */
            
            if (cnt > max)
                max = cnt;
        }/* End of For */
        
        printf("%d\n", max);
    }/* End of While */
    
    return 0;
}
