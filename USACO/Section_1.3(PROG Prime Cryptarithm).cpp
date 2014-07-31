/*
PROG:   crypt1
ID:     ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define onlinejudge

bool fig[12];
int  i, j, k, m, n, N, cnt, num[12];
int  a[3], b[2], c[4], d[4], w[5];

int main()
{

#ifdef onlinejudge
    freopen("E:\\prime.txt", "r", stdin);
    freopen("E:\\prime_ans.txt", "w", stdout);
#endif
/*
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
*/
    while (~scanf("%d", &N))
    {
        memset(fig, false, sizeof(fig));
        for (i=0; i<N; ++i)
        {
            scanf("%d", &num[i]);
            fig[num[i]] = true;
        }/* prepare */
        
        cnt = 0;
        for (i=0; i<N; ++i)
        {
            a[0] = num[i];
            for (j=0; j<N; ++j)
            {
                a[1] = num[j];
                for (k=0; k<N; ++k)
                {
                    a[2] = num[k];
                    for (m=0; m<N; ++m)
                    {
                        b[1] = num[m];
                        memset(c, 0, sizeof(c));
                        
                        c[3] = (b[1]*a[2])%10;
                        c[2] = (b[1]*a[2])/10 + (b[1]*a[1])%10;
                        c[1] = (b[1]*a[1])/10 + (b[1]*a[0])%10;
                        c[0] = (b[1]*a[0])/10;
                        
                        if (!fig[c[3]] || !fig[c[2]] || !fig[c[1]] || (!fig[c[0]] && c[0]))
                            continue;
                        
                        for (n=0; n<N; ++n)
                        {
                            b[0] = num[n];
                            memset(d, 0, sizeof(d));
                            
                            d[3] = (b[0]*a[2])%10;
                            d[2] = (b[0]*a[2])/10 + (b[0]*a[1])%10;
                            d[1] = (b[0]*a[1])/10 + (b[0]*a[0])%10;
                            d[0] = (b[0]*a[0])/10;
                            
                            if (!fig[d[3]] || !fig[d[2]] || !fig[d[1]] || d[0])
                                continue;
                                
                            w[4] = c[3];
                            w[3] = (c[2]+d[3])%10;
                            w[2] = (c[2]+d[3])/10 + (c[1]+d[2])%10;
                            w[1] = (c[1]+d[2])/10 + (c[0]+d[1])%10;
                            w[0] = (c[0]+d[1])/10 + d[0];
                            if (!fig[w[4]] || !fig[w[3]] || !fig[w[2]] || !fig[w[1]] || w[0])
                                continue;
                            else
							{
                                ++cnt;
								//---------------------------------------------------------------------------------
                                //printf("%d %d %d %d %d\n", a[0],a[1],a[2],b[0],b[1]);
                                //---------------------------------------------------------------------------------
							}
						}// 5
                    }// 4
                }// 3
            }// 2
        }// 1
        
        printf("%d\n", cnt);
    }/* End of While */
    
    return 0;
}
