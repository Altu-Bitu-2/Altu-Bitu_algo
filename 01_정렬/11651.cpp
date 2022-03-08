#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 주소값 조심 ,, 
bool cmparg(pair <int, int> &a, pair <int, int> &b)
{
	if (a.second != b.second)
		return a.second <  b.second;
	return a.first < b.first;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> c(n);
	for(int i = 0; i < n; i++)
		cin >> c[i].first >> c[i].second;
	sort(c.begin(), c.end(), cmparg);
	
	for (int i =0; i<n; i++)
		cout << c[i].first << ' ' << c[i].second << '\n';
	return 0;
}