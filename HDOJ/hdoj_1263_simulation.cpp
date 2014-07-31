/*
PROG:   Ë®¹û
ID  :   ouyangyewei
LANG:   C++
*/
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

const int maxn = 104;

int T, M, num, flag=0;
string fruit, place;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        map <string, map<string, int> > data;
        
        scanf("%d", &M);
        for (int i=0; i<M; ++i)
        {
            cin >> fruit >> place >> num;
            data[place][fruit] += num;
        }// input
        
        if (flag)   printf("\n");
        flag = 1;
        
        map <string, map<string, int> >::iterator iter1;
        for (iter1=data.begin(); iter1!=data.end(); ++iter1)
        {
            cout << iter1->first << endl;
            
            map <string, int>::iterator iter2;
            for (iter2=(iter1->second).begin(); iter2!=(iter1->second).end(); ++iter2)
                cout << "   |----" << iter2->first
                     << "(" << iter2->second << ")" << endl;
        }// Loop_1
    }// End of While
    
    return 0;
}
