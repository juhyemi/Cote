#include <string>
#include <vector>
#include <climits>
using namespace std;
#define MAX 105

int myCosts[MAX][MAX];
bool visit[MAX]; // 방문 노드
int answer;
int minCost;
int toVisitNode; // 방문 노드에 포함할 노드

int solution(int n, vector<vector<int>> costs) {
    for(int i=0; i<costs.size(); ++i) {
        myCosts[costs[i][0]][costs[i][1]] = costs[i][2];
        myCosts[costs[i][1]][costs[i][0]] = costs[i][2];
    }
    
    // 탐색의 시작 노드는 0
    visit[0] = true;
    
    // n-1개의 다리를 연결
    for(int cnt=0; cnt<n-1; ++cnt) {
        minCost = INT_MAX;
        
        for(int i=0; i<n; ++i) {
            // 방문 노드 선택
            if(!visit[i]) continue;
            
            // cf. 시작 노드가 0이므로 0은 제외
            for(int k=1; k<n; k++) {
                // 아직 방문 노드에 포함되지 않은 노드 중 최소 비용으로 갈 수 있는 노드를 선택
                
                if(visit[k]) continue; // 아직 방문 노드에 포함되지 않음
                if(myCosts[i][k] == 0) continue; // 노드로 이어진 다리가 존재
                if(minCost <= myCosts[i][k]) continue; // 최소 비용
                
                minCost = myCosts[i][k];
                toVisitNode = k;
            }
        }
        
        // 방문 노드에 포함하고 최소 비용 갱신
        visit[toVisitNode] = true;
        answer += minCost;
    }
    
    return answer;
}

// https://codingjj.tistory.com/96
// https://resilient-aura-65d.notion.site/670702b7efae46c4b0f63d3fcc78fecd?pvs=4
