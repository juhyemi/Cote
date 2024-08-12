#include <string>
#include <vector>
#include <cmath>
using namespace std;

int answer;
int n; // nameLength
int minCursorMoveCnt;

// 알파벳 변경 시 조이스틱 조작 횟수
int getMoveCntByConvert(char c) {
    if(c > 'N') return 'Z' - c + 1;
    return c - 'A';
}

int solution(string name) {
    n = name.length();
    // Case 1. 한 방향으로 이동 시 커서 이동 횟수는 n - 1
    minCursorMoveCnt = n - 1;
    
    for(int i=0; i<n; ++i) {
        if(name[i] == 'A' && i != 0) continue;
        // cf. 예시로, 'AAAX' 일 때 (i != 0) 조건 필요
        
        // 알파벳을 변경하기 위한 조작 횟수 추가
        answer += getMoveCntByConvert(name[i]);
        
        // Case 3. 방향을 바꿔가며 커서를 이동하는 경우
        // Case 2. 한 방향으로 이동하되, 필요한 만큼만 이동하는 경우 포함
        int j = i + 1; // 현재 위치를 기준으로 우측에 있는 문자 중 'A'가 아닌 가장 가까운 문자 위치
        while(name[j] == 'A' && j < n) ++j;
        minCursorMoveCnt = min(minCursorMoveCnt, min(2 * i + (n - j), 2 * (n - j) + i));
    }
    
    // 커서 이동 횟수 추가
    answer += minCursorMoveCnt;
    
    return answer;
}

// cf. https://googleyness.tistory.com/entry/C-프로그래머스-조이스틱
// https://resilient-aura-65d.notion.site/36268adbb23e4de48e7a1ed7c031e720?pvs=4
