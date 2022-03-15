#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int available(int alpha[])
{
	int count = 0;
	for (int i = 0; i < 26; i++)
		if (alpha[i] %2 == 1)
			count++;
	return count > 1;
}

int main()
{
	string s;
	int alpha[26] = {0, };

	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		alpha[s[i] - 'A']++;
	}
	if (available(alpha))
    {
        cout << "I'm Sorry Hansoo"; 
        return 0;
    }
	string r = "";
	char m = 0;
	for ( int i = 0; i < 26; i++)
	{
		for (int j = 0; j < alpha[i]/2; j++)
			r += char(i + 'A');
		if (alpha[i] % 2 == 1)
			m = char(i + 'A');
	}
	string rev = r;
	reverse(rev.begin(), rev.end());
	string tmp = rev;
	if (m!=0)
           r = r + m + tmp;
    else
        r = r + tmp;
	cout << r << '\n';
	return 0;
}