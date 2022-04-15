#include <iostream>
#include <map>

using namespace std;

/**
 * [IF문 좀 대신 써줘]
 *
 * 모든 캐릭터와 칭호를 매칭하는 브루트 포스를 사용하기엔 최대 연산 횟수 10^5 * 10^5 -> 100억!
 * 특정 전투력 '이하'까지 해당하는 칭호를 받을 수 있음
 * -> 이분 탐색
 *
 * 맵과 셋은 원소를 정렬된 상태로 저장하기 때문에 알고리즘 헤더 없이 자체적으로 이분 탐색 함수를 사용할 수 있음
 */

int main() {
    ios::sync_with_stdio(false); //stdio 버퍼 연결 끊기
    cin.tie(NULL); // cin 버퍼 연결 끊기

    map<int, string> title; //칭호와 그 칭호의 전투력 상한값

    int n, m, power; //입력받을 수 생성
    string name; // 칭호

    //입력
    cin >> n >> m; // 칭호의 개수, 캐릭터 개수 입력
    while (n--) { // 칭호 개수 동안 입력
        cin >> name >> power; //이름과 power입력
        if (title[power].empty()) { // 해당 전투력 상한값이 존재 하지 않으면
            title[power] = name; // 칭호 입력
        }
    }

    //출력
    while (m--) { // 캐릭터 개수 동안 
        cin >> power; // 퍄워 입력
        cout << title.lower_bound(power)->second << '\n'; //특정 전투력 보다 같거나 큰 숫자가 몇번째에 등장하는지 찾음 -> 그 값의 칭호 반환
    }
}