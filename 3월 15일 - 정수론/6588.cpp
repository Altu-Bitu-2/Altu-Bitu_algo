#include <iostream>
#include <vector>

using namespace std;

// 1,000,000까지 검사하므로 해당하는 만큼의 수를 미리 생성 후 사용
const int SIZE = 1e6;

//에라토스테네스의 체, 미리 SIZE까지의 소수 판단
vector<bool> isPrime() {
    vector<bool> is_prime(SIZE + 1, true); //소수 판단 여부 저장
	// 1,000,000까지 판단. 편하게 사용하기 위헤 +1 값으로, index = number이 될 수 있도록 사용. 전부 true로 백터 생성 후 소수가 아니라면 false 입력.

    is_prime[0] = is_prime[1] = false; // 0과 1은 소수가 아님. 2부터 확인.
    for (int i = 2; i * i <= SIZE; i++) { //2부터 1,000,000까지 소수 검사
        if (!is_prime[i]) { //소수가 아니라면
            continue; //다음 숫자로 이동
        }
        //i가 소수라면 (is_prime 값이 true라면)
        for (int j = i * i; j <= SIZE; j += i) { //남은 숫자에서 소수를 모두 찾는다. i*(i-1)까지는 이전 for loop에서 모두 다뤘으므로 제곱부터 끝까지 찾는다.
            is_prime[j] = false; //i의 배수 제거
        }
    }
    return is_prime; //소수만 남은 벡터 리턴
}

//골드바흐의 추측 판단 함수
int checkGoldbach(int n, vector<bool> &is_prime) {
    for (int i = 3; i <= n / 2; i += 2) { //홀수만 검사, n/2 이상의 값은 어차피 n-i를 통해 검사되므로 n/2까지 검사
        if (is_prime[i] && is_prime[n - i]) { //두 홀수 모두 소수라면 (골드바흐의 추측이 맞은 경우)
            return i; //두 홀수 소수 중 작은 값 리턴
        }
    }
    return 0; //골드바흐의 추측이 틀린 경우
}

/**
 * "골드바흐의 추측"
 * 4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다. -> 이를 증명하는 문제
 * -> 에라토스테네스의 체를 활용하여 미리 SIZE 까지의 소수 판별
 * -> 두 홀수 소수의 합으로 나타낼 수 있는지 판단
 */

int main() {
    //입출력 속도 향상
    ios_base::sync_with_stdio(false); //iostream을 사용하기 때문에 c의 standard input output 사용 안함. 
    cin.tie(NULL); // cin의 버퍼 분리

    int n; // 받아오는 인풋 함수 생성
    vector<bool> is_prime = isPrime(); //소수 판단 여부 저장

    while (true) {
        //입력
        cin >> n;
        if (n == 0) // 0을 받아오면 while 문이끝나고, 프로그램 종료.
            break;

        //연산
        int prime = checkGoldbach(n, is_prime); //골드바흐의 추측이 맞는지 체크
        if (prime) //맞다면 -> 두 홀수 소수 중 작은 값 리턴받은 경우
            cout << n << " = " << prime << " + " << n - prime << '\n';
        else //틀리다면 -> 0 리턴받은 경우
            cout << "Goldbach's conjecture is wrong.\n";

    }

    return 0; // 프로그램 종료
}