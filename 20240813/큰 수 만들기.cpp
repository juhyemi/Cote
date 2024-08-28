#include <string>
#include <vector>
#include <iostream>
using namespace std;

int maxIdx = -1;
int n; // numberLength
string answer;

string solution(string number, int k) {
    n = number.length();
    
    // (n-k)만큼 반복
    for(int i=n-k; i>0; --i) {
        int maxValue = -1;
        
        // 방금 선택한 수 다음부터 뒤에서 (n-i)개의 수를 남겨두고 제일 큰 수를 선택
        for(int j=maxIdx+1; j<=n-i; ++j) {
            if(maxValue >= number[j] - '0') continue;
            maxValue = number[j] - '0';
            maxIdx = j;
        }
        
        // 선택한 수를 추가
        answer += number[maxIdx];
    }
    
    return answer;
}

// cf. https://mjmjmj98.tistory.com/68
// https://resilient-aura-65d.notion.site/a731ce41e3634ba9ab306c6355a8ebd0?pvs=4
