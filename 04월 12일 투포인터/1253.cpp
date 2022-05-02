#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//좋은 수인지 검사하는 함수(투 포인터)
bool isGood(vector<int> &num, int left, int right, int idx) {
    while (left < right) { // 오른쪽이 더 높을 동안
        if (left == idx) { //인덱스값이랑 같으면 
            left++; //오른쪽으로
            continue; //다음 루프
        }
        if (right == idx) { //인덱스와 right이 같으면
            right--; //왼쪽으로
            continue;
        }

        if (num[left] + num[right] == num[idx]) { //왼쪽 + 오른쪽 = 인덱스값이면
            return true; // true 리턴
        }
        if (num[left] + num[right] > num[idx]) { // 더 크다면
            right--; //right를 왼쪽으로 이동
        } else {
            left++; // 더 작다면 left를 오른쪽으로 이동
        }
    }
    return false; //while loop를 벗어나면 fals 리턴
}

/**
 * [좋다]
 *
 * 1. 각 수마다 양 쪽 끝에서 포인터를 시작해서 좁혀오면서 어떤 '다른 두 수'가 현재 수를 만들 수 있는지 검사
 * 2. 포인터를 차례로 옮기며 검사하기 위해 미리 수를 오름차순 정렬함
 * 3. 현재 만드려는 수의 위치와 left, right 포인터 위치가 겹칠 경우 처리 주의
 */

int main() {
    int n, ans = 0; // 변수 초기화

    //입력
    cin >> n; // 개수 입력
    vector<int> num(n, 0); // n백터 생성
    for (int i = 0; i < n; i++) { // n번동안 입력
        cin >> num[i]; // 벡터에 입력
    }

    //연산
    sort(num.begin(), num.end()); //sort
    for (int i = 0; i < n; i++) { //n번동안
        if (isGood(num, 0, n - 1, i)) { //isgood 확인 후 true이면
            ans++; //결과값에 추가
        }
    }

    //출력
    cout << ans;
    return 0; // 프로그램 종료