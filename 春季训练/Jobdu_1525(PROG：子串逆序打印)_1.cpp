/**
 * PROG: ×Ó´®ÄæÐò´òÓ¡
 */
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 100004;

char g_szBunch[MAX_SIZE] = {0};

int main(void)
{
    int strLen;
    while (cin >> strLen)
    {
        if (0 == strLen)
        {
            break;
        }

        getchar();
        gets(g_szBunch);

        bool isFirstPart = true;
        char *pStr = strtok(g_szBunch, " ");
        while (NULL != pStr)
        {
            string strPart = string(pStr);
            reverse(strPart.begin(), strPart.end());
            if (!isFirstPart)
            {
                cout << " ";
            }
            else
            {
                isFirstPart = false;
            }
            cout << strPart;

            pStr = strtok(NULL, " ");
        }
        cout << endl;
    }
    return 0;
}
