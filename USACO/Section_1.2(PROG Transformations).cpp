/*
PROG:   transform
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

const int maxn = 12;

int  N;
char a[maxn][maxn], b[maxn][maxn], c[maxn][maxn], ans[maxn][maxn];

bool check()
{
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
        {
            if (b[i][j] != ans[i][j])
                return false;
        }
    }/* End of For */
    
    return true;
}/* check */

bool Nt_Degree()
{
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
            b[i][j] = a[N-j-1][i];
    }/* End of For */
    
    if (check())
        return true;
    else
        return false;
}/* 90_Degree */

bool Et_Degree()
{
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
            b[i][j] = a[N-i-1][N-j-1];
    }/* End of For */
    
    if (check())
        return true;
    else
        return false;
}/* 180_Degree */

bool TSt_Degree()
{
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
            b[i][j] = a[j][N-i-1];
    }/* End of For */
    
    if (check())
        return true;
    else
        return false;
}/* 270_Degree */

bool VertRef()
{
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
            b[i][j] = a[i][N-j-1];
    }/* End of For */
    
    if (check())
        return true;
    else
        return false;
}/* VertRef */

bool HorRef()
{
	int i;

	/* VertRef */
    for (i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
            b[i][j] = a[i][N-j-1], c[i][j]=b[i][j];
    }/* End of For */
    
	/* Nt_Degree */
    for (i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
            b[i][j] = c[N-j-1][i];
    }/* End of For */
    if (check())
        return true;

	/* Et_Degree */
	for (i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
            b[i][j] = c[N-i-1][N-j-1];
    }/* End of For */
	if (check())
        return true;

	/* TSt_Degree */
	for (i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
            b[i][j] = c[j][N-i-1];
    }/* End of For */
	if (check())
        return true;

	return false;
}/* HorRef */

bool NonChange()
{
	for (int i=0; i<N; ++i)
	{
		for (int j=0; j<N; ++j)
			b[i][j] = a[i][j];
	}/* End of For */

	if (check())
        return true;
    else
        return false; 
}/* NonChange */

int main()
{
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    
    while (~scanf("%d", &N))
    {
        int i;
        for (i=0; i<N; ++i)
            scanf("%s", a[i]);
        for (i=0; i<N; ++i)
            scanf("%s", ans[i]);
        
        bool IsSolved = false;
        for (i=1; i<7; ++i)
        {
            switch (i)
            {
                case 1: IsSolved = Nt_Degree(); break;
                case 2: IsSolved = Et_Degree(); break;
                case 3: IsSolved = TSt_Degree(); break;
                case 4: IsSolved = VertRef(); break;
                case 5: IsSolved = HorRef(); break;
                case 6: IsSolved = NonChange(); break;
            }/* End of Switch */
            
            if (IsSolved)
            {
                printf("%d\n", i);
                break;
            }    
        }/* End of For */
        if (!IsSolved)
            printf("7\n");
    }/* End of While */
    
    return 0;
}
