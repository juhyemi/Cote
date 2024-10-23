#include <queue>
#include <vector>
using namespace std;
#define MAX 20010

int maxDepth, answer;
vector<int> graph[MAX];
queue<pair<int, int>> q;
bool visited[MAX];

int solution(int n, vector<vector<int>> edge) {
    for(int i=0; i<edge.size(); ++i) {
        int u = edge[i][0];
        int v = edge[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    q.push({1, 0});
    visited[1] = true;
    while(!q.empty()) {
        int now = q.front().first;
        int depth = q.front().second;
        q.pop();
        
        if(maxDepth < depth) {
            maxDepth = depth;
            answer = 1;
        }
        
        else if(maxDepth == depth) {
            ++answer;
        }
        
        for(int i=0; i<graph[now].size(); ++i) {
            int next = graph[now][i];
            
            if(visited[next]) continue;
            q.push({next, depth + 1});
            visited[next] = true;
        }
    }
    
    return answer;
}
