## 20241101 문제

### 백준 [컨베이어 벨트 위의 로봇](https://www.acmicpc.net/problem/20055)

- 접근방식

  [은상]
  - 벨트를 하나씩 움직이도록 구현하면 시간복잡도가 너무 커지기 때문에 → 벨트는 고정하고 올리는 위치와 내리는 위치를 조정하는 방식을 사용
  - 내구도가 0이 된 벨트의 개수가 K개 이상이 될 때까지 반복문 실행
    1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
        - 올리는 위치와 내리는 위치를 `현재 위치 - 1`로 설정
        - 변경된 내리는 위치에 로봇이 있을 경우 로봇을 제거
    2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
        - 가장 먼저 벨트에 올라간 로봇부터 살펴봐야 한다는 조건
          - 가장 먼저 벨트에 올라간 로봇은 내리는 위치와 가장 가까운 로봇이다
          - 따라서 `내리는 위치 - 1`부터 올리는 위치까지 차례로 살펴본다
              - cf. 내리는 위치는 이미 위에서 확인 완료
          - 그 외 위치에는 로봇이 존재할 수 없다
        - 로봇을 옮긴 후 내구도 감소
        - 로봇을 옮긴 위치가 내리는 위치일 경우 로봇을 제거
    3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
        - 로봇을 올린 후 내구도 감소

  [주혜]
  
- 피드백

  [은상]
  - 삽질 Point
    1. 처음에, 가장 먼저 벨트에 올라간 로봇부터 살펴봐야 한다는 조건을 확인하지 않고 → 올리는 위치부터 모든 벨트를 모두 확인하는 코드를 작성하여 삽질
    2. 가장 먼저 벨트에 올라간 로봇부터 살펴봐야 한다는 조건을 충족하기 위해 약29,823 시간 동안 고민했지만, 결국 머리가 돌아가지 않아 답지 참고
    3. 내리는 위치부터 올리는 위치까지 살펴보는 과정→ 옮기기 전 위치와 옮긴 후 위치 설정 삽질 → 답지와 비교를 통해 오류 확인
        
        ```cpp
        for(int i=0; i<N-1; ++i) {
        	int currentIdx = (downIdx == 0 ? 2 * N - 1 : downIdx - i);
        	int nextIdx = (currentIdx + 1) % (2 * N);
        	...
        }
        ```
        
        - 이런식으로 코드를 작성하면 옮기기 전 위치는 음수가 될 수 있다
  - 다른 건 전부 엉망이었지만, 시간복잡도를 고려하여 벨트는 고정하고 올리는 위치와 내리는 위치를 바꾸는 방식을 스스로 구상한 점은 Good!
 
  [주혜]
