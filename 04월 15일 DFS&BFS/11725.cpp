#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj_list;
vector<int> parent;

void dfs_recursion(int prev, int curr) {
    if (parent[curr]) { //부모가 존재하면 
        return; // 그 위치에서 리턴
    }
    parent[curr] = prev; //이전값이 parent
    for (int i = 0; i < adj_list[curr].size(); i++) { //list 사이즈동안 루프
        dfs_recursion(curr, adj_list[curr][i]); //dfs 재귀
    }
}

/**
 * [트리의 부모 찾기]
 *
 * 1번 노드에서 출발해서 탐색
 * 루트 노드에서 출발 했기 때문에, 현재 노드의 부모는 이전 노드가 된다.
 */

int main() {
    int n, a, b; //입력값 초기화

    //입력
    cin >> n; //n 입력
    adj_list.assign(n + 1, vector<int>(0)); // n+1개의 리스트 생성
    parent.assign(n + 1, 0); //부모 생성
    for (int i = 1; i < n; i++) { // n번동안
        cin >> a >> b; //입력
        adj_list[a].push_back(b);//list에 추가
        adj_list[b].push_back(a); //list에 추가
    }

    //연산
    dfs_recursion(1, 1); //1번 노드는 루트노드이므로, 부모를 자기 자신으로 설정

    //출력
    for (int i = 2; i <= n; i++) {
        cout << parent[i] << '\n'; //출력
    }
    return 0; //프로그램 종료
}