/*
PROG:   Open the Lock
ID  :   ouyangyewei
LANG:   C++
*/
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory.h>
using namespace std;

//#define onlinejudge

bool hash[7000];
char password[5], goal[5];
typedef struct node
{
    int t, ca;
    char ss[5];
}NODE;

int CanTor(char s[])
{
    return (s[0]-'0'-1)*729+(s[1]-'0'-1)*81+(s[2]-'0'-1)*9+(s[3]-'0'-1);
}/* CanTor */

void ss_swap(char &x, char &y)
{
    char temp = x;
    x = y, y = temp;
}/* ss_swap */

int bfs()
{
    NODE    c, n;
    queue <NODE> q;
    
    c.t=0, c.ca=CanTor(password);
    memcpy(c.ss, password, 5);
    
    hash[c.ca] = true;
    q.push(c);
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        if (memcmp(c.ss, goal, 5) == 0)
            return c.t;
        
        for (int i=0; i<4; ++i)
        {
            memcpy(n.ss, c.ss, 5);
            n.ss[i] = (c.ss[i]=='9') ? '1':(c.ss[i]+1);   // Add one
            n.ca = CanTor(n.ss);
            if (!hash[n.ca])
                n.t=c.t+1, hash[n.ca]=true, q.push(n);
            
            memcpy(n.ss, c.ss, 5);
            n.ss[i] = (c.ss[i]=='1') ? '9':(c.ss[i]-1);   // Minus one
            n.ca = CanTor(n.ss);
            if (!hash[n.ca])
                n.t=c.t+1, hash[n.ca]=true, q.push(n);
            
            if (i != 0)
			{
				memcpy(n.ss, c.ss, 5);
				ss_swap(n.ss[i-1], n.ss[i]);    // swap ss[i-1] with ss[i]
				n.ca = CanTor(n.ss);
				if (!hash[n.ca])
					n.t=c.t+1, hash[n.ca]=true, q.push(n);
			}
            if (i != 3)
			{
				memcpy(n.ss, c.ss, 5);
				ss_swap(n.ss[i], n.ss[i+1]);    // swap ss[i] with ss[i+1]
				n.ca = CanTor(n.ss);
				if (!hash[n.ca])
					n.t=c.t+1, hash[n.ca]=true, q.push(n);
			}
        }/* End of For */
    }/* End of While */
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\zoj_2416.txt", "r", stdin);
    freopen("E:\\zoj_2416_ans.txt", "w", stdout);
#endif

    int T;
    scanf("%d", &T);
    while (T--)
    {
        cin >> password >> goal;
        memset(hash, false, sizeof(hash));
        printf("%d\n", bfs());
    }/* End of While */
    
    return 0;
}
