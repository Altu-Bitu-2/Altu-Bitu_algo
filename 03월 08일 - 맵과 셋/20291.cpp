#include <iostream>
#include <map>  //iostream에 불포함되어서 따로 헤더 불러옴. 
#include <string> //iostram에 내장되어있기도 함.

using namespace std;//해당 파일에서 이름공간은 따로지정하지 않으면 std. 

/**
 * 중복없이 정렬이 필요한 경우
 * key(확장자)-value(파일 개수) 쌍이 필요하므로 map 사용
 */

int main() {
    int n; // 바탕화면에 있는 파일 개수 선언
    string input; //파일명 변수 선언
    map<string, int> extension; //string: key, 확장자를 뜻. int: 파일 개수 value

    //입력 & 연산
    cin >> n; //파일 개수 입력
    while (n--) { // 입력될때마다 개수 -1. 0이 될때까지, 즉 n번 whileloop를 돌린다.
        cin >> input; //파일명 입력
        //string.substr(pos, len): 첫 번째 문자의 위치(pos)부터 pos + len 까지의 부분 문자열
        //pos + len 이 문자열보다 길다면 문자열 마지막 문자까지만 리턴하도록 처리
        string ext = input.substr(input.find('.') + 1, input.length()); //input string에서 .을 찾은 후, 그 뒤부터  끝까지를 ext에 추가.
        extension[ext]++; // 확장자를 map에서 찾고, value인 개수 추가
    }
	// 확장자 이름 사전순 출력
    for (auto iter = extension.begin(); iter != extension.end(); iter++) {// iter 사용해서 자동으로 반복자 선언과 동시에 순회. 
        cout << iter->first << ' ' << iter->second << '\n'; // 차례대로 출력
    }
    return 0; //main 종료
}