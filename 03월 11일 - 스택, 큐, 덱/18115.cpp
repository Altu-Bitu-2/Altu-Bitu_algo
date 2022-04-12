#include <iostream>
#include <deque>
#include <vector>

using namespace std;

// 1. 제일 위 1장을 바닥에 둠
// 2. 제일 위에서 2번재 카드를 바닥에 둠. n>2일때만 가능
// 3. 제일 밑 카드를 바닥에 둠. n>2일 때만 가능. 

int main()
{
	int n;
	deque<int> q;
	deque<int> init;
	cin >> n;
	vector<int> x(n);

	for (int i = 0; i < n; i++)
	{	
		cin >> x[i];
		q.push_front(i+1);
	}
	
	while(n--)
	{
		int tmp;
		switch (x[n])
		{
		case 1:
			init.push_back(q.back());
			q.pop_back();
			break;
		case 2:
			tmp = init.back();
			init.pop_back();
			init.push_back(q.back());
			q.pop_back();
			init.push_back(tmp);
			break;
		case 3:
			init.push_front(q.back());
			q.pop_back();
			break;
		}
	}

	int size = init.size();

	for(int i= 0 ; i<size; i++)
	{
		cout << init.back() << ' ';
		init.pop_back();
	}
	return 0;
}