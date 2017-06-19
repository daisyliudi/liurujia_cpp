#include<iostream>
#include<set>
#include<map>
using namespace std;
#define maxn 500005
map<set<int>, int> mpst;
set<int> st[maxn];
int main()
{
	int n, k, t;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> k >> t;
		st[i].insert(k);
		st[i].insert(t);
		if (!mpst.count(st[i])) mpst[st[i]] = 0;
		mpst[st[i]]++;

	}
	int flag = 0;
	for (map<set<int>, int>::iterator i = mpst.begin(); i != mpst.end(); ++i)
		if (i->second % 2 != 0)
		{
		flag = 1;
		break;
		}
	if (flag == 1)
		printf("No");
	else
		printf("Yes");
	return 0;

}
