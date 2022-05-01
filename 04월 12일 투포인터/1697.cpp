#include <iostream>
#include <queue>

using namespace std;
const int SIZE = 1e5;

int bfs(int n, int k) {
    vector<int> check(SIZE + 1, 0); //백터 생성
    queue<int> q; //큐에 좌표값 저장
    int ans = 0;

    check[n] = 1; //시작 노드 방문체크 + 시간 초기화
    q.push(n); // 해당 좌펴 값 큐에 추가
    while (!q.empty()) { // 큐가 비지 않았을 동안 
        int x = q.front(); //첫 값이 x
        q.pop(); //x 큐에서 제외

        if (x == k) { //k값이라면 
            ans = check[x] - 1;  //이전 까지 가능 
            break; //while 탈출
        }

        vector<int> child = {x - 1, x + 1, x * 2}; //자식 노드
        for (int i = 0; i < 3; i++) { //3번동안
            if (child[i] >= 0 && child[i] <= SIZE && !check[child[i]]) { // 해당 범위라면
                check[child[i]] = check[x] + 1; //이전값+1 해서 넣어준다
                q.push(child[i]); // 좌표 값 추가
            }
        }
    }
    return ans; // 결과값 반환
}

/**
 * [숨바꼭질]
 *
 * x좌표 위에서 x-1, x+1, 2*x의 위치로 계속 이동하며 탐색
 * 가장 빠른 시간을 찾아야 하므로 주변 노드부터 탐색하는 풀이로 풀어서 k에 도달하면 바로 탐색 종료 (bfs)
 */

int main() {
    int n, k; //입력값 초기화

    //입력
    cin >> n >> k;

    //연산 & 출력
    cout << bfs(n, k);
    return 0; // 프로그램 종료
}