#include <iostream>
#include <map>

using namespace std;


bool check(string s)
{
	int arr[26] = {false, };
	for(int i = 0; i < s.size(); i++)
	{
		if(arr[s[i]-'a'] && s[i-1] != s[i])
			return false;
		else
			arr[s[i]-'a'] = true;
	}
	return true;
}
int main() {
	int n, cnt = 0;
	//단어 개수
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		if (check(tmp))
			cnt++;
	}

	cout << cnt << '\n';
	return 0;
}