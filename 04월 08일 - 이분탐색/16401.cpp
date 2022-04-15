#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int childNum(int len, vector<int> &snacks) {
    int cnt = 0; // 명 수 생성
    for (int i = snacks.size() - 1; i >= 0; i--) { //가장 긴 과자부터 검사
        if (snacks[i] < len) { //나누어주려는 길이보다 작아지면 더 이상 못 나눠줌
            break; // 못 나눠주면 끝
        }
        cnt += (snacks[i] / len); // snack/len 만큼의 사람에게 줄 수 있으니까 그만큼 더해준다
    }

    return cnt; // 줄 수 있는 사람수 반환
}

int upperSearch(int left, int right, int target, vector<int> &snacks) {
    while (left <= right) { //왼쪽 값이 오른쪽과 같거나 작은 동안
        int mid = (left + right) / 2; //과자의 길이
        int cnt = childNum(mid, snacks); //과자 길이가 mid일 때 몇 명에게 나눠주는지

        if (cnt >= target) { //target보다 더 많은 아이들에게 나눠준다면 -> 과자 길이를 더 늘릴 수 있음
            left = mid + 1; // 작은 값을 중간값+1로
        } else {
            right = mid - 1; // 큰 값을 중간값-1로 변경
        }
    }
    return left - 1; //left-1을 리턴
}

/**
 * [과자 나눠주기]
 *
 * n개의 과자가 있을 때 m명의 조카에게 각각 같은 길이로 줄 수 있는 과자의 최대 길이를 구하는 문제
 * -> 특정 과자 길이에 대하여 m명의 조카에게 나누어 줄 수 있는가?
 *
 * left: 과자 길이의 최솟값 -> 1
 * right: 과자 길이의 최댓값
 *
 * 과자를 몇 명에게 나누어줄 수 있는지 차례로 검사하다 나누어줄 수 없으면 빠져나오기 위해 정렬을 먼저 해주면 좋음
 */

int main() {
    int m, n, left = 1, right = 0; //조카수, 과자 길이, left, right 생성

    //입력
    cin >> m >> n; // 조카와 과자길이 받는다
    vector<int> snacks(n, 0); //과자 길이 벡터 생성
    for (int i = 0; i < n; i++) { // 과자개수동안
        cin >> snacks[i]; //과자 길이 받기
    }

    //연산
    sort(snacks.begin(), snacks.end()); // 차례대로 sort
    right = snacks[n - 1]; //오른쪽 값은 snack의 마지막 값

    //연산 & 출력
    cout << upperSearch(left, right, m, snacks); 
    return 0; // 프로그램 종료
}