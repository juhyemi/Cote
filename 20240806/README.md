## 20240806 문제

### 백준 [비슷한 단어](https://www.acmicpc.net/problem/2607)

- 접근방식

  [은상]
  - 두 단어가 서로 비슷할 조건을 판단
    - 비교할 두 단어의 길이가 같은 경우
        - 구성이 같다
        - 한 문자를 다른 문자로 바꾸면 구성이 같아진다
    - 비교할 두 단어의 길이가 1 차이 나는 경우
        - 문자 하나를 추가하면 구성이 같아진다
  1. 비교할 두 단어의 각 문자(알파벳) 개수를 저장
  2. 두 단어가 서로 비슷한지 판단
    - A ~ Z까지 모든 문자의 개수를 비교하며, `개수 차이가 1인 문자의 개수(DifferentCnt)`를 저장
        - `DifferentCnt = 0` → 구성이 같다
        - `DifferentCnt = 1` → 문자 하나를 추가하면 구성이 같아진다
        - `DifferentCnt = 2` → 한 문자를 다른 문자로 바꾸면 구성이 같아진다
    - 비교할 두 단어의 길이가 같을 때와 하나 차이날 때를 구분하여 판단
    - 예외 조건(두 단어가 비슷하지 않을 조건) 고려
        - 단어의 길이가 2 이상 차이 나는 경우
        - 특정 문자 개수가 2 이상 차이 나는 경우
  
  [주혜] 
  - 두 단어의 길이 비교 (하나만 바꿔서 같은 구성의 문자열로 만들 수 있는지)
  - 기존 문자열과 비교 문자열별 구성비교를 위한 배열 선언
  - 한 개 차이만 나는 경우 cnt2 이용하여 따로 확인 (두 개의 알파벳 변경으로 같은 문자열이 될 수 있는 경우)
  - 두 문자열의 차이가 1면 answer++
  - 두 문자열의 차이가 2인데, cnt2도 2면 answer++

- 피드백

  [은상]
  - 처음에 정렬을 이용해서 풀이를 시도했지만 오답이 발생했고, GPT를 이용하여 이틀 만에 예외 case를 발견 → 이 문제는 꼭 통째로 기억하고 같은 과오를 반복하지 말자!
    - 정렬 풀이 code
        
        ```cpp
        #include <iostream>
        #include <vector>
        #include <algorithm>
        #include <string>
        using namespace std;
        
        int N;
        string word, s;
        int cnt;
        
        bool isSimilar(string a, string b) {
          // 동일하면 true
          if(a == b) return true;
          
          // a를 더 긴 단어로 설정
          if(a.length() < b.length()) swap(a, b);
        
          // 길이가 2 이상 차이나면 false
          if((a.length() - b.length()) > 1) return false;
        
          for(int i=0; i<a.length(); ++i) {
            if(a[i] == b[i]) continue;
        
            // a의 길이와 b의 길이가 같으면 → 두 단어 전부 해당 idx의 원소를 삭제
            // 다르면 → 긴 단어의 해당 idx 원소만 삭제
            if(a.length() == b.length()) b.erase(b.begin() + i);
            a.erase(a.begin() + i);
            break;
          }
        
          return a == b;
        }
        
        int main() {
        	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
        
          cin >> N;
          cin >> word;
          sort(word.begin(), word.end());
        	for(int i=1; i<N; ++i) {
            cin >> s;
            sort(s.begin(), s.end());
            if(isSimilar(word, s)) cnt++;
          }
        
          cout << cnt << '\n';
        }
        ```
        
    - 예외 case
        
        ```
        3
        AAB
        AAC
        ABC
        ```
        
  - 문제를 정확히 파악하고 CASE(문자열의 길이가 같은 경우와 다른 경우)를 잘 구분했으면, 답지를 한 번만 참고하여 문제를 해결할 수 있었을 것 → 특히 `구현` 유형은 문제 파악이 너무 중요하다! 항상 문제를 정확히 파악하는 연습 필요!
  
  [주혜]
  - 서로 다른 문자를 바꿀 때와, 문자열의 길이를 고려하지 않아 틀림
  - 복잡하거나 헷갈리다고 느껴질 경우 우선순위를 정한 후 하나씩 제끼며 답 찾는 연습 필요


### 프로그래머스 [카펫](https://school.programmers.co.kr/learn/courses/30/lessons/42842)

- 접근방식

  [은상]
  - 전체 카펫의 가로(X), 세로(Y)는 yellow 직사각형의 각 가로(x), 세로(y)의 길이 + 2
  - 따라서 `(x + 2) * (y + 2) = 전체 카펫의 넓이(brown + yellow)`가 되는 `(x, y)` 순서쌍을 탐색
    - 이 때 `(x, y)` 순서쌍은 yellow의 약수

  [주혜]
  
- 피드백

  [은상]
  - 처음 문제를 읽고 해결 방법이 쉽게 떠오르지 않아 계산식을 세워가며 수학적으로 접근 → 수단과 방법을 가리지 않고 해결 방법 탐색 Good!
  - `테두리 1줄은 갈색으로 칠해져 있는` 이라는 조건을 주의깊게 살펴봤다면<br>
    `전체 카펫의 가로, 세로는 yellow 직사각형의 각 가로, 세로의 길이 + 2` 라는 힌트를 빠르게 파악할 수 있었을 것<br>
    → 침착하고 주의깊게 문제를 파악하는 연습이 더 필요!
  
  [주혜]
  
  
