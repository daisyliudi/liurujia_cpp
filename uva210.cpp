#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<deque>
using namespace std;
#define maxn 20
int n;//表示有几个程序
int time[5];
map<char, int> tim;
deque<int> wait;
queue<int> stop;
queue<string> prog[maxn];
map<queue<string>,int> bexuhao;
map<char, int> value;
int	q;
void getque()
{
	string cols;
	cin >> n;
	for (int i = 0; i < 5; ++i)
		cin >> time[i];
	cin >> q;
	getchar();
	tim['='] = time[0];
	tim['i'] = time[1];
	tim['c'] = time[2];
	tim['l'] = time[3];
	tim['d'] = time[4];
	for (int i = 1; i <= n; ++i)
	{
		while (getline(cin, cols))
		{
			prog[i].push(cols);//prog[i]表示第i个程序
			if (cols == "end")
				break;
		}
		
		wait.push_back(i);//生成等待序列
	}
}
int becomint(const string &s)
{
	int z = 1;
	int value = 0;
	for (int i = s.length() - 1; i >= 0; --i)
	{
		value += (s[i]-'0')* z;
		z *= 10;
	}
	return value;

}

int main()
{
	int sumt;
	string yuju;
	int lock = 0;
	getque();
	printf("ok\n");
	while (1)
	{
		int t;
		sumt = 0;//对当前运行时间的计数
		if (!wait.empty())
		{
			t = wait.front();
			//wait.pop_front();
		}
		else
			break;
		while (1)
		{

			if (!prog[t].empty())
			{
				yuju = prog[t].front();
				prog[t].pop();
			}
			else
				break;
			sumt += tim[yuju[2]];
			if (yuju[2] == '=')//是赋值程序
			{
				int duan = becomint(yuju.substr(4));
				//printf("%d\n", duan);
				value[yuju[0]] = duan;
			}
			if (yuju[2] == 'i')
			{
				if (value.count(yuju[6]) == 0) value[yuju[6]] = 0;
				printf("%d : %d\n", t, value[yuju[6]]);
			}
			if (yuju[2] == 'c')
			{
				if (lock == 1)
				{
					wait.pop_front();//结束当前程序
					stop.push(t);//进入停止序列
					break;//当前执行结束
				}
				else
					lock = 1;
			}
			if (yuju[2] == 'l')
			{
				lock = 0;
				if (stop.size() != 0)
				{
					wait.push_front(stop.front());//阻止队列的第一个程序进入等待队列
					stop.pop();
					
				}
				break;
			}
			if (yuju[2] == 'd')
			{
				wait.pop_front();
				break;

			}
			if (sumt >= q)//因为配额没有了所以推出了，放到最后重新来
			{
				if (!prog[t].empty())
				{
					wait.push_back(t);
					wait.pop_front();
				}
				
				break;
				
				//当前配额已经够了，程序还没运行完的话
			
			}

		}
		
	}
	return 0;
}

		
