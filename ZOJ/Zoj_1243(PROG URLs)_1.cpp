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

#define DEBUG 0

void process(string &url, string &protocol,
             string &host, string &port, string &path)
{
    string::size_type ix;
    string::size_type slen = url.length();
    int ax = 0, bx = 0, ap[100] = {0}, bp[100] = {0};

    for (ix = 0; ix < slen; ++ix) {
        if ( url[ix] == ':' )
            ap[ax++] = ix;
        else if ( url[ix] == '/' )
            bp[bx++] = ix;
    }

    protocol = host = "", port = path = "";
    for (ix = 0; ix < ap[0]; ++ix) {
        protocol += url[ix];
    }
    if ( ap[1] ) {  // port is exist
        for (ix = bp[1] + 1; ix < ap[1]; ++ix) {
            host += url[ix];
        }// End of for
        if ( bp[2] ) {
            for (ix = ap[1] + 1; ix < bp[2]; ++ix)
                port += url[ix];
            for (ix = bp[2] + 1; ix < slen; ++ix)
                path += url[ix];
        } else {  // path is not exist
            for (ix = ap[1] + 1; ix < slen; ++ix)
                port += url[ix];
        }// End of else
    } else {
        if ( bp[2] ) {
            for (ix = bp[1] + 1; ix < bp[2]; ++ix)
                host += url[ix];
            for (ix = bp[2] + 1; ix < slen; ++ix)
                path += url[ix];
        } else {  // path is not exist
            for (ix = bp[1] + 1; ix < slen; ++ix)
                host += url[ix];
        }
    }// End of else

    if ( port == "" ) port = "<default>";
    if ( path == "" ) path = "<default>";
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
