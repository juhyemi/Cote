#include <vector>
#include <string>
#include <climits>
using namespace std;
#define MAX 110

int max_dp[MAX][MAX];
int min_dp[MAX][MAX];
// dp[i][j]: k가 연산자의 위치를 나타날 때, {i ~ k}, {(k+1) ~ j} 연산의 최대, 최소값 저장
int numCnt; // 식 내 숫자 개수

int solution(vector<string> arr) {
    numCnt = arr.size() / 2 + 1;
    
    // 배열 초기화
    for(int i=0; i<numCnt; ++i) {
        for(int j=0; j<numCnt; ++j) {
            // 숫자가 한 개짜리 식은 그 숫자 자체가 값
            if(i == j) {
                max_dp[i][j] = stoi(arr[i*2]);
                min_dp[i][j] = stoi(arr[i*2]);
                continue;
            }
            
            max_dp[i][j] = INT_MIN;
            min_dp[i][j] = INT_MAX;
        }
    }
    
    // 최대, 최소 dp 계산
    for(int idx=1; idx<numCnt; ++idx) {
        for(int i=0; i<numCnt-idx; ++i) {
            int j = idx + i;
            for(int k=i; k<j; ++k) {
                // 연산자가 '-' 일 때 최대값은 max_dp[i][j] - min_dp[i][j]
                // 연산자가 '-' 일 때 최소값은 min_dp[i][j] - max_dp[i][j]
                if(arr[k*2+1] == "-") {
                    max_dp[i][j] = max(max_dp[i][j], max_dp[i][k] - min_dp[k+1][j]);
                    min_dp[i][j] = min(min_dp[i][j], min_dp[i][k] - max_dp[k+1][j]);
                }
                
                // 연산자가 '+' 일 때 최대값은 max_dp[i][j] + max_dp[i][j]
                // 연산자가 '+' 일 때 최소값은 min_dp[i][j] + min_dp[i][j]
                else if(arr[k*2+1] == "+") {
                    max_dp[i][j] = max(max_dp[i][j], max_dp[i][k] + max_dp[k+1][j]);
                    min_dp[i][j] = min(min_dp[i][j], min_dp[i][k] + min_dp[k+1][j]);
                }
            }
        }
    }
    
    // 위 로직에서 마지막 연산은 max_dp[0][numCnt-1]
    return max_dp[0][numCnt-1];
}

// https://velog.io/@estelle17/프로그래머스-문제-사칙연산
