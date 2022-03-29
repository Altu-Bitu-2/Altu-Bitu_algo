#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//그라운드에 있는 카드를 덱으로 옮기는 함수
void moveCard(deque<int> &deck, deque<int> &ground) {
    while (!ground.empty()) { //그라운드가 비어있을때까지 겹친다.
        deck.push_back(ground.back()); // 덱 마지막에 그라운드 마지막에 있는 것 부터 겹친다. 
        ground.pop_back(); //뒤에서 부터 팝. 
    }
}

//게임을 진행하는 함수
pair<int, int> playGame(int m, vector<deque<int>> &deck, vector<deque<int>> &ground) {
    bool turn = false; //도도부터 시작

    while (m--) { //m번동안 게임을 진행한다. 
        //이번 턴의 사람이 카드 뒤집어서 그라운드에 올려놓기
        int card = deck[turn].front(); //이번 턴의 사람(도도부터 시작)의 덱 첫번째를 받기
        ground[turn].push_front(card); // 그라운드에 첫번째 카드를 앞에 넣기.
        deck[turn].pop_front(); // 덱에 있던 front를 없애기. 그라운드로 내놨기 때문에 없음. 

        if (deck[turn].empty()) { //덱에 더이상 카드가 없을 경우, 
            break; // 루프는 멈추고 바로 리턴한다. 
        }

        //이번에 종을 칠 사람
        int bell = -1;
        if (card == 5) { // 그라운드에 올라와있는 카드가 5이면 도도가 종을 친다.
            bell = 0; //도도 = 0
        }
		// 그라운드에 둘 다 카드가 있고,
		// 그라운드에 올라와있는 카드 값의 합이 5일 경우에 수연이가 종을 친다
        else if (!ground[0].empty() && !ground[1].empty() && (card + ground[!turn].front() == 5)) {
            bell = 1; //수연 = 1
        }

        if (bell != -1) { //종을 둘 중 한명이 칠 경우
            moveCard(deck[bell], ground[!bell]); // 상대방의 그라운드에 있는 카드를 자신의 덱에 합친다
            moveCard(deck[bell], ground[bell]); // 자신의 그라운드의 카드를 자신의 덱에 합친다.
        }
        turn = !turn; //차례 바꾸기
    }
    return make_pair(deck[0].size(), deck[1].size()); // 각 덱의 개수를 페어로 반환. <도도, 수연> 순서
}

/**
 * [숫자 할리갈리 게임] - 시뮬레이션 문제
 * - 카드 덱과 그라운드의 카드를 관리하기 위해 덱 사용
 *
 * 1. 차례가 되면, 상단 카드를 그라운드에 놓는다.
 * 2. 누군가의 카드 덱이 비는 즉시 게임 종료
 * 3. 종을 치면, 상대방의 그라운드 카드를 뒤집어서 카드 더미의 밑에 넣는다.
 */

int main() {
    int n, m, num1, num2;
    vector<deque<int>> deck(2), ground(2);

    cin >> n >> m; //n: 도도와 수연이가 가지는 덱의 개수, m: 게임 진행 회수
    while (n--) { // n번 동안 도도와 수연이가 가진 덱에 적힌 수. 맨 아래부터 받아서 맨 위의 수까지 받는다. 
        cin >> num1 >> num2;
        deck[0].push_front(num1); //deck 0번이 도도의 덱
        deck[1].push_front(num2); //deck 1번이 수연의 덱
    }

    pair<int, int> result = playGame(m, deck, ground); // m번동안의 게임 결과값을 받아 저장한다. first: 도도, second: 수연


	//이긴 사람 출력. 덱의 수가 많은 사람이 승리. 
    if (result.first == result.second) { //덱의 개수가 같을 경우
        cout << "dosu\n"; // 비김
    }
    else if (result.first > result.second) { // 도도의 덱의 개수가 많을 경우
        cout << "do\n"; //도도 승리 
    }
    else if (result.first < result.second) { // 수연의 덱의 개수가 많을 경우
        cout << "su\n"; //수연 승리
    }
    return 0;
}