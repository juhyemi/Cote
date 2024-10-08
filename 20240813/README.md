## 20240813 문제

### 백준 [랭킹전 대기열](https://www.acmicpc.net/problem/20006)

- 접근방식

  [은상]
  - 각 플레어이마다 여태까지 생성된 방을 차례로 살펴보며 입장 조건을 만족하면 입장
  - 입장 조건을 만족하는 방이 없으면 방 생성
  - 구현을 위해 방의 개수(`groupCnt`), 방의 최대, 최소 레벨을 저장하기 위한 배열(`groupLevel[MAX]`), 각 방에 입장한 플레이어의 레벨과 이름을 저장할 벡터(`groupPlayer[MAX]`) 선언
  - 출력 시
    - 각 `groupPlayer[]` 의 size를 통해 방의 시작 여부를 판별
    - 사전순 출력을 위해 각 `groupPlayer[]` 정렬
  
  [주혜]
  - 방이 있고, 해당 정원 수가 다 차지 않고 level 범위 안에 들면 입장
  - 방이 없거나 level 범위 안에 드는 방이 없으면 새로운 방생성과 동시에 입장
  - 방 정원이 다 차있으면 Started!, 모자르면 Waiting! 입력 후
  - 방에 있는 플레이어를 name 순으로 정렬 후 StringBuilder에 추가
  
- 피드백

  [은상]
  - 삽질 Point
    - 예시만 보고 player의 이름이 문자인 줄 알았지만 문자열이었다
    - 예시만 보고 당연히 player의 이름이 사전 순으로 주어지는 줄 알았지만 따로 정렬이 필요했다
        
        → 예시만 보고 당연히 이럴 것이라는 착각을 하는 경향이 있음
        
        → 모든 문제를 처음부터 완벽히 파악하지 못할 수 있지만, 지금처럼 최대한 빠르게 잘못 파악한 부분을 찾아내는 게 중요할 듯
  
  [주혜]
  - class 생성을 통해 변수 관리 good
  - 문제 꼼꼼하게 읽어서 Waiting! 조건 설정 good

### 프로그래머스 [큰 수 만들기](https://school.programmers.co.kr/learn/courses/30/lessons/42883)

- 접근방식

  [은상]
  - `k개의 수를 제거한다 = (n-k)개의 수를 뽑는다` → `(n-k)`번 반복하며 수를 선택
    - `i`를 `(n-k)`부터 하나씩 줄여가며 `1`까지 반복
    - `number`의 뒤에서부터 `(n-i)`개의 수를 남겨두고 나머지 수 중 제일 큰 수를 선택

  [주혜]
  - 큰 수 만들기 이고 삭제해야하는 k가 있기 때문에 Strack이용
  - 문자열 순차적으로 탐색하며 stack에 넣는데, stack이 차있을경우 peek이 탐색하는 것보다 작으면 빼고 k감소
  - 탐색 후에도 k가 0이 아니면 stack에서 그 횟수만큼 빼줌줌
  
  
- 피드백

  [은상]
  - 예외 Case ?
    
    ```cpp
    #include <string>
    #include <vector>
    #include <iostream>
    using namespace std;
    #define MAX 1000010
    
    string answer;
    int n; // numberLength
    int idx;
    
    string solution(string number, int k) {
        n = number.length();
        while(k > 0 && idx < n) {
            // cout << "현재 숫자: " << number[idx] << '\n';
            
            // 맨 앞 숫자랑 비교
            // 크면 왼쪽으로 가까운 숫자부터 min(idx, k)개 제거
            if(number[idx] > number[0]) {
                // cout << "첫 번째 숫자: " << number[0] << '\n';
                // cout << "number[idx] > number[0]" << '\n';
                number.erase(number.begin() + idx - min(idx, k), number.begin() + idx);
                k -= min(idx, k);
                idx -= min(idx, k);
                // cout << "결과: " << number << '\n';
                // cout << "남은 k의 개수: " << k << '\n';
            }
            
            // 오른쪽 숫자랑 비교
            // 작으면 현재 숫자 제거
            if(k > 0 && idx + 1 < n && number[idx] < number[idx + 1]) {
                // cout << "다음 숫자: " << number[idx + 1] << '\n';
                // cout << "number[idx] < number[idx + 1]" << '\n';
                number.erase(number.begin() + idx);
                --k;
                idx = idx - 1;
                // cout << "결과: " << number << '\n';
                // cout << "남은 k의 개수: " << k << '\n';
            }
            
            ++idx;
        }
            
        return number;
    }
    ```
    
  - 풀이법을 떠올리기는커녕 풀이를 이해하는 데만 한참 걸림 → 이 문제는 풀이 방법까지 그냥 통째로 외웁시다
  
  [주혜]
  - 빠른 판단 good!
