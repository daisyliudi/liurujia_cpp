//uva10391
#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
map<string, int> cidian;
vector<string> ivec;

int main()
{
	string s;
	string sbegin, send;
	while (getline(cin, s))
	{

		ivec.push_back(s);
		cidian[s] = ivec.size() - 1;
	}
	for (int i = 0; i < ivec.size(); ++i)
	{
		for (int j = 1; j < ivec[i].length() - 1; ++j)
		{
			sbegin = ivec[i].substr(0, j);
			send = ivec[i].substr(j);
			if (cidian.count(sbegin) != 0 && cidian.count(send) != 0)
				cout << ivec[i]<<endl;
		}
	}
}
