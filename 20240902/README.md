## 20240902 문제

### 백준 [창고 다각형](https://www.acmicpc.net/problem/2304)

- 접근방식

  [은상]
  - 가장 높은 기둥을 기준으로 왼쪽과 오른쪽의 범위를 나누어 계산
    - 왼쪽은 0-index부터, 오른쪽은 last-index부터 탐색
    - 각 범위에서 현재까지 살펴본 기둥 중 가장 높은 기둥의 높이를 추가
  - 마지막으로 가장 높은 기둥의 높이를 추가
  
  [주혜]
  - 가장 높은 곳 기준으로 왼, 오 탐색
  - stack이 비어있으면 넣어주고 stack에 값이 있다면 stack 값과 현재 값 비교 후 현재값과 같거나 크면 (현재 인덱스-stack top 인덱스) * stack top 인덱스를 answer에 더해줌 (왼, 오 두 번 실행)
  
- 피드백

  [은상]
  - 가장 높은 기둥을 기준으로 왼쪽과 오른쪽의 범위를 나누어 계산하는 풀이까지 생각했지만, 아마도 가장 높은 기둥이 여러 개 존재하는 예외를 제대로 처리하지 못해서 오답 발생
    - 예외?
        
        ```cpp
        #include <iostream>
        #include <stack>
        using namespace std;
        #define MAX 1010
        
        int N, L, H;
        int pillars[MAX]; // 기둥의 위치와 높이 정보 저장
        int maxHeight;
        int lastPos;
        int answer;
        int firstMaxHeightPos, lastMaxHeightPos;
        stack<int> s;
        
        int main() {
        	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
        
        	cin >> N;
          for(int i=0; i<N; ++i) {
            cin >> L >> H;
            pillars[L] = H;
            if(H > maxHeight) maxHeight = H;
            if(L > lastPos) lastPos = L;
          }
        
          for(int i=0; i<=lastPos; ++i) {
            if(!pillars[i]) continue;
            if(s.empty()) {
              s.push(i);
              continue;
            }
            
            int prevPos = s.top();
        
            // 이전 기둥보다 현재 기둥이 높은 경우
            if(pillars[prevPos] >= pillars[i]) continue;
            answer = answer + (i - prevPos) * pillars[prevPos];
            s.pop();
            s.push(i);
        
            // 최고 높이 기둥 등장
            if(pillars[i] == maxHeight) {
              firstMaxHeightPos = i;
              break;
            }
          }
        
          while(!s.empty()) s.pop();
        
          for(int i=lastPos; i>=0; --i) {
            if(!pillars[i]) continue;
            if(s.empty()) {
              s.p의 무궁무진함을 다시한 번 느낌!
  

### 프로그래머스 [단속카메라](https://school.programmers.co.kr/learn/courses/30/lessons/42884)

- 접근방식

  [은상]
  1. 차량 입장 순서대로 살펴보기 위해 정렬
  2. 순회하며 현재까지 가장 빠른 진출 지점보다 뒤에 진입한 차량이 있다면 카메라 설치
    - 지점의 중복이 없으면 카메라를 설치해야 하기 때문
    - 카메라 설치를 통해 단속할 수 있는 이전 차량을 제외하고 현재까지 가장 빠른 진출 지점 갱신
  3. 현재까지 가장 빠른 진출 지점 갱신
  4. 마지막에 아직 단속하지 않은 나머지 차량의 단속을 위한 카메라 한 대 추가

  [주혜]
  
  
- 피드백

  [은상]
  - 카메라를 최소로 설치할 조건을 파악했지만 코드 구현에 실패하여 답지 참고
  - 최근 예외 Case를 모두 고려하는 과정에서 빈번히 막혔지만, 그나마 충분한 고민을 통해 이번 문제에서는 극복..
  - 코드로 구현하기 어려웠던 부분에 대해 답지를 보자마자 아차 싶었던 걸로 보아 조금만 더 노력하면 될 듯!
    - 진입 순서에 상관없이 현재까지 살펴본 차량의 진출 지점 중 최소값을 관리하는 로직
    - 이전 차량의 진입, 진출 정보를 모두 저장하고 있어야 한다고 생각하여 막혔지만, 결론은 그럴 필요가 없었음
  
  [주혜]
  
