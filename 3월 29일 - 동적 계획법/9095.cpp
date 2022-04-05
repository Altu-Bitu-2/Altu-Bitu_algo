#include <iostream>
#include <vector>

using namespace std;
const int MAX = 10; // 정수 n은 양수이며 11보다 작은 값이기 때문에 max값을 미리 설정한다. 

vector<int> dp(MAX + 1); //dp에 사용되는 vector을 max+1로 사이즈를 설정한다. 

//top-down 방식 dp 채우기
int numberOfCasesTop(int n) {
    if (n < 0) { // n이 0보다 작을 경우 0을 리턴한다. recursive하게 사용하므로, 마지막에 n-1<0이 될 경우를 확인한다. 
        return 0;
    }
    if (n == 0) { // n이 0일 경우 1을 리턴한다. top down 방식으로 값을 더했을 때 맞는 경우의 수가 생긴 것이므로 카운트를 늘린다.
        return 1;
    }
    if (dp[n]) { //dp[n]이 존재한다면 해당 값을 리턴하면 된다. 존재하지 않는다면, 아래 for loop로 구한다. 
        return dp[n];
    }
    for (int i = 1; i <= 3; i++) { //1, 2, 3의 합으로 주어지므로 d[10] = d[7]+3 +d[8]+2 + d[9]+1 로 주어진다. 3가지 경우 모두 사용한다. 
        dp[n] += numberOfCasesTop(n - i); // recursive하게 함수를 사용한다. 
    }
    return dp[n]; //모든 recursion을 마치면, dp[n]을 반환한다. 
}

/**
 * [top-down 접근]
 * n부터 시작해서 -1, -2, -3한 수의 경우의 수 먼저 구함
 * 0미만일 경우 합으로 나타낼 수 없는 경우이므로 0 리턴
 * 이미 dp[n] 값이 있을 경우, 바로 리턴
 */

int main() {
    int t, n; //받을 t와 n을 선언

    //입력
    cin >> t; // 테스트 개수를 받는다
    while (t--) { //테스트 개수 동안 정수를 받고, 방법의 수를 출력한다
        cin >> n; // 정수 n을 받는다

        //연산 & 출력
        cout << numberOfCasesTop(n) << '\n'; 
    }
    return 0; // 프로그램 종료
}