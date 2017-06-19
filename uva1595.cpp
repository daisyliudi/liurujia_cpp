//对称轴，uva1595
#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;
#define maxn 1005

vector<int> px[maxn];
struct point{
	int x, y;
}p[maxn];
map<int, vector<int>> mpvt;
int main()
{
	int n;
	set<int> isexist;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> p[i].x >> p[i].y;
		if (!mpvt.count(p[i].y)) mpvt[p[i].y] = vector<int>();
		mpvt[p[i].y].push_back(p[i].x);
	}
	for (map<int, vector<int>>::iterator it = mpvt.begin(); it != mpvt.end(); ++it)
	{
		int sum = 0, average = 0;
		for (int i = 0; i < it->second.size(); ++i)
			sum = sum + it->second[i];
		average = sum / it->second.size();
		isexist.insert(average);
	}
	if (isexist.size() != 1)
		cout << "no";
	else
		cout << "yes";
	return 0;
}
