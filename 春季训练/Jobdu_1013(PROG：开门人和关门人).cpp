/**
 * PROG: 开门人和关门人
 */
#include <cstring>
#include <cstdio>

const int MAX_SIZE = 32;

int GetSeconds(const int hour, const int minute, const int seconds)
{
    return (hour*3600 + minute*60 + seconds);
}

int main(void)
{
    int nDays;
    int nRecords;
    int in_hour, in_minute, in_seconds;
    int out_hour, out_minute, out_seconds;

    char szName[MAX_SIZE] = {0};
    char szEarly[MAX_SIZE] = {0};
    char szLater[MAX_SIZE] = {0};

    scanf("%d", &nDays);
    while (nDays--)
    {
        int nEarly = 0x3fffffff;
        int nLater = -1;

        scanf("%d", &nRecords);
        for (int i=0; i<nRecords; ++i)
        {
            scanf("%s %d:%d:%d %d:%d:%d", szName,
                  &in_hour, &in_minute, &in_seconds,
                  &out_hour, &out_minute, &out_seconds);

            int checkin = GetSeconds(in_hour, in_minute, in_seconds);
            if (checkin < nEarly)
            {
                nEarly = checkin;
                //strncpy(szEarly, szName, sizeof(szName));
                strcpy(szEarly, szName);
            }
            int checkout = GetSeconds(out_hour, out_minute, out_seconds);
            if (checkout > nLater)
            {
                nLater = checkout;
                //strncpy(szLater, szName, sizeof(szName));
                strcpy(szLater, szName);
            }
            //printf("****%s %d %d****\n", szName, checkin, checkout);
        }
        printf("%s %s\n", szEarly, szLater);
    }// End of While

    return 0;
}
