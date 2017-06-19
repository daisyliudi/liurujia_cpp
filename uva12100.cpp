#include<iostream>
#include<queue>
using namespace std;
#define maxn 105
struct fil
{
	int ux;//优先级
	int id;//文件名称
	
}f[maxn];
queue<fil> yuanshi;
priority_queue<int> paixu;
int main()
{
	int n,m,time=0;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> f[i].ux;
		f[i].id = i;
		yuanshi.push(f[i]);
		paixu.push(f[i].ux);
	}
	while (time<=n)
	{
		if (yuanshi.front().ux != paixu.top())
		{
			yuanshi.push(yuanshi.front());
			yuanshi.pop();
		}
		else
		{
			time++;
			paixu.pop();
			if (yuanshi.front().id == m)
			{
				cout << time;
				break;
			}
			yuanshi.pop();
		}

	}  
}
