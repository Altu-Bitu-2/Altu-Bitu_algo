#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll cntTree(int height, vector<int> &tree) {
    ll sum = 0; //int범위를 넘어가므로 longlong으로 선언
    for (int i = 0; i < tree.size(); i++) { //트리 개수만큼
        if (height >= tree[i]) { //높이가 해당 인덱스 트리보다 높으면
            return sum; // sum을 그대로 리턴
        }
        sum += (tree[i] - height); //아니라면 sum에 차이만큼 더한다
    }
    return sum; // sum리턴
}

int upperSearch(int left, int right, int target, vector<int> &tree) { //높이의 최대값 찾기 이분탐색 활용
    while (left <= right) { // 오른쪽 값이 더 큰 동안 탐색. 
        int mid = (left + right) / 2; // 중앙값 계산
        ll tree_cnt = cntTree(mid, tree); // cntTree로 트리 세기. 

        if (tree_cnt >= target) { //자르고자 하는 값보다 cntTree가 더 크면
            left = mid + 1; // 왼쪽값이 mid+1이 되고
        } else {
            right = mid - 1; // 아니면 오른쪽 값이 mid+1
        }
    }
    return left - 1; // 같거나 클때 whileloop이 끝나므로 -1인 값을 리턴
}

/**
 * [나무 자르기]
 *
 * 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값은?
 * -> 절단기의 높이가 k(임의의 값)일 때, M미터의 나무를 집에 가져갈 수 있는가?
 *
 * left: 절단기의 최소 높이 -> 0
 * right: 절단기의 최대 높이 -> 주어진 나무 중 가장 높은 나무 높이
 *
 * !주의! int 자료형 범위를 넘어가므로 long long써야 함
 */

int main() {
    int n, m; // 입력 변수 생성

    //입력
    cin >> n >> m; //나무의 수, 상근이가 집으로 가져가는 나무 길이
    vector<int> tree(n, 0); // 나무 수 만큼의 백터 생성
    for (int i = 0; i < n; i++) { // 나무 수 만큼
        cin >> tree[i]; // 나무 입력
    }

    sort(tree.begin(), tree.end(), greater<>()); //나무 순서대로 sort

    //연산 & 출력
    cout << upperSearch(0, tree[0], m, tree); //연산 및 출력
    return 0; //종료
}