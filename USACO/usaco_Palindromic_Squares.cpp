/*
PROG:   palsquare
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int  cnt, B;
char a[30], b[30];

void Trans_In_Base(int fig, int base, char bunch[])
{
    int  tmp;
    char s[30]={0};
    
	cnt = 0;
    while (fig)
    {
        tmp = fig%base;
        if (tmp > 9)
            s[cnt++] = tmp-10+'A';
        else
            s[cnt++] = tmp+'0';
        
        fig /= base;
    }/* End of while */

    for (int i=0; i<cnt; ++i)
        bunch[cnt-i-1] = s[i];
	bunch[cnt] = '\0';
}/* Trans_In_Base */

bool IsPalind()
{
    //int cnt = strlen(bunch);
    for (int i=0; i<=(cnt>>1); ++i)
    {
        if (b[i] != b[cnt-i-1])
            return false;
    }/* End of For */
    
    return true;
}/* IsPalind */

int main()
{
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);

    while (~scanf("%d", &B))
    {
        printf("1 1\n");
        for (int i=2; i<=300; ++i)
        {
            Trans_In_Base(i, B, a);
			Trans_In_Base(i*i, B, b);
            if (IsPalind())
                printf("%s %s\n", a, b);
        }/* End of For */
    }/* End of While */
    
    return 0;
}
