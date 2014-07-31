/**
 * PROG: 会员积分排序
 */
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Customer
{
    int m_id;
    int m_credits;

    Customer(int id, int credit)
    {
        m_id = id;
        m_credits = credit;
    }
};

int compare_rule(const Customer& a, const Customer& b)
{
    if (a.m_credits == b.m_credits)
    {
        return (a.m_id < b.m_id);
    }
    else
    {
        return (a.m_credits > b.m_credits);
    }
}

int main(void)
{
    int id, credit;
    int nCustomer, nGift;

    while (~scanf("%d %d", &nCustomer, &nGift))
    {
        vector<Customer> vect;
        for (int i=0; i<nCustomer; ++i)
        {
            scanf("%d %d", &id, &credit);
            Customer customer(id, credit);
            vect.push_back(customer);
        }

        sort(vect.begin(), vect.end(), compare_rule);

        nGift = (nGift > nCustomer ? nCustomer : nGift);
        for (int j=0; j<nGift; ++j)
        {
            printf("%d\n", vect[j].m_id);
        }
    }// End of While

    return 0;
}
