/*
PROG:   crypt1
ID:     ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define onlinejudge

bool hash[12];
int  N, i, j, cnt, fig;

bool check(int num)
{
    while (num)
    {
        if (!hash[num%10])
            return false;
        
        num /= 10;
    }/* End of While */
    
    return true;
}/* check */

bool IsPrimeDig(int a, int b)
{
    if (!check(a) || !check(b))
        return false;
    
    int r1 = (b%10)*a;
    int r2 = (b/10)*a;
    int mul = b*a;
    
    if ((r1>=100&&r1<=999) && (r2>=100&&r2<=999)
        && (mul>=1000&&mul<=9999))
    {
        if (check(r1) && check(r2) && check(mul))
            return true;
        else
            return false;
    }
    else
        return false;
}/* IsPrimeDig */

int main()
{
/*
#ifdef onlinejudge
    freopen("E:\\prime.txt", "r", stdin);
    freopen("E:\\prime_ans.txt", "w", stdout);
#endif
*/
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);

    while (~scanf("%d", &N))
    {
        memset(hash, false, sizeof(hash));
        for (i=0; i<N; ++i)
        {
            scanf("%d", &fig);
            hash[fig] = true;
        }/* prepare */
        
        for (i=100, cnt=0; i<=999; ++i)
        {
            for (j=10; j<=99; ++j)
            {
                if (IsPrimeDig(i, j))
                {
                    ++cnt;
                    //------------------------------------------------------
                    //printf("%d %d %d\n", i, j, i*j);
                    //------------------------------------------------------
                }    
            }
        }/* Main Process */
        
        printf("%d\n", cnt);
    }/* End of While */
    
    return 0;
}
