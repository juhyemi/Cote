#include <vector>
#include <queue>
using namespace std;

int t;
queue<int> waiting;
queue<pair<int, int>> crossing; // {다리에 입장한 시간, 무게}
int total_weight; // 다리를 건너고 있는 트럭의 무게 합

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    for(const auto& tw : truck_weights) {
        waiting.push(tw);
    }
    
    while(true) {
        ++t;
        
        // 다리의 맨 앞의 트럭이 다리를 건넜는지
        if(!crossing.empty() && t - crossing.front().first == bridge_length) {
            total_weight -= crossing.front().second;
            crossing.pop();
        }
        
        // 대기 중인 트럭 중 다리에 오를 수 있는 트럭이 있는지
        if(!waiting.empty() && crossing.size() + 1 <= bridge_length && waiting.front() + total_weight <= weight) {
            crossing.push({t, waiting.front()});
            total_weight += waiting.front();
            waiting.pop();
        }
        
        // 대기 중인 마지막 트럭이 다리에 올랐을 때
        // 정답(시간)을 바로 계산하고 반복문 종료
        if(waiting.empty()) {
            t += bridge_length;
            break;
        }
    }
    
    return t;
}

// https://resilient-aura-65d.notion.site/83760dbc2e014227adedde0a1a71403d?pvs=4
