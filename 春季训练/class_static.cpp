/**
 * PROG: class static
 */
#include <cstdio>

class Date
{
public:
    Date();

    int day() const;
    int month() const;
    int year() const;

    static void PrintDate();

private:
    int d, m, y;
};

Date::Date()
{
    y = 2014;
    m = 1;
    d = 9;
}

void Date::PrintDate()
{
    printf("static void PrintDate()\n");
}

inline int Date::year() const
{
    //y++;
    return y;
}

int main(void)
{
    Date::PrintDate();

    Date date;
    printf("year is %d\n", date.year());

    return 0;
}
