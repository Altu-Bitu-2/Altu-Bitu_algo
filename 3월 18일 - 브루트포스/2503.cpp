#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci; // 스트라이크 카운트와 볼 카운트를 위한 페어 스트럭쳐 생성

struct baseball { //baseball structure 생성
    string num;       //서로 다른 세 자리 수
    int strike, ball; //스트라이크 개수, 볼 개수
};

ci cntStrikeBall(string &s1, string &s2) {
    int strike_cnt = 0; //s1과 s2사이의 strike 개수
    int ball_cnt = 0;   //s1과 s2사이의 ball 개수

    for (int i = 0; i < 3; i++) { // 세자리수니까 3번만 반복
        if (s1[i] == s2[i]) { //위치+수 정확히 일치 -> 스트라이크
            strike_cnt++; // 스트라이트 카운트 증가
        }
        else if (s1.find(s2[i]) != s1.npos) { //위치 다른데 수가 존재 -> 볼
            ball_cnt++; // 볼 카운트 증가
        }
    }

    return ci(strike_cnt, ball_cnt); //스트라이크 카운트와 볼 카운트를 리턴
}

int game(int n, vector<baseball> &question) {
    int ans = 0; //정답 개수

    for (int i = 123; i <= 987; i++) { //숫자가 가능한 범위동안 돌리기 
        bool check = true; // 각 세자리수를 체크할 때 true로 선언 
        string s1 = to_string(i);  //정답인지 확인할 수

        if (s1[0] == '0' || s1[1] == '0' || s1[2] == '0') { //0이 하나라도 있다면
            continue; // 0이 하나라도 있다면 패스
        }
        if (s1[0] == s1[1] || s1[0] == s1[2] || s1[1] == s1[2]) { //서로 같은 수 하나라도 있다면
            continue; // 같은 숫자가 있으면 패스
        }

        for (int j = 0; j < n; j++) { // 입력받은 수의 개수 동안 for문 돌리기.
            string s2 = question[j].num; //질문으로 들어온 수
            ci cnt = cntStrikeBall(s1, s2); //s1과 s2사이의 스트라이크와 볼 개수
            if (cnt.first != question[j].strike || cnt.second != question[j].ball) { //하나라도 다르면
                check = false; //세자리수 체크를 멈추고, 해당 i가 세자리수가 될 수 없기 때문에 false.
                break; // 해당 for문 탈출
            }
        }

        if (check) { //true일 경우
            ans++; // ans 개수 늘리기
        }
    }

    return ans; // 가능한 세자리수 개수 리턴
}

/**
 * [숫자 야구]
 * 서로 다른 세 자리 수에서 위치 + 수 같으면 스트라이크, 위치는 다르고 수가 존재하면 볼
 * n개의 질문으로 수와 스트라이크와 볼 개수가 주어질 때, 이를 모두 만족하는 서로 다른 세 자리 정답 수의 개수
 *
 * [풀이]
 * 서로 다른 세 자리수는 123 ~ 987이 가능하다. 이는 총 865가지
 * 질문 n의 범위는 최대 100
 * 따라서 123부터 하나씩 증가시키며 정답이 되는지 검사해도 865 * 100 * 3(자릿수)으로 접근 충분히 가능!
 */

int main() {
    int n; // 입력받는 정수 선언

    //입력
    cin >> n;

    vector<baseball> question(n); //baseball structure로 이루어진 vetor 생성
    for (int i = 0; i < n; i++) { // vector의 원소 개수만큼 숫자와 strike, ball을 순서대로 받는다. 
        cin >> question[i].num >> question[i].strike >> question[i].ball; // 벡터에 차례대로 넣기
    }

    //연산 + 출력
    cout << game(n, question); //game 함수 결과값 출력

    return 0; // 프로그램 종료
}