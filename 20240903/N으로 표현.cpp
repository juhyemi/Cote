#include <unordered_set>
using namespace std;

// dp[i]: i개의 N으로 만들 수 있는 수들의 배열 저장
// 중복과 정렬이 필요 없고, 각 index 배열에서 number을 찾는 과정이 필요하기 때문에 unordered_set 선언
// 최대 8개의 숫자를 이용하기 때문에 index 9까지 선언
unordered_set<int> dp[9];

// Cnt개의 N을 이어붙여 만들 수 있는 수 반환
int getCntN(int cnt, int n) {
    int result = n;
    for(int i=1; i<cnt; ++i) {
        result = 10 * result + n;
    }
    return result;
}

int solution(int N, int number) {
    // cnt개의 N으로 만들 수 있는 수들을 차례로 삽입
    for(int cnt=1; cnt<=8; ++cnt) {
        // cnt개의 N을 이어붙이는 과정부터 시작
        dp[cnt].insert(getCntN(cnt, N));
        
        // i + j = cnt 일 때,
        // dp[i] (사칙연산) dp[j] = dp[cnt]가 되는 경우를 dp[cnt]에 저장
        for(int i=1; i<cnt; ++i) {
            for(int j=1; j<cnt; ++j) {
                if(i + j != cnt) continue;
                
                for(const auto& a : dp[i]) {
                    for(const auto& b : dp[j]) {
                        dp[cnt].insert(a + b);
                        // 양수만 저장
                        if(a - b > 0) dp[cnt].insert(a - b);
                        dp[cnt].insert(a * b);
                        // 양수만 저장
                        if(a % b == 0 && a / b > 0) dp[cnt].insert(a / b);
                    }
                }
            }
        }
        
        // cnt를 1부터 차례로 살펴보며 dp[cnt]에서 number가 있는지 검사
        // 있으면 cnt를 반환하고 종료
        if(dp[cnt].find(number) != dp[cnt].end()) return cnt;
    }
    
    // cnt가 8이 될 때까지 number가 없으면 -1 반환
    return -1;
}

// https://velog.io/@euneun/프로그래머스-N으로-표현-DP-동적계획법-C
// https://resilient-aura-65d.notion.site/N-59bbf16aaa274544b7eeba34421c4961?pvs=4
