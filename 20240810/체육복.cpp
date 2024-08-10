#include <vector>
using namespace std;
#define MAX 35

int answer;
bool isReserve[MAX], isLost[MAX];

int solution(int n, vector<int> lost, vector<int> reserve) {
    answer = n; // 정답 변수를 최대값으로 설정
    for(const auto& l : lost) isLost[l] = true;
    for(const auto& r : reserve) isReserve[r] = true;
    
    // 모든 학생을 1번부터 차례로 순회하며
    // 체육 수업을 들을 수 없으면 (정답 변수 - 1)
    for(int i=1; i<=n; ++i) {
        if(!isLost[i]) continue;
        
        // 1. 자신의 여벌이 있는 경우
        if(isReserve[i]) {
            isReserve[i] = false;
            isLost[i] = false;
            continue;
        }
        
        // 2. 앞 사람의 체육복을 빌릴 수 있는 경우
        if(isReserve[i-1]) {
            isReserve[i-1] = false;
            isLost[i-1] = false;
            continue;
        }
        
        // 3. 뒤 사람의 체육복을 빌릴 수 있는 경우
        // 빌리기 전에 그 사람의 도난 여부를 확인
        if(isReserve[i+1] && !isLost[i+1]) {
            isReserve[i+1] = false;
            isLost[i+1] = false;
            continue;
        }
        
        --answer;
    }
    
    return answer;
}

// 01:02:39
// https://resilient-aura-65d.notion.site/47d1569bf1da4978b003055caa0cc178?pvs=4
