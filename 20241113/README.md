## 20241113 문제

### 백준 [문자열 게임 2](https://www.acmicpc.net/problem/20437)

- 접근방식

  [은상]
  1. 문자열의 알파벳 문자별로 등장 빈도수 저장
  2. `K`와 같거나 `K`보다 큰 빈도수를 가진 문자들만을 대상으로 실행
      1. 해당 문자를 부분 문자열의 시작 문자로 지정
      2. 이후 문자들을 살펴보며, 시작 문자와 동일한 문자를 만날 때마다 count
      - 그 카운트가 `K`가 되었을 때 최소 길이(`answer_3`), 최대 길이(`answer_4`)를 update

  [주혜]
  
- 피드백

  [은상]
  - 슬라이딩 윈도우 유형임을 파악하고, 윈도우 내 각 문자의 등장 빈도수를 계산하여 값을 구하려고 했지만 → 코드 작성이 생각보다 어려워서 머리가 굴러가지 않아 긴 여정 끝에 포기
    - 윈도우의 개수를 하나씩 증가해가며 모든 부분 문자열을 검사해야 하니 다중 반복분이 발생
    - 윈도우 내 부분 문자열의 각 문자 인덱스를 참조하며 등장 빈도수를 수정할 때 번거로움 존재
    - 등
  - 답지를 보니, “문자열에서 등장 빈도수가 K 이상인 문자에 대해서만 부분 문자열의 시작 문자열로 설정 후 탐색”하면 간단하게 코드를 작성할 수 있는 풀이가 존재
  - 코드 작성이 아니다 싶을 정도로 복잡하고 어려우면 → 멈추고 쉬운 풀이법을 고민해보자

  [주혜]
