/*
 * AC 统计比赛选手被打败的次数 
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int  i, j, k, cnt, casenum, temp;
char winner[50], loser[50];
struct match
{
    int  failTimes;     /* 保存比赛选手得分 */ 
    char name[50];
}player[2010];

int search_player(char name[])
{
    int site;
    
    for (site=0; site<casenum+casenum; ++site)
    {
        if (player[site].name[0] == '\0')
        {
            ++cnt;
            strcpy(player[site].name, name);
            return site;
        }
        else if (strcmp(player[site].name, name) == 0)
        {
            return site;
        }
    }/* End of For */
}

int main()
{
    while (1==scanf("%d", &casenum), casenum!=0)
    {
        cnt = 0;
        memset(player, 0, sizeof(player)); /* 清空结构体数组 */
        for (i=0; i<casenum; ++i)
        {
            /* 清空临时缓存字符串数组 */ 
            memset(winner, 0, sizeof(winner));
            memset(loser, 0, sizeof(loser));
            
            scanf("%s %s", winner, loser);
            j = search_player(winner);
            k = search_player(loser);
            
            ++player[k].failTimes;
        }/* End of For */
        
        /* Get the champion */
        temp = 0;
        for (i=0; i<cnt; ++i)
        {
            if (player[i].failTimes == 0)
            {
                ++temp;
            }
        }/* End of For */
        if (temp == 1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }/* End of while */
    
    return 0;
}
