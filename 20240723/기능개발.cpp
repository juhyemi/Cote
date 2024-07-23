#include <vector>
#include <queue>
using namespace std;

queue<int> q;
vector<int> answer;
int day;
int compelete; // 해당 날짜에 완료한 작업의 개수

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    // 각 작업에 대해 완료까지 남은 일수를 queue에 저장
    for(int i=0; i<progresses.size(); ++i) {
        int remainDay = (100 - progresses[i]) % speeds[i] ? (100 - progresses[i]) / speeds[i] + 1 : (100 - progresses[i]) / speeds[i];
        q.push(remainDay);
    }
    
    while(!q.empty()) {
        int now = q.front(); q.pop();
        
        // 현재 날짜에
        // 기능 개발이 완료되지 않았을 때
        if(now > day) {
            if(day) answer.push_back(compelete); // cf. 0번째 날에는 추가하지 않는다
            day = now;
            compelete = 1;
        }
        
        // 기능 개발이 완료됐을 때
        else {
            ++compelete;
        }
    }
    
    // 마지막 날짜에 완료한 작업의 개수 저장
    answer.push_back(compelete);
    
    return answer;
}

// https://resilient-aura-65d.notion.site/eb0709463ef84ca7b79ddd6e6cdf272e?pvs=4
