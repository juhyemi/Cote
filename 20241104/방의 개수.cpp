#include <string>
#include <vector>
#include <map>
using namespace std;

int answer;
map<pair<int, int>, bool> visited_node; // 방문 노드 표시
map<pair<pair<int, int>, pair<int, int>>, bool> visited_edge; // 방문 간선 표시
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int x, y; // 현재 위치

int solution(vector<int> arrows) {
    visited_node[{y, x}] = true;
    
    for(int i=0; i<arrows.size(); ++i) {
        int dir = arrows[i];
        
        // 한 방향에 대해 두 번씩 이동해야 모래시계 모양의 예외 Case를 처리할 수 있다
        for(int j=0; j<2; ++j) {
            // 다음 위치
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            // 핵심! 다음 두 가지 조건을 만족하면 방의 갯수 count
            // 1. 중복 방문한 노드
            // 2. 처음 방문한 간선
            if(visited_node[{ny, nx}] && !visited_edge[{{y, x}, {ny, nx}}]) {
                answer++;
            }
            
            // 방문 표시
            visited_node[{ny, nx}] = true;
            visited_edge[{{y, x}, {ny, nx}}] = true;
            visited_edge[{{ny, nx}, {y, x}}] = true;
            
            // 현재 위치 갱신
            x = nx;
            y = ny;
        }
    }
    return answer;
}
