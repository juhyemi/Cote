## 20240902 문제

### 백준 [창고 다각형](https://www.acmicpc.net/problem/2304)

- 접근방식

  [은상]
  - 가장 높은 기둥을 기준으로 왼쪽과 오른쪽의 범위를 나누어 계산
    - 왼쪽은 0-index부터, 오른쪽은 last-index부터 탐색
    - 각 범위에서 현재까지 살펴본 기둥 중 가장 높은 기둥의 높이를 추가
  - 마지막으로 가장 높은 기둥의 높이를 추가
  
  [주혜]
  
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
              s.push(i);
              continue;
            }
        
            int prevPos = s.top();
        
            // 이전 기둥보다 현재 기둥이 높은 경우
            if(pillars[prevPos] >= pillars[i]) continue;
            answer += (prevPos - i) * pillars[prevPos];
            s.pop();
            s.push(i);
        
            // 최고 높이 기둥 등장
            if(pillars[i] == maxHeight) {
              lastMaxHeightPos = i;
              break;
            }
          }
        
          answer += (lastMaxHeightPos - firstMaxHeightPos + 1) * maxHeight;
        
          cout << answer << '\n';
        }
        ```
        
    - 예외 처리에 트라우마 생긴듯… 무섭다…
    - 결론은 가장 높은 기둥 중 아무거나 선택해서 풀어도 예외는 자동으로 해결
  
  [주혜]
  

### 프로그래머스 [단속카메라](https://school.programmers.co.kr/learn/courses/30/lessons/42884)

- 접근방식

  [은상]
  

  [주혜]
  
  
- 피드백

  [은상]
  
  
  [주혜]
  
