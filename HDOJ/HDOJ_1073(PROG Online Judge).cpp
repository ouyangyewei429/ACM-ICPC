/*
PROG:   Online Judge
ID  :   ouyangyewei
LANG:   C++
*/
//#pragma warnning (diaable : 4530)
//#pragma warnning (disable : 4786)

#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#define DEBUG 0

void readString(string &ss) {
    string tt;
    
    ss = "";
    while (getline(cin, tt), tt != "END") {
        if (tt != "START")
            ss += tt;
		if (tt == "")
			ss += "\n";
    }// End of while
}

void getString(string &ss, string &tt) {
    string::size_type ix;
    string::size_type slen = ss.length();
    
    tt = "";
    for (ix = 0; ix < slen; ++ix) {
        if (!isspace(ss[ix]))
            tt += ss[ix];
    }// End of for
}

int main() 
{
#if DEBUG
    freopen("E:\\hdoj_1073.in", "r" ,stdin);
    freopen("E:\\hdoj_1073.out", "w", stdout);
#endif

    int nCases;
    string s1, s2, s3, s4;
    
    scanf("%d", &nCases);
    while (nCases--) {
        readString(s1);
        readString(s2);
        if (s1 == s2) {
            cout << "Accepted" << endl;
        } else {
            getString(s1, s3);
            getString(s2, s4);
            if (s3 == s4)
                cout << "Presentation Error" << endl;
            else
                cout << "Wrong Answer" << endl;
        }
    }// End of while
    return 0;
}
