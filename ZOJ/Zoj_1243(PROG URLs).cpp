/*
PROG:
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

#define DEBUG 1

void process(string &url, string &protocol,
             string &host, string &port, string &path)
{
    int cnt, apos[100] = {0}, bpos[100] = {0};
    string::size_type ix, jx;
    string::size_type slen = url.length();

    protocol = host = "", port = path = "";
    for (cnt = 0, ix = 0; ix < slen; ++ix) {
        if ( url[ix] == ':' || url[ix] == '/' )
            pos[cnt++] = ix;
    }
    for (ix = 0; ix < pos[0]; ++ix) {
        protocol += url[ix];
    }
    if ( pos[3] != -1 ) {  // port is exist
        for (ix = pos[2] + 1; ix < pos[3]; ++ix) {  // get host
            host += url[ix];
        }
        if ( pos[4] != -1 ) {  // path is exist
            for (ix = pos[3] + 1; ix < pos[4]; ++ix) {
                port += url[ix];
            }
            for (ix = pos[4] + 1; ix < slen; ++ix) {
                path += url[ix];
            }// End of for
        } else {  // path is not exist
            for (ix = pos[3] + 1; ix < slen; ++ix) {
                port += url[ix];
            }
        }
    } else {  // port is not exist
        if ( pos[4] != -1 ) {  // path is exist
            for (ix = pos[2] + 1; ix < pos[4]; ++ix) {
                host += url[ix];
            }
            for (ix = pos[4] + 1; ix < slen; ++ix) {
                path += url[ix];
            }
        } else {
            for (ix = pos[2] + 1; ix < slen; ++ix) {
                host += url[ix];
            }
        }
    }// End of else
    if ( port == "" )
        host = "<default>";
    if ( path == "" )
        path = "<default>";
    return ;
}

int main() 
{
#if DEBUG
    freopen("E:\\zoj_1243.in", "r" ,stdin);
    freopen("E:\\zoj_1243.out", "w", stdout);
#endif
    
    int testCases;
    string url, protocol, host, port, path;
    
    scanf("%d", &testCases);
    for (int cas = 1; cas <= testCases; ++cas) {
        cin >> url;
        process(url, protocol, host, port, path);
        cout << "URL #" << cas << endl;
        cout << "Protocol = " << protocol << endl;
        cout << "Host     = " << host << endl;
        cout << "Port     = " << port << endl;
        cout << "Path     = " << path << endl << endl;
    }// End of while
    return 0;
}
