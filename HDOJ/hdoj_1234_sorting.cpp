/*
PROG:   开门人和关门人
ID  :   ouyangyewei
LANG:   C++
*/
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

const int maxn = 20;

int T, N, hh, mm, ss, first, second, a, b;
typedef struct message
{
    char id[maxn];
    int  st, et;
}MES;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        MES     tmp;
        vector <MES> data;
        
        scanf("%d", &N);
        for (int i=0; i<N; ++i)
        {
            getchar();
            scanf("%s", tmp.id);
            //cin >> tmp.id;
            scanf("%d:%d:%d", &hh, &mm, &ss);
            tmp.st = hh*3600+mm*60+ss;
            scanf("%d:%d:%d", &hh, &mm, &ss);
            tmp.et = hh*3600+mm*60+ss;
            
            data.push_back(tmp);
        }// Input
        
        first=0x3F3F3F3F, second=-65535;
        for (int i=0; i<data.size(); ++i)
        {
            if (first > data[i].st)
                a=i, first=data[i].st;
            if (second < data[i].et)
                b=i, second=data[i].et;
        }// Find the answer
        
        printf("%s %s\n", data[a].id, data[b].id);
    }// End of While
    
    return 0;
}
