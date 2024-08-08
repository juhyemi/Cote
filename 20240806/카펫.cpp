#include <vector>
#include <cmath>
using namespace std;

vector<int> answer;

vector<int> solution(int brown, int yellow) {
    // 곱해서 yellow가 되는 (x, y) 순서쌍 탐색
    for(int i=1; i<=sqrt(yellow); ++i) {
        if(yellow % i) continue;
        int x = yellow / i;
        int y = i;

        // '(x + 2) * (y + 2) = 카펫의 넓이(brown + yellow)'를 만족하는지 검사
        // 만족하면 카펫의 (가로, 세로) = (x + 2, y + 2)
        if((x + 2) * (y + 2) != brown + yellow) continue;
        answer.push_back(x + 2);
        answer.push_back(y + 2);
        break;
    }
    
    return answer;
}

// https://resilient-aura-65d.notion.site/3f896ff649e44c11aa371a447abe53c6?pvs=4
