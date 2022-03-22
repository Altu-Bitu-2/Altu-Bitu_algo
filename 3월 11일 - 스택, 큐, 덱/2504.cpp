#include <iostream>
#include <stack>
#include <map>
using namespace std;

int balance(string &s)
{
	int tmp = 1;
	int ans = 0;
	stack<int> st;
	map<char, char> m;
	map<char, int> cal;
	// 괄호 미리 매핑
	m[')'] = '(';
	m[']'] = '[';
	//숫자 매핑
	cal['('] = 2;
	cal['['] = 3;
	cal[')'] = 2;
	cal[']'] = 3;

	bool flag = false;
	for (int i = 0; i < s.length(); i++)
	{
		switch (s[i])
		{
		case '(':
		case '[':
			st.push(s[i]);
			tmp *= cal[s[i]];
			flag = true;
			break;
		case ')':
		case ']':
			if (st.empty() || st.top() != m[s[i]])
			{ //스택 비었거나, 종류 안맞음
				return 0;
			}
			if (flag == true)
				ans += tmp;
			tmp /= cal[s[i]];
			st.pop();
			flag = false;
			break;
		}
	}
	if (!st.empty())
		return 0;
	return ans;
}
int main()
{
	string s;
	cin >> s;
	cout << balance(s);
	return 0;
}