/*
PROG:   packrec
ID  :   ouyangyewei
LANG:   C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct rect
{
	int x;
	int y;
}c[5],t[5],rec;

const int MAX=20000;
int ans[101], area=MAX;

void mycmp()
{
	if(rec.x*rec.y<area)
	{
		area=rec.x*rec.y;
		fill_n(ans+1,100,0);
	}
	if(rec.x*rec.y==area)
		ans[min(rec.x,rec.y)]=1;
}

void imitate()
{
	// ͼ1
	rec.x=0;
	rec.y=0;
	for(int i=1;i<=4;i++)
	{
		rec.x+=c[i].x;
		if(rec.y<c[i].y)
			rec.y=c[i].y;
	}
	mycmp();

	//ͼ2
	rec.x=0;
	rec.y=0;
	for(int i=1;i<=3;i++)
	{
		rec.x+=c[i].x;
		if(rec.y<c[i].y)
			rec.y=c[i].y;
	}
	rec.x=max(rec.x,c[4].y);
	rec.y+=c[4].x;
	mycmp();

	//ͼ3
	rec.x=c[1].x+c[2].x;
	rec.x=max(rec.x,c[3].y)+c[4].x;
	rec.y=max(max(c[1].y,c[2].y)+c[3].x,c[4].y);
	mycmp();

	//ͼ4��5
	rec.x=c[1].x+max(c[2].x,c[3].x)+c[4].x;
	rec.y=max(c[1].y,c[4].y);
	rec.y=max(rec.y,c[2].y+c[3].y);
	mycmp();

	//ͼ6
	rec.x = c[1].x+c[2].x;
	rec.y = max(c[1].y+c[3].y, c[2].y+c[4].y);
	if (c[1].y < c[2].y)
		rec.x = max(rec.x, c[3].x+c[2].x);
	if (c[1].y+c[3].y > c[2].y)
		rec.x = max(rec.x, c[3].x+c[4].x);
	if (c[2].y < c[1].y)
		rec.x = max(rec.x, c[1].x+c[4].x);
	rec.x = max(rec.x, c[3].x);
	rec.x = max(rec.x, c[4].x);
	mycmp();
}

void rotate()
{
	for(int i4=0;i4<=1;i4++)
	{
		for(int i3=0;i3<=1;i3++)
		{
			for(int i2=0;i2<=1;i2++)
			{
				for(int i1=0;i1<=1;i1++)
				{
					if(i1)
						swap(c[1].x,c[1].y);
					if(i2)
						swap(c[2].x,c[2].y);
					if(i3)
						swap(c[3].x,c[3].y);
					if(i4)
						swap(c[4].x,c[4].y);
					imitate();
					if(i1)
						swap(c[1].x,c[1].y);
					if(i2)
						swap(c[2].x,c[2].y);
					if(i3)
						swap(c[3].x,c[3].y);
					if(i4)
						swap(c[4].x,c[4].y);
				}
			}
		}
	}
}

int main() 
{
	freopen("packrec.in","r",stdin);
	freopen("packrec.out","w",stdout);

	for(int i=1;i<=4;i++)
		cin >> t[i].x >> t[i].y;
	for(int i1=1;i1<=4;i1++)
	{
		for(int i2=1;i2<=4;i2++)
		{
			if(i2==i1)
				continue;
			for(int i3=1;i3<=4;i3++)
			{
				if(i3==i2||i3==i1)
					continue;
				for(int i4=1;i4<=4;i4++)
				{
					if(i4==i1||i4==i2||i4==i3)
						continue;
					c[1]=t[i1];
					c[2]=t[i2];
					c[3]=t[i3];
					c[4]=t[i4];
					rotate();
				}
			}
		}
	}
	cout << area << endl;
	for(int i=1;i<=100;i++)
	{
		if(ans[i])
			cout << i << ' ' << area/i << endl;
	}
    return 0;
}
