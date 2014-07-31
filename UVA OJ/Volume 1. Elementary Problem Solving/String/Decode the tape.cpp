/*
PROG:   Decode the tape
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#define DEBUG 0

// 解码：tape 上表示 7 位的2进制数字，其中空格代表二进制 0，字符‘0‘
// 表示二进制 1，将tape上的二进制以十进制形的ASCIll就是解码后的文字 
void decodeTape(string &tapes) {
    int decimal = 0;
    int slen = tapes.length();
    
    for (int i = 0; i < slen; ++i) {
        if (tapes[i] == ' ') {
            decimal <<= 1;
        } else if (tapes[i] == 'o') {
            decimal = decimal << 1 | 1;
        }
    }
    printf("%c", decimal);
}

int main() {
#if DEBUG
    freopen("E:\\10878.in", "r", stdin);
    freopen("E:\\10878.out", "w", stdout);
#endif

    string tapes;
    
    while (getline(cin, tapes)) {
        //getchar();  // get the carry return
        if (tapes != "___________") {
            decodeTape(tapes);
        }
    }// End of while
    //printf("\n");
    
    return 0;
}
