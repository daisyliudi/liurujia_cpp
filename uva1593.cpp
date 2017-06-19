#include<algorithm>
using namespace std;

const int maxn = 1005;
const int maxcol = 180;
//输出字符串,长度不足补字符extra
void print(const string& s, int len, char extra)
{
	cout << s;
	for (int i = s.length(); i < len; ++i)
		cout << extra;
}
int main()
{	
	string s;
	string t;
	int k = 0;
	int countmax=0;
	vector<string> vs[maxn];
	while (getline(cin, s))
	{
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] != ' ')  t += s[i];
			else
			{
				if (t.length()!= 0)
				{
					vs[k].push_back(t);
					countmax = max(countmax,(int) t.length());
					t.clear();
				}
			}
		}
		vs[k].push_back(t);
		t.clear();
		k++;	    
	}
	//输出
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < vs[i].size(); ++j)
			print(vs[i][j], countmax + 1, ' ');
		printf("\n");
	}
	return 0;

	
}

