#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll INF = 3 * 1e9 + 1;

ll min_diff = INF;

//다른 위치에서 시작하여 서로를 향해 가까워지는 투 포인터
pair<ll, ll> liquid(vector<ll> &arr, ll fixed, int left, int right) {
    pair<ll, ll> ans; //ans 페어 생성
    ans = make_pair(INF, INF); // inf, inf 페어 생성

    while (left < right) { // 왼쪽이 더 작을 동안
        ll mix = fixed + arr[left] + arr[right]; // 믹스되는 값은 왼+오+ 픽스된 값
        if (mix == 0) { // 멕스가 0이라면
            return make_pair(arr[left], arr[right]); // 해당 튜플 리턴
        }
        if (abs(mix) < min_diff) {// mix 절대값이 최소한의 차이보다 작으면
            min_diff = abs(mix); //min diff 를 mix 절대값으로 변경
            ans = make_pair(arr[left], arr[right]); // ans pair 변경
        }
        if (mix > 0) { // 믹스가 0보다 크면
            right--; // 오른쪽 값 왼쪽으로
        } else { //0보다 작으면 
            left++;//왼쪽 값을 오른쪽으로 
        }
    }
    return ans; //결과값 페어 리턴
}

/**
 * 2470번 : 두 용액 섞기
 * 2473번 : 세 용액 섞기
 *
 * [세 용액]
 *
 * 1. 하나의 용액을 반드시 사용한다고 가정
 * 2. 용액 하나 고정
 * 3. 해당 용액 이후의 범위에 대해 투 포인터 알고리즘 적용
 *
 * pair : 2개의 값 저장
 * tuple : 3개의 값 저장
 *
 * !주의! 세 용액의 최댓값은 1e9(=10억)이기 때문에 3개를 섞은 최댓값은 30억이고, int를 넘어감!
 */
int main() {
    int n; // 변수 선언

    //입력
    cin >> n; //개수 입력
    vector<ll> arr(n, 0); //개수 벡터 생성
    for (int i = 0; i < n; i++) { //n번동안
        cin >> arr[i]; // 백터에 값 넣기
    }

    //연산
    sort(arr.begin(), arr.end()); //sort
    tuple<ll, ll, ll> ans; //ans 튜플 생성
    for (int i = 0; i < n - 2; i++) { //n-2번 동안
        pair<ll, ll> p = liquid(arr, arr[i], i + 1, n - 1); //arr[i] 용액은 고정
        if ((p.first != INF) && (p.second != INF)) { //최솟값이 갱신된 경우
            ans = make_tuple(arr[i], p.first, p.second); //값 찾기
        }
    }

    //출력
    cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans); 
    return 0; //프로그램 종료
}