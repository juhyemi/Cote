## 20241016 문제

### 백준 [단축키 지정](https://www.acmicpc.net/problem/1283)

- 접근방식

  [은상]
  - 각 option에 기능들까지 저장해야 하므로 → 두 가지 정보를 저장할 수 있는 2차원 문자열 벡터 선언과 값 삽입
  - 모든 option을 순회하며
    1. 기능들을 차례대로 살펴보며 아직 단축키로 지정하지 않은 첫 글자가 있으면 단축키로 지정 → 다음 option으로 pass
    2. 모든 기능의 첫 글자가 단축키로 저장되어 있으면 → 각 기능의 모든 글자를 차례대로 살펴보며 아직 단축키로 지정하지 않은 글자를 단축키로 지정
  - cf. 대소문자를 구분하지 않는 조건을 주의!

  [주혜]
  - n개의 문자열 탐색
  - 각 문자열을 " " 기준으로 배열 생성
  - set 이용하여 겹치는 단축키 없도록 구현
  - 첫번째 단어와 겹치지 않으면 " " 기준으로 나눈 배열에 첫번째 알파벳에만 [] 씌워 저장 후 String.join을 이용하여 StringBuilder에 넣음
  - 첫번째 단어가 이미 단축키인 경우 해당 단어 전체 탐색 후 공백이 아니면서 set에 없는 단어 발견시 [] 만 해당 단어에 추가
  - 모든 단어가 이미 set에 있는 경우 해당 문자열 그대로 StringBuilder에 저장
    
- 피드백

  [은상]
  - `구현` → 로직은 어렵지 않으나, 사용하거나 직접 작성할 줄 알아야 하는 함수가 존재
    1. `split()` 구현
        
        ```cpp
        vector<string> split(string str, char delimiter) {
          vector<string> result;
          stringstream ss(str);
          string temp;
        
          while(getline(ss, temp, delimiter)) {
            result.push_back(temp);
          }
        
          return result;
        }
        ```
        
    2. `getline()` 사용 → 한 줄 입력받기
        
        ```cpp
        string s;
        getline(cin, s, '\n');
        ```
        
        - cf. 입력 버퍼에 어떤 문자나 문자열이 남아있을 경우 해당 문자나 문자열이 저장될 수 있다
            - `getline()` 사용 전에 `cin`을 사용했다면 버퍼를 비우자 → `cin.ignore();`
    3. `substr()` 사용
    
    → 한 번 리마인드 후 넘어가자
 
  [주혜]
  - 전체 단어 탐색시 공백 조건을 달아주지 않아 삽질
  - 첫 시도에 String.join 을 사용하지 않고 for 루프를 사용하여 sb에 저장하였다
  - String 관련 메서드를 더 숙지해보자!
  - 오늘의 String 관련 메서드 ** String.join : string 배열을 delimiter 을 기준으로 하나의 문자열로 만들 수 있다!
  
