#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int available(map<char, int> al, int n, char &c)
{
	int count = 0;

	for (auto iter = al.begin(); iter != al.end(); iter++)
	{
		if (iter->second % 2 == 1)
		{
			c = iter->first;
			count++;
		}
	}
	return count > 1;
}

int main()
{
        ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	string s;
	map<char, int> al;

	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (al.find(s[i]) != al.end())
		{
			al[s[i]]++;
			continue;
		}
		al[s[i]] = 1;
	}
	char m = 0;
	if (available(al, s.length(), m))
    {
        cout << "I'm Sorry Hansoo\n";
		return 0;
    }
	string r = "";
	for (auto iter = al.begin(); iter != al.end(); iter++)
	{
		for (int i = 0; i < iter->second / 2; i++)
			r += iter->first;
	}
	string rev = r;
	reverse(rev.begin(), rev.end());
	if ( m!=0)
        r = r + m + rev;
    else
        r = r + rev;
	cout << r << '\n';
	return 0;
}