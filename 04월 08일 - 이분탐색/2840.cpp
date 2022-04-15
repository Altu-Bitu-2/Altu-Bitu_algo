#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, char> ci; // 압력을 페어로 받는다

//특정 화살표에서 시작한 행운의 바퀴 리턴
string arrowStartWheel(int arrow_point, int n, vector<char> &wheel) {
    string ans = ""; // 빈 스트링 생성
    int start = arrow_point; // 화살표가 가리킨 인덱스 부터 시작
    do {
        ans += wheel[arrow_point]; // ans스트링에 화살표가 가리킨 문자를 더해준다
        arrow_point = (arrow_point + 1) % n; // 다음 arrow point
    } while (arrow_point != start); // arrowpoint가 start지점이 되기 전까지, 즉 한바퀴 돌린다.
    return ans; //바퀴에 적힌 문자 스트링 반환
}

//행운의 바퀴 구하는 함수
string makeWheel(int n, vector<ci> &record) {
    vector<char> wheel(n, '?'); //바퀴의 상태
    vector<bool> is_available(26, false); //알파벳 중복 체크

    int idx = 0; //화살표가 가리키는 인덱스
    for (int i = 0; i < record.size(); i++) { // k번만큼 돌아감
        int rot = record[i].first; // 몇번 바뀌었는지
        char alpha = record[i].second; // 가리키던 글자 
        idx = (idx - rot % n + n) % n; // 화살표가 가리키는 인덱스
        if (wheel[idx] == alpha) { // 해당 인덱스에 alpha가 존재하면
            continue; // 다음 for loop
        }
        if (wheel[idx] != '?' || is_available[alpha - 'A']) { //해단 인덱스가 결정하지 못한 칸이 아니거나, 해당 문자가 존재하면
            return "!"; //해운의 바퀴가 없음을 반환
        }
        wheel[idx] = alpha; // 인덱스가 ?면 alpha를 넣는다
        is_available[alpha - 'A'] = true; // 해당 문자가 존재함 체크
    }
    return arrowStartWheel(idx, n, wheel);// 행운의 바퀴를 리턴
}

/**
 * [행운의 바퀴]
 *
 * 바퀴가 돌아갈 필요 X
 * 화살표가 가르키는 인덱스를 회전 정보에 따라 바꿔줌
 *
 * 1. 화살표가 가르키는 칸이 결정되지 않았으면 알파벳을 바퀴에 적는다.
 * 2. 이미 알파벳이 써 있는 경우, 같은 알파벳이 아닌 경우 조건에 해당하는 바퀴 만들 수 없다.
 * 3. 바퀴에 쓰여있는 알파벳은 중복되지 않으므로 동일한 알파벳이 여러 자리에 있을 수 없다.
 */

int main() {
    int n, k; // 바퀴의 칸 수, 돌리는 횟수 선언 

    //입력
    cin >> n >> k; // 사용자 입력
    vector<ci> record(k, {0, 0}); //바퀴 회전 기록
    for (int i = 0; i < k; i++) { //k번동안 for loop
        cin >> record[i].first >> record[i].second; //사용자에게 가리키는 글자가 몇번 바뀌었는지, 가리키던 글자
    }

    //연산 & 출력
    cout << makeWheel(n, record);
    return 0; // 종료
}