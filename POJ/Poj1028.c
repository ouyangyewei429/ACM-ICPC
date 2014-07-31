#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define LOCAL

int  topback = -1;
int  topfor  = -1;
char command[20] = {0};
char curpage[100] = "http://www.acm.org/";
char newpage[100] = {0};
char backward[110][80] = {0};
char forward[110][80] = {0};

int main()
{
#ifdef LOCAL
    freopen("E:\\poj1028.txt", "r", stdin);
    freopen("E:\\poj1028(result).txt", "w", stdout);
#endif

    while (EOF != scanf("%s", command), command[0]!='Q')
    {
        switch (command[0])
        {
            case 'V':
            {
                memset(newpage, 0, sizeof(newpage)); /* 清空缓存新网页的字符串数组 */
                
                scanf("%s", newpage);
                if (strcmp(newpage, curpage) != 0)
                {   /* 如果新网页不等于当前网页，则将当前网页压入 backward栈 */ 
                    strcpy(backward[++topback], curpage);
                    
                    memset(curpage, 0, sizeof(curpage));
                    strcpy(curpage, newpage); /* 当前网页更改为新输入网页 */
                }
                
                topfor = -1;
                memset(forward, 0, sizeof(forward));
                printf("%s\n", curpage);
            };break;
            
            case 'B':
            {
                if (topback == -1)
                {
                    printf("Ignored\n");
                }
                else
                {
                    strcpy(forward[++topfor], curpage);  /* 将当前网页压入 forward 栈 */
                    
                    memset(curpage, 0, sizeof(curpage));
                    strcpy(curpage, backward[topback--]); /* 将 backward 栈顶元素弹出 */
                    strcpy(backward[topback+1], "\0");
                    printf("%s\n", curpage);
                }    
            }break;
            
            case 'F':
            {
                if (topfor == -1)
                {
                    printf("Ignored\n");
                }
                else
                {
                    strcpy(backward[++topback], curpage); /* 将当前网页压入 forward 栈 */
                    
                    memset(curpage, 0, sizeof(curpage));
                    strcpy(curpage, forward[topfor--]);   /* 将 forward 栈顶元素弹出 */
                    strcpy(forward[topfor+1], "\0");
                    printf("%s\n", curpage);
                }
            };break;
        }/* End of Switch */
    }/* End of While */
    
    return 0;
}
