#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int maxn = 300001;

int  i, step, mod, a, b;
bool hash[maxn];

int main()
{
    while (~scanf("%d %d", &step, &mod))
    {
        memset(hash, false, sizeof(hash));
        
        a = b = 0;
        hash[0] = true;
        for (i=0; i<mod; ++i)
        {
            b = (a+step)%mod;
            a = b;
            hash[b] = true;
        }/* End of For */
        
        for (i=0; i<mod; ++i)
        {
            if (hash[i] == false)
                break;
        }/* End of For */
        if (i == mod)
            printf("%10d%10d    Good Choice\n", step, mod);
        else
            printf("%10d%10d    Bad Choice\n", step, mod);
        printf("\n");
    }/* End of While */
    
    return 0;
}
