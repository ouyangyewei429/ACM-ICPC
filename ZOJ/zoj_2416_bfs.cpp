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

int T;
string lock, password;
typedef struct node
{
    int t;
    string bunch;
}NODE;

int bfs()
{
    NODE    c, n;
    queue <NODE> q;
    map <string, bool> hash;
    
    c.bunch = lock, c.t = 0;
    hash[lock] = true;
    
    q.push(c);
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        if (c.bunch == password)
            return c.t;
        
        for (int i=0; i<4; ++i)
        {
            n.bunch = c.bunch;
            n.bunch[i] = (c.bunch[i]=='9') ? '1':(c.bunch[i]+'1');  // add one
            n.bunch[i] = (c.bunch[i]=='1') ? '9':(c.bunch[i]-'1');  // minus one
            if (hash[n.bunch])
                continue;
            else
                hash[n.bunch]=true, n.t=c.t+1, q.push(n);
            
            string swap;
            n.bunch = c.bunch;
            if (i == 0)
            {
                swap=n.bunch[i], n.bunch[i]=n.bunch[i+1], n.bunch[i+1]=swap;
                if (hash[n.bunch])  continue;
                
                hash[n.bunch] = true, n.t=c.t+1, q.push(n);
            }
            else if (i == 3)
            {
                swap=n.bunch[i], n.bunch[i]=n.bunch[i-1], n.bunch[i-1]=swap;
                if (hash[n.bunch])  continue;
                
                hash[n.bunch] = true, n.t=c.t+1, q.push(n);
            }
            else
            {   // 0<=i<=3
                swap=n.bunch[i], n.bunch[i]=n.bunch[i+1], n.bunch[i+1]=swap;
                if (hash[n.bunch])  continue;
                hash[n.bunch] = true, n.t=c.t+1, q.push(n);
                
                swap=n.bunch[i], n.bunch[i]=n.bunch[i-1], n.bunch[i-1]=swap;
                if (hash[n.bunch])  continue;
                hash[n.bunch] = true, n.t=c.t+1, q.push(n);
            }
        }/* End of For */
    }/* End of While */
}/* bfs */

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        cin >> lock >> password;
        
        if (lock == password)
            printf("0\n");
        else
            printf("%d\n", bfs());
    }/* End of While */
    
    return 0;
}
