/*
PROG:   Hexadecimal View
ID  :   ouyangyewei
LANG:   C++
*/
//#pragma warnning (disable : 4786)

#include <set>
#include <map>
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

#define DEBUG 0

void print_dump(string &str) {
    int bits = str.length();
    
    for (int i = 0; i < bits; ++i) {
        if ((i & 1) == 0)
            printf(" ");
        printf("%02x", (int)str[i]);
    }
    for (int j = bits; j < 16; ++j) {
        if ((j & 1) == 0)
            printf(" ");
        printf("  ");
    }
    //printf(" ");
}

void print_text(string &str) {
    int bits = str.length();
    
    printf(" ");
    for (int i = 0; i < bits; ++i) {
        if (!isalpha(str[i])) {
            printf("%c", str[i]);
        } else {
            if (isupper(str[i])) {
                printf("%c", tolower(str[i]));
            } else {
                printf("%c", toupper(str[i]));
            }
        }
    }// End of for
    printf("\n");
}

int main() {
#if DEBUG
    freopen("E:\\hdoj_4054.in", "r" ,stdin);
    freopen("E:\\hdoj_4054.out", "w", stdout);
#endif

    string line, str;
    
    while (getline(cin, line)) {
        int addr = 0;  // address of curuent line
        
        while (line != "") {
            printf("%04x:", addr);
            if (line.length() >= 16) {
                str = line.substr(0, 16);
                line.erase(0, 16);
            } else {
                str = line;
                line = "";
            }
            print_dump(str);
            print_text(str);
            addr += 16;
        }
    }// End of while

    return 0;
}
/*
Run ID	Submit Time	Judge Status	Pro.ID	Exe.Time	Exe.Memory	Code Len.	Language	Author
6767243	2012-09-14 21:58:17	Accepted	4054	15MS	288K	1817 B	C++	Maxwell
*/
