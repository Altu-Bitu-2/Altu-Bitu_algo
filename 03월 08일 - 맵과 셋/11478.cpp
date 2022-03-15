#include <iostream>
#include <set> //IOSTREAM에 포함되지 않아서 따로 헤더파일 포함. 

using namespace std; //cin, cout와 같은 표준라이브러리의 함수 소속. 미리 정해두면 뒤에서 std::cout라고 명시하지 않아도 기본으로 std로 설정. 

//서로 다른 부분문자열을 구하는 함수 구현
int cntDiff(string s) {
    set<string> sub; // 중복없이 문자열 저장할 수 있는 set 클래스 객체 선언. 
    for (int i = 0; i < s.length(); i++) { //for loop동안 가능한 문자열 갯수 구하기. i=0, j=0부터 해서 차례대로 문자열을 만든다.
        string temp = ""; //temporary string을 만듦. 다음 for loop동안 temp에 문자를 더하고, 셋에 넣어 중복 확인 
        for (int j = i; j < s.length(); j++) { //루프동안 
            temp += s[j]; //j=i부터 해서 각 문제를 temp에 더함. 
            sub.insert(temp); //삽입을 통해서 해당 문자열이 셋에 있으면 중복으로 추가 안되고 새 문자열이면 추가
        }
    }
    return sub.size(); // 만들어진 문자열의 갯수 반환
}

/**
 * 중복을 제거해서 저장해주는 컨테이너인 set을 활용해서 풀이 가능
 * 삽입만 하므로 트리 구조 셋(set)이나 해시 구조 셋(unordered_set) 중 무엇을 쓰든 크게 상관 x
 */

int main() {
	//메인에서는 input, output만 담당. 이외의 실제 연산은 함수에서. 
    string s; // string s선언. 

    //입력
    cin >> s; //s에 사용자 입력 넣음 
    //연산 & 출력
    cout << cntDiff(s); //cntDiff 함수 리턴값 출력
    return 0; // main 함수 끝내기
}