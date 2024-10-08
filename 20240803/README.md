## 20240803 문제

### 백준 [수 이어 쓰기](https://www.acmicpc.net/problem/1515)

- 접근방식

  [은상]
  - `입력받은 문자열(str)의 인덱스를 참조할 변수(idx)`와 `입렫받은 문자열(str)와 비교하며 하나씩 증가시킬 변수(N)`를 선언
  - `idx`가 문자열의 index를 확인할 때까지 반복
    - 각 반복문 안에서 1 만큼 증가시킨 `N`의 각 자리수와 `str`의 각 자리수를 비교해가며 `idx`를 증가
  - 반복문을 탈출한 후 N의 결과값을 출력
  
  [주혜]
  - 최소값을 구해야 하기 때문에 1부터 완전 탐색을 해야함
  - idx를 따로 두어 주어진 수와 비교 수가 같으면 증가 시킴<br/>다르면 비교 수만 증가
  

- 피드백

  [은상]
  - 해결 방법이 떠오르지 않아 답지 참고
    
    → 무식하게 모든 경우를 다 살펴보는 브루트포스 알고리즘을 생각해보자
  
  [주혜]
  - 처음에 11에 1일 2개라는걸 인식 못해서 문제 이해 못함 -> Bad
  - 문제를 이해한 후 1부터 탐색해야한다는 것을 인지하면 쉬운 문제였음<br/> -> 바로 이해되지 않는다고 문제를 던지거나 조급해하지말고 오히려 차분하게 생각해는 버릇을 들여야 할 것 같음


### 프로그래머스 [최소직사각형](https://school.programmers.co.kr/learn/courses/30/lessons/86491)

- 접근방식

  [은상]
  - 첫 번째 명함부터 차례로 살펴보며
    - 명함을 세로로 놓았을 때와 가로로 놓았을 때 지갑의 크기를 비교하여
    - 지갑의 크기가 더 작은 경우의 `width`와 `height`을 저장
  - 최종 `width`와 `height`을 반환

  [주혜]
  - 가로 세로 정해진게 아니라 눕힐 수 있기 때문에 각 배열 값에서 두 수의 크기 비교 후 더 큰 값을 한 쪽으로 정렬
  - 정렬된 값의 가로, 세로 값 중 max 값 탐색
  - max 세로 * max 가로 return
  
- 피드백

  [은상]
  - 결과적으로 어떻게 최대한 짧고 간결하게 코드를 작성할 수 있을까 고민하느라 시간을 조금 소비하긴 했지만 꼭 필요한 과정이었다
    - 명함을 세로로 놓았을 때와 가로로 놓았을 때 지갑의 크기를 비교하는 과정에서의 코드 작성 단계에서 고민
    - 코드가 길어지고 가독성이 저하되는 현상을 막기 위해 변수를 지정하지 않고 바로 크기를 계산
        
        ```cpp
        // 세로가 더 작은 경우
        if(max(size[0], maxw) * max(size[1], maxh) < max(size[0], maxh) * max(size[1], maxw))
        
        // 가로가 더 작은 경우
        else
        ```
  
  [주혜]
  
  
