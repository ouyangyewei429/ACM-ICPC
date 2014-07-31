#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAX 1000000

int hash[MAX+MAX+10], p[MAX+10]={0};
int a, b, c, d, i, j, cnt;

int main()
{
    for (i=1; i<=100; ++i)
    {
        p[i] = i*i;
    }
    
    while (~scanf("%d %d %d %d", &a, &b, &c, &d))
    {
        if ((a>0 && b>0 && c>0 && d>0)
            || (a<0 && b<0 && c<0 && d<0))
        {
            printf("0\n");
            continue;
        }
        
        memset(hash, 0, sizeof(hash));
        for (i=1; i<=100; ++i)
        {
            for (j=1; j<=100; ++j)
            {
                ++hash[MAX+a*p[i]+b*p[j]];
            }
        }/* End of For */
        
        cnt = 0;
        for (i=1; i<=100; ++i)
        {
            for (j=1; j<=100; ++j)
            {
                cnt += hash[MAX-c*p[i]-d*p[j]];
            }
        }/* End of For */
        
        printf("%d\n", cnt<<4);
    }/* End of While */
    
    return 0;
}
