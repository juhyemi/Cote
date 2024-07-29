#include <vector>
#include <queue>
using namespace std;

// 요청 시간이 작은 값이 우선순위를 갖는 priority_queue의 비교 함수
struct requestCmp {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.first > p2.first;
    }
};

// 소요 시간이 작은 값이 우선순위를 갖는 priority_queue의 비교 함수
struct workCmp {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;
    }
};

int ms, answer;
// 요청 대기, 작업 대기 priority_queue 선언, {요청 시간, 작업 시간}
priority_queue<pair<int, int>, vector<pair<int, int>>, requestCmp> request;
priority_queue<pair<int, int>, vector<pair<int, int>>, workCmp> work;

int solution(vector<vector<int>> jobs) {
    int jobCnt = jobs.size();
    
    // 요청 대기 queue에 요소 삽입
    for(const auto& job : jobs) request.push({job[0], job[1]});
    
    while(!request.empty() || !work.empty()) {
        // 작업이 남아있지만 아직 요청 시간이 되지 않아 작업 대기 queue가 비어있는 경우
        // 요청 시간으로 이동
        if(work.empty() && !request.empty() && ms < request.top().first) {
            ms = request.top().first;
        }
            
        // 요청이 들어온 모든 작업을 작업 대기 queue에 삽입
        while(!request.empty() && request.top().first <= ms) {
            work.push(request.top());
            request.pop();
        }
    
        // 가장 높은 우선순위의 대기 중인 작업을 완료하고
        // 요청부터 종료까지 걸린 시간을 기록
        ms += work.top().second;
        answer += ms - work.top().first;
        work.pop();
    }
    
    return answer / jobCnt;
}

// 01:58:36
// https://resilient-aura-65d.notion.site/801b6c82f40846acb448a923e9f8f7b2?pvs=4
