#include <vector>
#include <queue>
using namespace std;

queue<pair<int, int>> q; // {index, priority}
priority_queue<int> pq; // 작업의 우선순위를 기준으로 정렬
int answer;

int solution(vector<int> priorities, int location) {
    for(int i=0; i<priorities.size(); ++i) {
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    
    while(true) {
        pair<int, int> current = q.front();
        
        // 우선순위가 가장 높은 작업이 할당된 경우
        if(current.second == pq.top()) {
            // 작업 실행 순서를 count
            ++answer;
            
            // 구하고자 하는 작업일 경우
            if(current.first == location) {
                break;
            }
            
            // 구하고자 하는 작업이 아닐 경우
            else {
                // 해당 작업 수행 (p와 pq를 pop)
                q.pop();
                pq.pop();
            }
            
        }
        
        // 우선순위가 가장 높은 작업이 할당되지 않은 경우
        else {
            // queue 맨 뒤로 보낸다 (핵심!!)
            q.pop();
            q.push(current);
        }
    }
    
    return answer;
}

// https://resilient-aura-65d.notion.site/a4c5f0aa6a074872949975ede555fefe?pvs=4
