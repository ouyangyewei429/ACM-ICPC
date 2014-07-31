#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>

using namespace std;


int k,result[201],ff[201];
string temps;
string::size_type t,j,i;

void add2(int *result,int *f1);

int main()
{/*
    freopen("E:\\hdoj_1047.txt", "r", stdin);
    freopen("E:\\hdoj_1047_1.txt", "w", stdout);
*/
	scanf("%d", &k);
	while(k)
	{
		result[0]=200;
		while(cin >> temps)
		{
			if(temps=="0")
			{
				break;
			}
			t=temps.size();
			ff[0]=200-t+1;
			for(j=ff[0],i=0;j<=200;j++,i++)
			{
				ff[j]=temps[i]-'0';
			}
			add2(result,ff);
			for(j=ff[0];j<=200;j++)
			{
				ff[j]=0;
			}
		}
		for(int i=result[0];i<=200;i++)
		{
			cout << result[i];
			result[i]=0;
		}
		if(k!=1)
		    cout << endl << endl;
		else
			cout << endl;
		k--;
	}
	return 0;
}

void add2(int *result,int *f1)
{
	int temp=f1[0];
	if(temp>result[0])
		temp=result[0];
	for(int i=200;i>=temp;i--)
	{
		result[i]+=f1[i];
		result[i-1]+=result[i]/10;
		result[i]=result[i]%10;
	}
	if(result[temp-1])
	{
		result[0]=temp-1;
	}
	else
	{
		result[0]=temp;
	}
}

