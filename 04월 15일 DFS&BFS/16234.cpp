#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

vector<vector<int>> board, visited; //
queue<ci> countries;


//각 연합의 인구 수만큼 인구 이동하는 함수
void movePeople(int population, vector<ci> &union_cord) {
    for (int i = 0; i < union_cord.size(); i++) { //연합 이동 인구수 만큼
        int row = union_cord[i].first, col = union_cord[i].second; //row, col init
        board[row][col] = population; // 해당 명수가 곧 인구수
        countries.push({row, col}); //인구 이동이 있는 나라는 다음에도 인구 이동 가능성 있음
    }
}

bool bfs(int n, int l, int r, int cr, int cc, int day) {
    //상, 하, 좌, 우
    int dr[4] = {-1, 1, 0, 0}; //위아래
    int dc[4] = {0, 0, -1, 1}; //좌우

    vector<ci> union_cord; //연합 저장할 벡터
    union_cord.push_back({cr, cc}); //백터에 연합 푸시
    queue<ci> q; // 상하, 좌우 페어 큐 생성
    q.push({cr, cc}); // 상하, 좌우 페어 큐에 입력
    int sum = board[cr][cc], cnt = 1; // sum, board[][], cnt 생성
    while (!q.empty()) { //큐가 비어있지 않으면 
        cr = q.front().first; //큐 값의 첫 번째
        cc = q.front().second; // 큐값의 두번째
        q.pop(); //해당 값은 pop

        for (int i = 0; i < 4; i++) { //상하좌우 4번동안
            int nr = cr + dr[i]; //위아래값 추가
            int nc = cc + dc[i]; //좌우값 추가
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] == day) { //해당경우는 국경선이 열리지 않았으므로 다음 루프로 이동
                continue;
            }
            int diff = abs(board[nr][nc] - board[cr][cc]); //차이 확인
            if (diff >= l && diff <= r) { //국경선 열림
                q.push({nr, nc}); //큐에 해당 값 추가
                visited[nr][nc] = day; // 움직였던 날 입력
                union_cord.push_back({nr, nc}); //연합에 추가
                sum += board[nr][nc]; // 합 계산
                cnt++; //이동 수 더하기
            }
        }
    }
    if (cnt > 1) { //연합이 생겼다면
        movePeople(sum / cnt, union_cord); //인구 이동
        return true;
    }
    return false;
}

int simulation(int n, int l, int r) {
    int day = 0; //방문 체크로도 사용
    while (true) { //참인 동안 루프
        day++; // 하루가 늘어날 때 마다
        bool is_move = false; //인구 이동 했는지 체크
        int size = countries.size(); //이번 시간에 탐색할 수 있는 나라의 수
        while (size--) { //탐색 가능 나라 수 만큼 루프
            int row = countries.front().first; //나라의 row 받아옴
            int col = countries.front().second; // 나라의 col 받아옴
            countries.pop(); //countries 큐에서 삭제
            if (visited[row][col] == day) { //이미 탐색한 나라라면
                continue; //다음 루프
            }
            visited[row][col] = day; //탐색 안했다면, 탐색 함 넣어줌
            if (bfs(n, l, r, row, col, day)) { //bfs
                is_move = true; //갈 수있다면 true값
            }
        }
        if (!is_move) { //못가면
            return day - 1; // 그 전날 까지로 갈 수 있으니까 그 값 리턴
        }
    }
}

/**
 * [인구 이동]
 *
 * 0. 인구이동이 일어날 수 있는 나라(처음에는 모든 나라)의 좌표를 좌표 큐에 저장
 * 1. bfs 탐색을 통해 연합을 확인하고, 연합에 포함된 나라의 인구이동을 진행한다.
 * 2. 인구 이동이 있었던 나라는 다음 날에도 인구이동이 시작될 수 있으므로 좌표 큐에 다시 넣어준다.
 *    -> 직전 이동이 있었던 나라에 대해서만 bfs 탐색 진행
 *    - 인구 이동이 일어나지 않은 두 나라 사이에서는 다음 날에도 인구이동이 일어날 수 없음
 * 3. 인구이동이 전혀 일어나지 않을 때까지 반복
 */

int main() {
    int n, l, r; //입력값 선언

    //입력
    cin >> n >> l >> r; //사용자 입력
    board.assign(n, vector<int>(n, 0)); //보드 생성
    visited.assign(n, vector<int>(n, 0)); // 방문 목록 생성
    for (int i = 0; i < n; i++) { //n*n번 동안
        for (int j = 0; j < n; j++) { // ㅜn*n번동안
            cin >> board[i][j]; //보드 입력
            countries.push({i, j}); // 나라 추가
        }
    }

    //연산 & 출력
    cout << simulation(n, l, r);
    return 0; // 프로그램 종료
}