#include <iostream>
#include <vector>

using namespace std;

//부분 행렬 원소 뒤집는 함수
void reverseMtx(int row, int col, vector<string> &matrix_a) {
    for (int i = row; i < row + 3; i++) { //row부터 +3까지
        for (int j = col; j < col + 3; j++) { //col부터 +2까지
            if (matrix_a[i][j] == '1') { //값을 뒤집기
                matrix_a[i][j] = '0';
            }
            else {
                matrix_a[i][j] = '1';
            }
        }
    }
}

//마지막으로 A == B인지 확인하는 함수
int isPossible(int n, int m, vector<string> &matrix_a, vector<string> &matrix_b) {
    for (int i = 0; i < n; i++) { //0부터 n번째행까지
        for (int j = 0; j < m; j++) { //각 행에서 m번째 열까지
            if (matrix_a[i][j] != matrix_b[i][j]) { //같은지 확인
                return false;
            }
        }
    }
    return true;//같다면 true 리턴
}

/**
 * [행렬]
 *
 * (0, 0) 인덱스부터 부분행렬을 만들 수 있는 마지막 인덱스까지 검사하며 그리디하게 푸는 문제
 * A, B 행렬의 현재 인덱스 값이 서로 다르다면 A 행렬에서 현재 인덱스로 '시작'하는 3x3 크기만큼의 부분 행렬 원소 뒤집기
 * 검사가 모두 끝난 후, A와 B가 서로 다르다면 바꿀 수 없는 경우임
 * !주의! 입력이 공백없이 주어지므로 string으로 받음
 */

int main() {
    int n, m;

    //입력
    cin >> n >> m;
    vector<string> matrix_a(n); //행렬a 백터
    vector<string> matrix_b(n); //행렬b 벡터
    for (int i = 0; i < n; i++) {
        cin >> matrix_a[i]; // n번동안 a벡터 받기. 공백없이 한 줄로받기때문에 string을 받음
    }

    for (int i = 0; i < n; i++) {
        cin >> matrix_b[i]; //b 벡터 받기
    }

    //연산
    int ans = 0;
    for (int i = 0; i <= n - 3; i++) { //3*3행렬의 원소를 바꿀 것
        for (int j = 0; j <= m - 3; j++) {
            if (matrix_a[i][j] != matrix_b[i][j]) { //(i, j)원소가 서로 다르다면
                reverseMtx(i, j, matrix_a); // a 행렬의 i,j부터 3*3행렬을 바꿈 
                ans++;
            }
        }
    }

    //출력
    if (!isPossible(n, m, matrix_a, matrix_b)) { // 만약에 끝까지 바꿨음에도 동일하지 않을 경우
        ans = -1; //-1출력
    }
    cout << ans; //바꾸는 연산 값 출력
    return 0;
}