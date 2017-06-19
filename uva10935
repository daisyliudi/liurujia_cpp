#include<iostream>
#include<queue>

using namespace std;
//Throwing cards away i,uva10935
queue<int> s;
int main()
{
	int n;
	while (!s.empty()) s.pop();
	cin >> n;
	for (int i = 0; i < n; ++i)
		s.push(i);
	while (s.size() >= 2)
	{
		cout << s.front();
		s.pop();
		s.push(s.front());
		s.pop();
	}
	cout << s.front();
	return 0;
}
