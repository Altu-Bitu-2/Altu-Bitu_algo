#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b, output = "";
	cin >> a >> b;

	int a_size = a.length();
	int b_size = b.length();
	
	// up은 올림
	int tmp = 0, up = 0;
	while(a_size > 0 || b_size > 0)
	{
		int ap = 0, bp = 0;
		if(a_size > 0)
			ap = a[--a_size] - '0';
		if (b_size > 0)
			bp = b[--b_size] - '0';
		tmp = ap + bp + up;
		up = tmp / 10;
		output += (char)(tmp % 10 + '0');
	}
	if (up > 0)
		output += (char)(up + '0');
	reverse(output.begin(), output.end());
	cout << output << '\n';

	return 0;
}