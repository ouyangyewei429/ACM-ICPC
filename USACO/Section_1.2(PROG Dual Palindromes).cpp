/*
PROG:   dualpal
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char bunch[40];
int  N, S, pnum, count;

void Trans_In_Base(int fig, int base)
{
    int cnt=0;
    while (fig)
    {
        bunch[cnt++] = fig%base+'0';
        fig /= base;
    }/* End of while */
    
    bunch[cnt] = '\0';
}/* Trans_In_Base */

bool IsPalind()
{
    int cnt = strlen(bunch);
    for (int i=0; i<=(cnt>>1); ++i)
    {
        if (bunch[i] != bunch[cnt-i-1])
            return false;
    }/* End of For */
    
    return true;
}/* IsPalind */

int main()
{
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);

    while (~scanf("%d %d", &N, &S))
    {
        for (int i=S+1,pnum=0; pnum<N; ++i)
        {
            count = 0;
            for (int base=2; base<=10; ++base)
            {
                Trans_In_Base(i, base);
                if (IsPalind())
                    ++count;
                
                if (count >= 2)
                {
                    ++pnum;
                    printf("%d\n", i);
                    break;
                }
            }/* End of for */
        }/* End of For */
    }/* End of While */
    
    return 0;
}
