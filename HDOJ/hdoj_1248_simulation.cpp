/*
PROG:   º®±ùÍõ×ù
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int N, i, money;

int main()
{
    while (~scanf("%d", &N))
    {
        for (i=1; i<=N; ++i)
        {
            scanf("%d", &money);
            if ( money%150==0 || money%200==0
                || money%350==0 )
            {
                printf("0\n");
            }
            else
            {
                money%=150, money%=200, money%=350;
                printf("%d\n", money);
            }    
        }
    }/* End of while */
    
    return 0;
}
