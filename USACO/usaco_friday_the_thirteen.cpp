/*
ID: ouyangyewei
LANG:   C++
PROG:   friday
*/
#include <stdio.h>
#include <memory.h>

int N, fday, res[7] = {0};
int month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);

    while (~scanf("%d", &N))
    {
        fday = 1;   /* 每个月第一天是周几，1900.1.1 是周一 */ 
        for (int i=1900; i<1900+N; ++i)
        {
            if (i%400==0 || (i%4==0&&i%100!=0))
                month[2] = 29;
            else
                month[2] = 28;
            
            for (int j=1; j<=12; ++j)
            {
                res[(13+fday-1)%7]++;       /* 第 13 天 */ 
                fday = (month[j]+fday-1)%7+1;  /* 下个月的第一天 */ 
            }
        }/* End of For */
        
        printf("%d %d", res[6], res[0]);
        for (int i=1; i<=5; ++i)
            printf(" %d", res[i]);
        printf("\n");
        
        memset(res, 0, sizeof(res));
    }/* End of While */
    
    return 0;
}
