#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int SIZE = 21; // 1-20까지 사용하니까 그만큼의 배열 선언

/**
 * [집합] - 단순 구현 문제
 *
 * ver1. 배열 사용 풀이
 * set()을 사용해서 매번 연산을 하면 시간이 굉장히 오래 걸려요.
 * 입력되는 x의 값이 1~20으로 범위가 매우 작기 때문에, 각 숫자가 집합에 들어있는 여부를 저장하는 배열을 이용합니다.
 *
 * 1. 집합에는 1~20의 숫자만 입력 or 제거됨 (=true or false)
 * 2. 크기 21의 bool 배열을 선언
 * 3. 입력은 true 처리, 제거는 false 처리
 */

int main()
{
	// standard input output buffer을 끊어줌. stdio 혼용 불가
	ios::sync_with_stdio(false);
	cin.tie(NULL); // cin 버퍼 묶인거 풀어줌

	int m, num;					 //커멘드 개수, 커맨드에 사용할 변수 생성
	string cmd;					 //커맨드 변수 생성
	vector<bool> s(SIZE, false); // 전체가 false인 길이가 21인 배열 생성. 1-20 인덱스로 접근

	cin >> m; // 커맨드 개수
	while (m--)
	{				// 커맨드 개수 변수가 0이 될때까지 while 문 돌아감
		cin >> cmd; // 커맨드 받아옴
		if (cmd == "all")
		{						  // all 일 경우,
			s.assign(SIZE, true); // vector를 모두 true로 변경, 다음 while loop으로 넘어감.
			continue;
		}
		if (cmd == "empty")
		{						   // empty인 경우
			s.assign(SIZE, false); // vector을 모두 false로 변경,
			continue;			   // 다음 while loop으로 넘어감.
		}

		cin >> num; // add, remove, check, toggle일 때는 커맨드에 사용할 변수도 같이 받아온다.
		if (cmd == "add")//command가 add일 경우
		{
			s[num] = true; //해당 인덱스의 벡터값을 true로 변경. 
			continue; // 다음 루프로 넘어감
		}
		if (cmd == "remove") //커맨드가 remove일 경우
		{
			s[num] = false; //해당 인덱스 값을 false로 변경
			continue; // 다음 루프로 넘어감
		}
		if (cmd == "check") // 커맨드가 check일경우
		{
			cout << s[num] << '\n'; // bool 형을 출력하면 true: 1, false: 0으로 출력
			continue; // 다음 루프로 넘어감
		}
		if (cmd == "toggle") //토글일 경우
		{
			s[num] = !s[num]; //해당 인덱스의 값을 반대로 변경. false->true, true -> false
			continue; // 다음 루프로 넘어감
		}
	}
	return 0;
}