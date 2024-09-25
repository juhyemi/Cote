#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 1000010

int answer;
int dp[2][MAX]; // dp[0][i]: 첫 번째 집을 선택하지 않은 경우, dp[1][i]: 첫 번째 집을 선택한 경우
int homeCnt;

int solution(vector<int> money) {
    homeCnt = money.size();
    
    // 1. 첫 번째 집을 선택한 경우
    // 두 번째 집과 마지막 집을 선택할 수 없다
    dp[1][0] = money[0];
    dp[1][1] = dp[1][0]; // 두 번째 집
    for(int i=2; i<homeCnt-1; ++i) {
        dp[1][i] = max(dp[1][i-2] + money[i], dp[1][i-1]);
    }
    dp[1][homeCnt-1] = dp[1][homeCnt-2]; // 마지막 집
    
    // 2. 첫 번째 집을 선택하지 않은 경우
    dp[0][0] = 0;
    dp[0][1] = money[1];
    for(int i=2; i<homeCnt; ++i) {
        dp[0][i] = max(dp[0][i-2] + money[i], dp[0][i-1]);
    }
    
    return max(dp[1][homeCnt-1], dp[0][homeCnt-1]);
}
