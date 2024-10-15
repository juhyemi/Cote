## 20241008 문제

### 백준 [문자열 교환](https://www.acmicpc.net/problem/1522)

- 접근방식

  [은상]
  - 문자열 내 a의 개수만큼 `슬라이딩 윈도우`의 크기를 설정
  - 슬라이딩 윈도우로 설정할 수 있는 모든 경우의 수를 살펴보며 → `브루트포스 알고리즘`
  - 해당 슬라이딩 윈도우의 모든 문자를 a로 몰아넣기 위해 바꿔야 하는 b의 개수를 계산
  - 계산한 ‘바꿔야 하는 b의 개수’ 중 최소값을 정답으로 출력

  [주혜]
  - 문자열에서 a의 개수 카운팅
  - for문 a개수만큼 돌면서 a개수 카운팅 -> 이 때 원형구조기 때문에 idx변수 사용하여 j가 범위를 넘을경우 앞에서 부터 탐색할 수 있도록 설정
  - 가장 많은 a개수 저장
  - 문자열에서 카운팅한 a개수 - 가장 많은 a개수
    
- 피드백

  [은상]
  - 실전에서는 ‘예제는 모두 맞지만 오답이 뜨는 풀이'는 검증할 방법이 없다 → 스트레스 받지 말고 이런 문제도 있구나 하고 넘어가!
    - 예외 Case?
    
    ```cpp
    #include <iostream>
    #include <string>
    using namespace std;
    
    string str;
    int len; // str.length()
    int s, e;
    int cnt; // answer
    int aCntFromBack; // 뒤에 연속으로 존재하는 a의 개수
    
    // 뒤에 연속으로 존재하는 모든 a를 앞으로 이동하는 함수
    void mySort() {
      for(int i=len-1; i>=0; --i) {
        if(str[i] == 'b') break;
        aCntFromBack++;
      }
    
      str = str.substr(0, len - aCntFromBack);
      for(int i=0; i<aCntFromBack; ++i) {
        str = 'a' + str;
      }
    }
    
    int main() {
    	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
    
    	cin >> str;
      len = str.length();
      mySort();
      s = 0;
      e = len - 1;
      
      while(true) {
        while(str[s] == 'a' && s < len) s++;
        while(str[e] == 'b' && e > 0) e--;
        if(s >= e) break;
        cnt++;
        s++;
        e--;
      }
    
      cout << cnt << '\n';
    }
    
    // 시간복잡도: O(len)
    ```
  - 문자열이 원형으로 이어져 있을 때 index를 쉽게 처리하기 위한 방법 → 문자열을 복사하여 확장
  
 
  [주혜]
  - 문제 이해만 된다면 쉽게 풀 수 있는 문제였다
  - 너무 어렵게 생각하지말고 차분하게 풀이해보자
