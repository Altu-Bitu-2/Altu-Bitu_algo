#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int findAvg(vector<int> v, int n)
{
	int a = 0;
	while(n--)
		a += v[n];
	a = round(a/(double)v.size());
	return a;
}
int findMid(vector<int> &v, int n)
{
	return v[n/2];
}
int findMod(vector<int> v, int n)
{
	vector<int> vec(8001, 0);
	
	for(int i = 0; i < n; i++)
		vec[v[i]+ 4000]++;
	int max = *max_element(vec.begin(), vec.end());
	int c = max_element(vec.begin(), vec.end()) - vec.begin();
	if (find(vec.begin()+c+1, vec.end(), max) != vec.end())
	{
		c = find(vec.begin()+c+1, vec.end(), max) - vec.begin();
	}
	c -= 4000;
	return c;
}
int findDiff(vector<int> &v, int n)
{
	return (v[n-1] - v[0]);
}
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	int avg = findAvg(v, n);
	int mid = findMid(v, n);
	int mod = findMod(v, n);
	int diff = (v, n);
	cout << avg << '\n' << mid << '\n' << mod << '\n' << diff << '\n';

	return 0;
}