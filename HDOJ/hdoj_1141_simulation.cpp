/*
PROG:   Factstone Benchmark
ID  :   ouyangyewei
LANG:   C
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

double sum;
int years, bits, ans;

int main()
{
    while (~scanf("%d", &years), years!=0)
    {
        bits = ( 1<<( (years-1960)/10+2 ) );
        for (ans=1, sum=0.0; ; ++ans)
        {
            sum += log(1.0*ans)/log(2.0);
            if (sum>bits)   break;
        }

        printf("%d\n", ans-1);
    }/* End of while */
    
    return 0;
}
