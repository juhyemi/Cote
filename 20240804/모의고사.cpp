#include <vector>
using namespace std;

int a[5] = {1, 2, 3, 4, 5};
int b[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int c[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
int cnt[3];
int maxCnt;
vector<int> answer;

vector<int> solution(vector<int> answers) {
    // 정답 배열을 순회하며
    // 해당 문제를 맞춘 수포자의 cnt를 증가
    for(int i=0; i<answers.size(); ++i) {
        if(a[i%5] == answers[i]) ++cnt[0];
        if(b[i%8] == answers[i]) ++cnt[1];
        if(c[i%10] == answers[i]) ++cnt[2];
    }
    
    // 수포자의 정답 개수를 순회하며
    // 현재까지 확인한 최대 개수보다 크거나 같으면 배열에 추가
    // 클 경우 배열에 추가하기 이전에 최대 개수를 갱신하고 배열 초기화 진행
    for(int i=0; i<3; ++i) {
        if(maxCnt > cnt[i]) continue;
        if(maxCnt < cnt[i]) {
            maxCnt = cnt[i];
            answer.clear();
        }
        answer.push_back(i+1);
    }
    
    return answer;
}

// 14:31
// https://resilient-aura-65d.notion.site/8eaf043fca954d37923cf1bb88d0d72d?pvs=4
