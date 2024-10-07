#include <vector>
using namespace std;
#define MAX 210

bool visited[MAX];
int answer;
vector<int> graph[MAX]; // 인접리스트

// DFS를 사용하여 같은 네트워크에 있는 컴퓨터의 방문 여부를 true로 변환
void dfs(int now) {
    visited[now] = true;
    
    for(int i=0; i<graph[now].size(); ++i) {
        int next = graph[now][i];
        if(visited[next]) continue;
        dfs(next);
    }
}

int solution(int n, vector<vector<int>> computers) {
    // 인접리스트 초기화
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(!computers[i][j]) continue;
            if(i == j) continue;
            graph[i].push_back(j);
        }
    }
    
    for(int i=0; i<n; ++i) {
        // 새로운 네트워크를 발견하면
        // dfs를 통해 같은 네트워크에 있는 컴퓨터의 방문 여부를 true로 변환하고
        // 정답 count
        if(visited[i]) continue;
        dfs(i);
        ++answer;
    }
    
    return answer;
}
