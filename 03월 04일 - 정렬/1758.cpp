#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	long long total = 0;
	for (int i = 0; i < n; i++)
		if (v[i] - i > 0)
			total += v[i] - i;
	cout << total << '\n';
	return 0;
}
