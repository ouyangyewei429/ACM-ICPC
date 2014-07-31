/*
PROG:   clocks
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int ways[9] = {
    //00A00B00C00D00E00F00G00H00I
    0b001001000001001000000000000,
    0b001001001000000000000000000,
    0b000001001000001001000000000,
    0b001000000001000000001000000,
    0b000001000001001001000001000,
    0b000000001000000001000000001,
    0b000000000001001000001001000,
    0b000000000000000000001001001,
    0b000000000000001001000001001
    };
           //0000000A00B00C00D00E00F00G00H00I
int keys = 0b00000011011011011011011011011011;

void Read_Data(int &state)
{
    int i, clocks, c;
    for (i=0; i<9; ++i)
    {
        state <<= 3;

        scanf("%d", &clocks);
        if (clocks == 12)
            c = 0;
        else if (clocks == 3)
            c = 1;
        else if (clocks == 6)
            c = 2;
        else if (clocks == 9)
            c = 3;

        state |= c;
    }// input
}// Read_Data

bool CanTakeIt(int depth, int t, int path[])
{
    int i, cnt=0;
    for (i=0; i<depth; ++i)
    {
        if (t == path[i])
            ++cnt;
    }// counting

    if (cnt >= 3)
        return false;
    else
        return true;
}// CanTakeIt

void Display_Route(int depth, int path[])
{
    int i;;
    for (i=0; i<depth; ++i)
        printf(i==0 ? "%d":" %d", path[i]);
    printf("\n");

    return ;
}// Display_Route

void dfs(int depth, int state, int path[])
{
    if (state == 0)
    {
        Display_Route(depth, path);
        return ;
    }// destination

    int i, start, tempState;
    if (depth > 0)
        start = path[depth-1];
    else
        start = 1;

    for (i=start; i<=9; ++i)
    {
        if (CanTakeIt(depth, i, path))
        {
            tempState = state;

            state += ways[i-1];
            state &= keys;

            path[depth] = i;
            dfs(depth+1, state, path);
            state = tempState;
        }
    }// end of for
}// dfs

int main()
{
    freopen("clocks.in", "r", stdin);
    freopen("clocks.out", "w", stdout);

    int state, path[27]={0};

    Read_Data(state);
    dfs(0, state, path);

    return 0;
}

