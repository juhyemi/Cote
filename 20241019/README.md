## 20241019 문제

### 프로그래머스 [징검다리](https://school.programmers.co.kr/learn/courses/30/lessons/43236)

- 접근방식

  [은상]
  - 주어진 수가 상당히 크고, 직관적인 방법으로 접근했을 때 시간복잡도가 비정상적으로 크다 → 이분탐색 의심
  - 이분탐색
    - 기준(`mid`): 각 지점 사이의 거리의 최솟값
    - 각 지점 사이의 거리의 최소값이 `mid`값이 될 수 있는지 판단
        - 모든 각 지점 사이의 거리를 확인, 그 거리가 `mid`보다 작으면 해당 바위를 제거
            - 위치 순서대로 거리를 확인하기 위해 바위의 위치를 정렬
        - 제거한 바위의 개수로 `mid`값 가능 여부를 확인
            - 제거한 바위의 개수가 `n` 이하이면 → 각 지점 사이의 거리의 최솟값이 `mid`보다 클 수 있다
                - answer = mid로 초기화 후 `mid`값을 늘려서 다시 확인
            - 그렇지 않으면
                - `mid`값을 줄여서 다시 확인
  
  [주혜]
  - 돌 사이의 거리를 구하기 위한 배열 선언
  - min 1, max 는 주어진 distance
  - mid는 임의의 최솟값임으로 중간 값으로 잡은 후 없앨 돌 개수 선언
  - mid보다 작은 거리가 있으면 안되기 때문에 돌을 빼줌
  - mid값보다 sum이 커지면 sum 0으로 초기화
  - 거리 확인 후 돌개수가 n보다 크면 max=mid-1
  - 아니면 min = mid+1, answer 갱신
  
  
- 피드백

  [은상]
  - 도착지점까지의 거리가 최대 10억이므로, 이분탐색의 기준(`mid`)을 이 거리로 지정해야 한다고 생각하여 접근했지만 → 각 지점 사이의 거리의 최솟값(정답 반환값)을 기준으로 설정해야 했다
    - 이분탐색 문제를 더 접해보며 기준(`mid`) 설정에 더 능숙해지자
  - 각 지점 사이의 거리의 최솟값을 `mid`로 설정했다고 하면 → 제거한 바위의 수로 mid의 이상 이하 판단할 생각을 어떻게…?
    - 이런 문제도 있구나~ 하고 넘어가자
 
  [주혜]
  - 접근 방식 good
  - 돌 제거하는 부분에서 계산 잘못했었음 ㅠ
  - 이분탐색 로직구현할 때 헷갈렸지만 해냈다!
  
  
