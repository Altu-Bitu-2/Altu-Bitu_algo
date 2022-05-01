#include <iostream>
#include <vector>

using namespace std;

int steal(int n, int m, int k, vector<int> &house) {
    //윈도우 초기화
    int money = 0; // 돈 init
    for (int i = 0; i < m; i++) { //도둑이 돈을 훔칠 연속된 집 동안
        money += house[i]; // 돈 더하기
    }
    int ans = money < k; //훔쳐야 하는 집 초기화

    if (n == m) { //훔칠 수 있는 경우 딱 1개인 경우
        return ans; // ans 리턴
    }
    for (int i = m; i < n + m - 1; i++) { //n번동안
        money -= house[i - m]; // -m번째 취소
        money += house[i % n]; // 원형이니까 나머지로 i%n 번째 추가
        if (money < k) { // 여전히 k보다 적다면
            ans++; // ans 추가
        }
    }
    return ans; // ans 반환
}

/**
 * [도둑]
 *
 * 1. 연속해서 훔쳐야 할 집이 m으로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * !주의! 마을에 있는 집의 개수와 도둑이 훔칠 집의 개수가 같을 때(n==m) 도둑이 훔칠 수 있는 경우의 수 1개!
 *    => 예를 들어, n = m = 3, k = 4, house = [1, 1, 1] 일 때, 실제 방법의 수는 1번, 2번, 3번 집을 택하는 경우밖에 없지만
 *       예외 처리를 안해줄 경우, 원형으로 돌며 3을 출력하게 됨!
 */

int main() {
    int t, n, m, k; //변수 선언

    cin >> t; //테스트 데이터 개수
    while (t--) { //테스트 데이터 개수동안
        //입력
        cin >> n >> m >> k; //입력
        vector<int> house(n, 0); // 집 벡터 생성
        for (int i = 0; i < n; i++) {
            cin >> house[i]; // 각각 보관중인 돈의 양
        }

        //연산 & 출력
        cout << steal(n, m, k, house) << '\n';
    }
    return 0; // 프로그램 종료 
}