#include <string>
#include <vector>
using namespace std;
#define MAX 110

int answer;
bool versus[MAX][MAX]; // versus[승자][패자] = true

int solution(int n, vector<vector<int>> results) {
    for(int i=0; i<results.size(); ++i) {
        versus[results[i][0] - 1][results[i][1] - 1] = true;
    }
    
    // 플로이드-와샬 알고리즘
    // a가 b를 이기고, b가 c를 이기면, a가 c를 이긴다
    // 시간복잡도: O(n^3)
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            for(int k=0; k<n; ++k) {
                if(versus[j][i] && versus[i][k]) versus[j][k] = true;
            }
        }
    }
    
    // 모든 선수들에 대해 순위를 매길 수 있는지 여부 확인
    // 임의의 선수의 경기 정보가 n-1개이면 순위를 매길 수 있다
    for(int i=0; i<n; ++i) {
        int cnt = 0;
        for(int j=0; j<n; ++j) {
            if(versus[i][j] || versus[j][i]) ++cnt;
        }
        
        if(cnt == n-1) ++answer;
    }
    
    return answer;
}
