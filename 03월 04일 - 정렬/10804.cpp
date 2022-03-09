#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> v(20);
	int s, e;

	for(int i = 0; i < 20; i++)
		v[i] = i+1;
	for(int i = 0; i < 10; i++)
	{
		cin >> s >> e;
		reverse(v.begin() + s - 1, v.begin() + e);	
	}

	for(int i = 0; i < 20; i++)
		cout << v[i] << " ";
	cout << endl;	
	return 0;
}