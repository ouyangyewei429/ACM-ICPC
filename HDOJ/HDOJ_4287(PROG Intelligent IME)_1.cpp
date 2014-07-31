/*
PROG:   Intelligent IME
ID  :   ouyangyewei
LANG:   C++
*/
#pragma warnning (disable : 4786)

#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const char ss[] = "22233344455566677778889999";

struct compare {
    bool operator ()(const char *s1, const char *s2) const {
        return strcmp(s1, s2) < 0;
    }
};

void trans(char nums[], char str[]) {
    int slen = strlen( str );
    
    memset( nums, 0, sizeof(nums) );
    for (int i = 0; i < slen; ++i) {
        nums[i] = ss[ str[i] - 'a' ];
    }
    nums[ slen ] = '\0';
}

int main() {
    int T, N, M, i, j;
    char nums[20], str[20];
    
    scanf("%d", &T);
    while ( T-- ) {
        vector<char *> v;
        map<char *, int, compare> mp;
        
        scanf("%d %d", &N, &M);
        for (i = 0; i < N; ++i) {
            scanf("%s", nums);
            v.push_back( nums );
            mp[ nums ] = 0;
        }
        for (i = 0; i < M; ++i) {
            scanf("%s", str);
            trans(nums, str);
            ++mp[ nums ];
        }
        
        for (i = 0; i < N; ++i) {
            if ( mp[ v[i] ] == 0 ) {
                printf("0\n");
            } else {
                printf("%d\n", mp[ v[i] ]);
            }
        }
    }// End of while
    
    system("pause");
    return 0;
}
/*
1
3 5
46
64448
74
go
in
night
might
gn

3
2
0
*/
