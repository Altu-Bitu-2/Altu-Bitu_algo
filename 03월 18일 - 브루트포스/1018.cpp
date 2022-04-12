#include <iostream>
#include <string>

using namespace std;

string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};
string board[50];
int cnt(int x, int y, string op[])
{
	int cnt = 0;

	 for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(board[x+i][y+j] != op[i][j])
                cnt++;
        }

    }
    return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	int min_val = 64;
	for(int i = 0; i + 8 <= n; i++)
    {
        for(int j = 0; j + 8 <= m; j++)
        {
            int tmp;
            tmp = min(cnt(i,j,BW),cnt(i,j,WB));
            if(tmp < min_val) {
                min_val = tmp;
            }
        }
    }
	cout << min_val << '\n';
	return 0;
}