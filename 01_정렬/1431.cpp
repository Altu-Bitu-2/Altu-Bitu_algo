#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int chkSum(string &a)
{
	int sum = 0;

	for(int i = 0; i < a.length(); i++)
	{
		if ( '0' <= a[i] && a[i] <= '9')
			sum = sum + a[i] - '0';
	}
	return sum;
}

bool chkAlpha(string &a, string &b)
{
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] < b[i])
			return true;
		if (a[i] > b[i])
			return false;
	}
}
	// 1. 짧은 것
	// 2. 자리수의 합이 작은 것
	// 3. 사전 순서
bool cmparg(string &a, string &b)
{
	if(a.length() != b.length())
		return a.length() < b.length();
	int a_sum = chkSum(a);
	int b_sum = chkSum(b);
	if (a_sum != b_sum)
		return a_sum < b_sum;
	return chkAlpha(a, b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<string> v(n);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(), cmparg);	

	for(int i = 0; i < n; i++)
		cout << v[i] <<'\n';

	return 0;
}