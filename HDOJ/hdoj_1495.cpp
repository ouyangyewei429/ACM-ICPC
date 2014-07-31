#include <queue>
#include <stdio.h>
using namespace std;

//#define onlinejudge

const int maxn = 104;

bool IsSolved, hash[maxn][maxn][maxn];
int  S, A, B, maze[maxn][maxn];
struct Graph
{
    int a, b, c, step;
};

bool IsInBound(int a, int b, int c)
{
    if (a<0 || b<0 || c<0 || a>A || b>B || c>S)
        return false;
    
    return true;
}/* IsInBound */

void bfs()
{
    queue <Graph> q;
    struct Graph cur, next;
    
    cur.a = 0;
    cur.b = 0;
    cur.c = S;
    cur.step = 0;
    hash[0][0][S] = true;
    
    q.push(cur);
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        
        //----------------------------------------------
        //printf("%d # %d %d %d\n", cur.step, cur.c, cur.a, cur.b);
        //----------------------------------------------
        
        if ((!cur.b&&cur.c==cur.a) || (!cur.a&&cur.c==cur.b)
            || (!cur.c&&cur.a==cur.b))
        {
            IsSolved = true;
            printf("%d\n", cur.step);
            return ;
        }
        
        /* Pour(A, B) */
        next.b = (cur.a+cur.b>=B) ? B:(cur.a+cur.b);
        next.a = cur.a+cur.b-next.b;
        next.c = cur.c;
        if (!hash[next.a][next.b][next.c] && IsInBound(next.a, next.b, next.c))
        {
            next.step = cur.step + 1;
            hash[next.a][next.b][next.c] = true;
            q.push(next);
            
            //----------------------------------------------
            //printf("Pour(A, B): %d %d %d %d\n", next.step, next.c, next.a, next.b);
            //----------------------------------------------
        }
        
        /* Pour(B, A) */
        next.a = (cur.a+cur.b>=A) ? A:(cur.a+cur.b);
        next.b = cur.a+cur.b-next.a;
        next.c = cur.c;
        if (!hash[next.a][next.b][next.c] && IsInBound(next.a, next.b, next.c))
        {           
            next.step = cur.step + 1;
            hash[next.a][next.b][next.c] = true;
            q.push(next);
            //----------------------------------------------
            //printf("Pour(B, A): %d %d %d %d\n", next.step, next.c, next.a, next.b);
            //----------------------------------------------
        }
        
        /* Pour(A, C) */
        next.c = (cur.a+cur.c>=S) ? S:(cur.a+cur.c);
        next.a = cur.a+cur.c-next.c;
        next.b = cur.b;
        if (!hash[next.a][next.b][next.c] && IsInBound(next.a, next.b, next.c))
        {
            next.step = cur.step + 1;
            hash[next.a][next.b][next.c] = true;
            q.push(next);
            
            //----------------------------------------------
            //printf("Pour(A, C): %d %d %d %d\n", next.step, next.c, next.a, next.b);
            //----------------------------------------------
        }
        
        /* pour(C, A) */
        next.a = (cur.a+cur.c>=A) ? A:(cur.a+cur.c);
        next.c = cur.a+cur.c-next.a;
        next.b = cur.b;
        if (!hash[next.a][next.b][next.c] && IsInBound(next.a, next.b, next.c))
        {
            next.step = cur.step + 1;
            hash[next.a][next.b][next.c] = true;
            q.push(next);
            
            //----------------------------------------------
            //printf("Pour(C, A): %d %d %d %d\n", next.step, next.c, next.a, next.b);
            //----------------------------------------------
        }
        
        /* pour(B, C) */
        next.c = (cur.b+cur.c>=S) ? S:(cur.b+cur.c);
        next.b = cur.b+cur.c-next.c;
        next.a = cur.a;
        if (!hash[next.a][next.b][next.c] && IsInBound(next.a, next.b, next.c))
        {
            next.step = cur.step + 1;
            hash[next.a][next.b][next.c] = true;
            q.push(next);
            
            //----------------------------------------------
            //printf("Pour(B, C): %d %d %d %d\n", next.step, next.c, next.a, next.b);
            //----------------------------------------------
        }
        
        /* pour(C, B) */
        next.b = (cur.b+cur.c>=B) ? B:(cur.b+cur.c);
        next.c = cur.b+cur.c-next.b;
        next.a = cur.a;
        if (!hash[next.a][next.b][next.c] && IsInBound(next.a, next.b, next.c))
        {
            next.step = cur.step + 1;
            hash[next.a][next.b][next.c] = true;
            q.push(next);
            
            //----------------------------------------------
            //printf("Pour(C, B): %d %d %d %d\n", next.step, next.c, next.a, next.b);
            //----------------------------------------------
        }
    }/* End of While */
    if (!IsSolved)
        printf("NO\n");
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1495.txt", "r", stdin);
    freopen("E:\\hdoj_1495_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d %d", &S, &A, &B), S+A+B!=0)
    {
        memset(hash, false, sizeof(hash));
        
        IsSolved = false;
        bfs();
    }/* End of While */
    
    return 0;
}
