/*
PROG:   ËÙËã24µã
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

char card[10];
int  cardNums[10];

bool dfs(int ans)
{
    if ( ans==24 )
        return true;
    if ( ans<=0 )
        return false;
    
    for (int i=0; i<4; ++i)
    {
        if ( dfs( ans+cardNums[i] ) )  return true;
        if ( dfs( ans-cardNums[i] ) )  return true;
        if ( dfs( ans*cardNums[i] ) )  return true;
        if ( dfs( ans/cardNums[i] ) )  return true;
    }
    
    return false;
}// dfs

int main()
{
    while (~scanf("%c %c %c %c", &card[0], &card[1], &card[2], &card[3]))
    {
        for (int i=0; i<4; ++i)
        {
            switch (card[i])
            {
                case 'A':   cardNums[i]= 1; break;
                case 'J':   cardNums[i]=11; break;
                case 'Q':   cardNums[i]=12; break;
                case 'K':   cardNums[i]=13; break;
                default :   cardNums[i]=card[i]-'0'; break;
            }
        }// Trans to number
        
        if ( dfs( 0 ) )  /* depth, ans */
            printf("Yes\n");
        else
            printf("No\n");
    }// End of while
    
    return 0;
}
