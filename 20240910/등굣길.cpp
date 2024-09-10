#include <vector>
using namespace std;
#define MAX 110
#define MOD 1000000007

int answer;
int dp[MAX][MAX];
bool isWater[MAX][MAX];

int solution(int m, int n, vector<vector<int>> puddles) {
    for(int i=0; i<puddles.size(); ++i) {
        isWater[puddles[i][1]][puddles[i][0]] = true;
    }
    
    dp[1][1] = 1;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(isWater[i][j]) continue;
            if(i == 1 && j == 1) continue; // dp[1][1] = 1
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
    
    return dp[n][m];
}
