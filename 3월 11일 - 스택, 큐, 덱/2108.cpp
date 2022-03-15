#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void findA(vector<int> v, int n, int &a)
{
	a = 0;
	while(n--)
		a += v[n];
	a = round(a/(double)v.size());
}
void findB(vector<int> &v, int n, int &b)
{
	b = v[n/2];
}
void findC(vector<int> v, int n, int &c)
{
	vector<int> vec(8001, 0);
	for(int i = 0; i < n; i++)
		vec[v[i]+ 4000]++;
	int max = *max_element(vec.begin(), vec.end());
	c = max_element(vec.begin(), vec.end()) - vec.begin();
	if (find(vec.begin()+c+1, vec.end(), max) != vec.end())
	{
		c = find(vec.begin()+c+1, vec.end(), max) - vec.begin();
	}
	c -= 4000;
}
void findD(vector<int> &v, int n, int &d)
{
	d = v[n-1] - v[0];
}
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	int a, b, c, d;
	findA(v, n, a);
	findB(v, n, b);
	findC(v, n, c);
	findD(v, n, d);
	cout << a << '\n' << b << '\n' << c<< '\n' << d << '\n';

	return 0;
}