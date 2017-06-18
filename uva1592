#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<utility>
using namespace std;
#define MP(a, b) make_pair(a, b)
#define PB(a) push_back(a)
typedef pair<int, int> pii;
typedef map<string, int> mpsi;
typedef map<pii, int> mppi;
string database[1005][5];
mpsi IDcache;
vector<string> strcache;
int ID(const string& s)
{
	if (IDcache.count(s)) return IDcache[s];
	strcache.push_back(s);
	return IDcache[s] = strcache.size() - 1;
}
int m, n;
void read_str()
{
	
	string sline;
	cin>>n>>m;
	
	for (int i = 0; i < n; ++i)
	{
		int k = 0;
		getchar();
		getline(cin, sline);
		for (int j = 0; j <sline.length(); ++j)
			if (sline[j] != ',')
				database[i][k] += sline[j];
			else k++;
	}

}

int main()
{
	mppi saomiao;
	pair<int, int> topair;
	read_str();
	for (int i = 0; i < m; ++i)
		for (int j = i+1; j <m; ++j)
		{
		for (int k = 0; k < n; ++k)
		{
			topair = make_pair(ID(database[k][i]), ID(database[k][j]));
			if (saomiao.count(topair))
			{
				printf("YES");
				return 0;
			}
			saomiao[topair] =0;
		}
		}
	printf("NO");
	return 0;
}

