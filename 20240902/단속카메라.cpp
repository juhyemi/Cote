#include <vector>
#include <algorithm>
using namespace std;

int answer;
int carOutMinPoint; // 현재까지 살펴본 차량 중 가장 빠른 진출 지점

bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    // 차량 입장 순서대로 살펴보기 위해 정렬
    sort(routes.begin(), routes.end(), cmp);
    
    // 현재까지 살펴본 차량 중 가장 빠른 진출 지점 값 초기화
    carOutMinPoint = routes[0][1];
    
    for(int i=0; i<routes.size(); ++i) {
        // 현재까지 가장 빠른 진출 지점보다 뒤에 진입한 차량이 있다면 카메라 설치
        // (지점의 중복이 없으면 카메라를 설치해야 한다)
        if(carOutMinPoint < routes[i][0]) {
            ++answer;
            // 카메라 설치를 통해 단속할 수 있는 이전 차량을 제외하고
            // 현재까지 가장 빠른 진출 지점 갱신
            carOutMinPoint = routes[i][1];
        }
        
        // 현재까지 가장 빠른 진출 지점 갱신
        if(carOutMinPoint > routes[i][1]) {
            carOutMinPoint = routes[i][1];
        }
    }
    
    // 나머지 차량의 단속을 위한 카메라 한 대 추가
    return ++answer;
}

// https://mungto.tistory.com/49
// https://resilient-aura-65d.notion.site/4d4a80a9f3194e3783c900c0d038e78a?pvs=4
