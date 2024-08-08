#include <vector>
#define MAX 8
using namespace std;

int answer, cnt;
bool visited[MAX];

// 완전탐색 - 백트래킹
void dfs(int k, const vector<vector<int>>& dungeons) {
    // 현재까지 방문한 던전의 개수가 최대이면, 최대값(정답) 갱신
    if(answer < cnt) answer = cnt;
    
    // 모든 던전을 처음부터 살펴보며
    // 아직 방문하지 않았고, 최소 필요 피로도가 충분할 때
    // 해당 던전을 방문한 상태에서 재귀 호출
    for(int i=0; i<dungeons.size(); ++i) {
        if(visited[i]) continue;
        if(k < dungeons[i][0]) continue;
        
        visited[i] = true; ++cnt;
        dfs(k - dungeons[i][1], dungeons);
        visited[i] = false; --cnt;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(k, dungeons);
    return answer;
}

// https://resilient-aura-65d.notion.site/b970925ae45845529f7db43173d76571?pvs=4
