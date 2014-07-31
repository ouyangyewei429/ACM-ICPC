#include <stdio.h>
#include <memory.h>

#define MAX 1000037

int nNum, mNum, temp, i, j;
struct HashTable
{
    int key;
    int num;
}hash[MAX];

int LinearDe(int k)
{
    int d = k%MAX;
    
    while (hash[d].num && hash[d].key!=k)
    {
        d = (d+1)%MAX;
    }
    
    return d;
}/* LinearDe */

int main()
{
    while (~scanf("%d %d", &nNum, &mNum))
    {
        memset(hash, 0, sizeof(hash));
        for (i=0; i<nNum; ++i)
        {
            scanf("%d", &temp);
            p = LinearDe(temp+MAX);
            hash[p].key = temp;
            ++hash[p].num;
        }
    }/* End of While */
    
    return 0;
}
