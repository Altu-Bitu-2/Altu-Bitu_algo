#include <iostream>

using namespace std;
# define DAY 3600*24

int main() {
	// c언어용 버퍼 사용안함.. 딜레이 사라짐. 대신에 c언어 함수 사용 안함
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int	h, m, s;
	int	q, t, c, cur;

	cin >> h >> m >> s;
	cin >> q;
	cur = 3600 * h + 60 * m + s;

	while (q-- > 0)
	{
		cin >> t;
		switch (t)
		{
		case 1:
			cin >> c;
			// 설마 int 범위를 넘겠어..하고 안일하게 생각한 죄 
			cur = (cur + c)%DAY;
			break;
		case 2:
			cin >> c;
			cur = cur - c;
			while (cur < 0)
				cur += DAY;
			break;
		case 3:
			cout << (cur/3600)%24 << ' ' << (cur/60)%60 << ' ' <<cur % 60 << '\n';
			break;
		default:
			break;
		}
	}
	return 0;
}