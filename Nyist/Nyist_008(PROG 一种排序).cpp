/*
PROG:
ID  :   ouyangyewei
LANG:   C++
*/
//#pragma warnning (disable : 4786)

#include <set>
#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define DEBUG 1

struct Rectangle {
    int number, length, width;
};

typedef Rectangle Rect;
typedef vector<Rect> VR;

inline int compare_1(Rect c, Rect d) {
    if (c.number == d.number) {
        if (c.length == d.length)
            return c.width < d.width;
        else
            return c.length < d.length;
    } else {
        return c.number < d.number;
    }
}

inline int compare_2(Rect c, Rect d) {
    return (c.number == d.number && c.length == d.length
            && c.width == d.width);
}

int main() 
{
#if DEBUG
    freopen("E:\\nyist_008.in", "r" ,stdin);
    freopen("E:\\nyist_008.out", "w", stdout);
#endif

    VR vec;
    Rect rt;
    int testCases, nNums;
    
    scanf("%d", &testCases);
    while (testCases--) {
        vec.clear();
        scanf("%d", &nNums);
        for (int i = 0; i < nNums; ++i) {
            scanf("%d %d %d", &rt.number, &rt.length, &rt.width);
            if (rt.length < rt.width)
                swap(rt.length, rt.width);
            vec.push_back(rt);
        }
        sort(vec.begin(), vec.end(), compare_1);
        
        for (VR::size_type ix = 0; ix < vec.size(); ++ix)
            printf("%d %d %d\n", vec[ix].number, vec[ix].length, vec[ix].width);
        
        unique(vec.begin(), vec.end(), compare_2);
        /*
        for (VR::size_type ix = 0; ix < vec.size(); ++ix)
            printf("%d %d %d\n", vec[ix].number, vec[ix].length, vec[ix].width);
            */
    }// End of while
    return 0;
}

