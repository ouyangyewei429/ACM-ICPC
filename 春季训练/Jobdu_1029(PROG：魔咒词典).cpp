/**
 * PROG: Ä§Öä´Êµä
 */
#include <map>
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

void SpiltString(map<string, string>& spell, const string& strBunch)
{
    string incantation;
    string effect;

    int index = 0;
    while (']' != strBunch[index])
    {
        incantation += strBunch[index];
        ++index;
    }
    incantation += strBunch[index++];

    int strLen = strBunch.length();
    for (index++; index<strLen; ++index)
    {
        effect += strBunch[index];
    }
    spell[incantation] = effect;
    spell[effect] = incantation;
    //cout << incantation << "--" << effect << endl;
}

int main(void)
{
    string strBunch;
    map<string, string> spell;
    while (getline(cin, strBunch))
    {
        if ("@END@" == strBunch)
        {
            break;
        }

        SpiltString(spell, strBunch);
    }

    int nRecords;
    cin >> nRecords;
    getchar();
    for (int i=0; i<nRecords; ++i)
    {
        getline(cin, strBunch);
        if (!spell[strBunch].empty())
        {
            string strResult = spell[strBunch];
            if ('[' == strResult[0])
            {
                int strLen = strResult.length();
                for (int j=1; j<strLen-1; ++j)
                {
                    cout << strResult[j];
                }
                cout << endl;
            }
            else
            {
                cout << strResult << endl;
            }
        }
        else
        {
            cout << "what?" << endl;
        }
    }
    return 0;
}
