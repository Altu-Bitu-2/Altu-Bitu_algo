#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

void greenToRed(int n, vector<vector<char>> &board) { //적록색약
    for (int i = 0; i < n; i++) { //n*n번동안
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'G') { //녹색인 부분을 
                board[i][j] = 'R'; //모두 붉은색으로 변경
            }
        }
    }
}

void bfs(int n, int r, int c, vector<vector<bool>> &visited, vector<vector<char>> &board) {
    //상, 하, 좌, 우
    int dr[4] = {-1, 1, 0, 0}; //상하
    int dc[4] = {0, 0, -1, 1}; //좌우

    queue<ci> q; // 큐 생성

    //큐 초기화
    q.push({r, c});
    visited[r][c] = true; //해당 위치 방문
    while (!q.empty()) { //큐가 비어있지 않다면 
        int cr = q.front().first; // r값
        int cc = q.front().second; //c값
        q.pop(); //해당 조합을 pop

        for (int i = 0; i < 4; i++) { //상하좌우 4번동안
            int nr = cr + dr[i]; //상하
            int nc = cc + dc[i]; //좌우
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc]) { //해당범위에 있다면
                continue; //다음 루프
            }
            if (board[nr][nc] != board[cr][cc]) { //[nr][nc]와 값이 다르면
                continue; //다음 루프
            }
            q.push({nr, nc}); // 해당 위치는 값이 같고, 범위에 있으니까 push
            visited[nr][nc] = true; //방문 확인
        }
    }
}

int countArea(int n, vector<vector<char>> &board) {
    vector<vector<bool>> visited(n, vector<bool>(n, false)); // 움직였는지 확인하는 벡터
    int area = 0; //결과값

    for (int i = 0; i < n; i++) { //n*n 보드동안
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) { //해당 위치를 방문했으면 pass
                continue;
            }
            bfs(n, i, j, visited, board); //BFS
            area++; //결과값 추가
        } 
    }
    return area; // 결과값 반환
}

/**
 * [적록색약]
 *
 * 그림의 색을 기준으로 구역을 나누는 문제
 * 1. 적록색약이 아닌 사람 기준으로 구역을 나눈다.
 * 2. 그림의 초록을 모두 빨강으로 바꾼 후, 적록색약인 사람 기준으로 구역을 나눈다.
 */

int main() {
    int n; // 입력값 선언
    string s; //입력값 선언

    //입력
    cin >> n; // n 입력
    vector<vector<char>> board(n, vector<char>(n, ' ')); // n*n보드 생성
    for (int i = 0; i < n; i++) { //n번동안
        cin >> s; //보드 문자열 받기
        for (int j = 0; j < n; j++) { // 보드 문자열 개수동안
            board[i][j] = s[j]; //문자열 보드에 넣기
        }
    }

    //연산 & 출력
    cout << countArea(n, board) << ' '; // 결과값 출력
    greenToRed(n, board); //적녹생약
    cout << countArea(n, board); // 결과값 출력
    return 0; //프로그램 종료
}