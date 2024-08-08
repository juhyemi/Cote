#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#define MAX 110
using namespace std;

vector<int> graph[MAX]; // 그래프(인접 리스트)
queue<int> q;
bool visited[MAX];
int answer = 100;

void reset() {
    memset(visited, false, sizeof(visited));
}

// cut 전선이 잘렸을 때 → n 송전탑이 속한 전력망의 송전탑의 개수 반환
int getConnectedCnt(int n, vector<int> cut) {
    int cnt = 0;
    
    // bfs
    q.push(n);
    visited[n] = true;
    ++cnt;
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for(int i=0; i<graph[now].size(); ++i) {
            int next = graph[now][i];
            if(visited[next]) continue;
            // 잘린 전선일 경우
            if((now == cut[0] && next == cut[1]) || (now == cut[1] && next == cut[0])) continue;
            q.push(next);
            visited[next] = true;
            ++cnt;
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    // 그래프(인접 리스트) 생성
    for(const auto& wire : wires) {
        graph[wire[0]].push_back(wire[1]);
        graph[wire[1]].push_back(wire[0]);
    }
    
    // 각 전선을 잘라가며 확인
    for(const auto& cut : wires) {
        int diff = abs(n - 2 * getConnectedCnt(1, cut)); // 두 전력망이 가지고 있는 송전탑 개수의 차이
        if(diff < answer) answer = diff;
        reset();
    }
    
    return answer;
}

// 45:18
