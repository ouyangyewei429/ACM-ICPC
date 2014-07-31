/*
PROG:   Nª ∫ÛŒ Ã‚
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int N, result[15]={0,1,0,0,2,
                   10,4,40,92,
                   352,724,2680};

int main()
{
    while (~scanf("%d", &N), N!=0)
    {
        printf("%d\n", result[N]);
    }// End of while
    
    return 0;
}
