#include <iostream>
#include <vector>

using namespace std;

vector<int> possibleWeight(int left, int right, int g) {
    vector<int> ans; // 벡터 선언
    while (left < right) { //왼쪽이 더 작은 동안
        int diff = right * right - left * left; //제곱의 차 구하기

        if (diff <= g) { // 제곱의 차가 g보다 작거나 같으면
            if (diff == g) { // 같을 경우 
                ans.push_back(right); // right값을 push 
            }
            right++; // right 값 추가
        } else { //diff가 더 크면 
            left++; //left 값 추가
        }
    }
    return ans; // 백터 반환
}

/**
 * [다이어트]
 *
 * left: 성원이가 기억하고 있던 몸무게
 * right: 성원이의 현재 몸무게
 *
 * 같은 위치에서 시작해서 점점 증가하는 투 포인터로 풀이
 * 대신, left ~ right를 모두 고려하는 것이 아니라 left, right 포인터 값 자체만 고려
 *
 * !주의! 몸무게의 범위가 딱히 정해져 있지 않으므로, 종료 조건을 잘 세우는 것이 중요!
 *       -> 두 몸무게가 같아지는 순간 종료!
 *       -> left가 right와 같은 값을 가진다면, 직전 상황은 두 몸무게가 1차이 나는 상황
 *       -> 이때 몸무게 차이가 g 이상이었다는 것은 이후로 나올 수 있는 차이는 무조건 g이상이 된다. (제곱수의 간격은 수가 커질수록 늘어나기 때문)
 */

int main() {
    int g; // 변수 선언

    //입력
    cin >> g;

    //연산
    vector<int> ans = possibleWeight(1, 2, g);

    //출력
    if (!ans.size()) { // 벡터에 값이 없으면
        cout << "-1"; //-1 리턴
        return 0; // 프로그램 종료
    }
    for (int i = 0; i < ans.size(); i++) { // 벡터 사이즈만큼
        cout << ans[i] << '\n'; // 출력
    }
    return 0; // 프로그램 종료
}