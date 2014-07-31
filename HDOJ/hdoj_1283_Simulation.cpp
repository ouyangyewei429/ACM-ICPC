/*
PROG:   最简单的计算机
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

const int maxn = 204;

char cmd[maxn];
int  M1, M2, R1, R2, R3;

int main()
{
    while (~scanf("%d %d", &M1, &M2))
    {
        R1=R2=R3=0;
        
        getchar();
        scanf("%s", cmd);
        for (int i=0; i<strlen(cmd); ++i)
        {
            switch (cmd[i])
            {
                case 'A': R1 = M1; break;
                case 'B': R2 = M2; break;
                case 'C': M1 = R3; break;
                case 'D': M2 = R3; break;
                case 'E': R3 = R1+R2; break;
                case 'F': R3 = R1-R2; break;
            }
        }// simulation
        
        printf("%d,%d\n", M1, M2);
    }/* End of While */
    
    return 0;
}
