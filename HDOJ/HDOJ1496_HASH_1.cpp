// Accept  31ms  544k 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

/* 将方程分划为2个部分，前一个部分最多有100*100种可能 */
#define MAX 30093

int s[10010]={0};
int a, b, c, d, ans, temp, p, i, j;
struct HashTable
{
    int key;
    int num;
}hash[MAX];

/* 线性探查法 */
int LinearDe(int k)
{
    int d = k%MAX;
    
    if (d < 0)
    {
        d += MAX;
    }
    
    /***
     *  前一个条件主要用于解决hash冲突 
     *  后一个条件主要用于查找 ax1^2+bx2^2 的结果
     *  
     *  可以证明在hash[i].num（关键字频率）为0前，总是
     *  会有至少一个元素位于 hash[i] 位置，这是线性探查法
     *  的构造结果！（想想？）
     *
     *  同时在利用线性探查法解决hash冲突时，后一个条件不会影响
     *  前一个条件，因为不可以存在一个位置 hash[i] ，使得
     *  hash[i].num!=0, hash[i].key=k
     *  换句话说，只要 hash[i] 有记录关键字，那么必定满足hash[i].num!=0 
     **/
    while (hash[d].num && hash[d].key!=k)
    {
        d = (d+1)%MAX;
    }/* End of While */

    return d;
}/* LinearDe */

int main()
{
    for (i=1; i<=10000; ++i)
    {
        s[i] = i*i;
    }/* End of For */
    
    while (~scanf("%d %d %d %d", &a, &b, &c, &d))
    {
        if ((a>0 && b>0 && c>0 && d>0)
            || (a<0 && b<0 && c<0 && d<0))
        {   /* 同号必然无解 */ 
            printf("0\n");
            continue;
        }/* End of If */
        
        memset(hash, 0, sizeof(hash));
        for (i=1; i<=100; ++i)
        {
            for (j=1; j<=100; ++j)
            {
                temp = a*s[i] + b*s[j];
                p = LinearDe(temp);
                hash[p].key = temp;    /* 记录关键字 */ 
                ++hash[p].num;         /* 记录关键字的频率 */ 
            }
        }/* End of For */
        
        ans = 0;
        for (i=1; i<=100; ++i)
        {
            for (j=1; j<=100; ++j)
            {
                /*
                  因为ax1^2+bx2^2+cx3^2+dx4^2 = 0,
                  所以满足：
                  ax1^2+bx2^2 = -(cx3^2+dx4^2) 
                */
                temp = -(c*s[i] + d*s[j]);
                p = LinearDe(temp);
                ans += hash[p].num;
            }
        }/* End of For */ 
        
        printf("%d\n", ans<<4); /* x1 x2 x3 x4 对应不同的正负形，于是一共有 2^4 种可能 */ 
    }/* End of While */
    
    return 0;
}
