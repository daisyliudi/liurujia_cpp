#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define maxn 16
int ducci[maxn];

int main()
{
	int n,k=1;
	int tmp;
	int flag = 1;
	cin>>n;
	for (int i = 0; i < n; ++i)
		cin>>ducci[i];
	while (k++ <= 1000 && flag)
	{
		flag = 0;
		tmp = ducci[0];
		for (int i = 0; i < n - 1; ++i)
			ducci[i] = abs(ducci[i] - ducci[i + 1]);
		ducci[n - 1] = abs(ducci[n - 1] - tmp);
		for (int i = 0; i < n; ++i)
			if (ducci[i] != 0)
			{
			flag = 1;
			break;
			}
	}
			if (k ==1001) printf("loop");
			else printf("zero!");
	
}
