#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<char> op;
	string ans = "";

	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (isalpha(s[i]))
			ans += s[i];
		else if (s[i] == '(')
			op.push(s[i]);
		else if (s[i] == ')')
		{
			while (!op.empty() && op.top() != '(')
			{
				ans += op.top();
				op.pop();
			}
			op.pop();
		}
		else if (s[i] == '*' || s[i] == '/')
		{
			// 
			while (!op.empty() && (op.top() == '*' && op.top() == '/'))
			{
				ans += op.top();
				op.pop();
			}
			op.push(s[i]);
		}
		else if (s[i] == '+' || s[i] == '-')
		{
			while (!op.empty() && op.top() != '(')
			{
				ans += op.top();
				op.pop();
			}
			op.push(s[i]);
		}
	}
	while (!op.empty())
	{
		ans += op.top();
		op.pop();
	}
	cout << ans << '\n';
	return 0;
}