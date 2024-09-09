## 20240906 문제

### 백준 [한 줄로 서기](https://www.acmicpc.net/problem/1138)

- 접근방식

  [은상]
  - 키가 작은 순서대로 살펴본다
    - 자리(위치)를 앞에서부터 순서대로 살펴보며 비어있는 자리를 찾아 위치
    - 아직 사람이 지정되지 않은 자리는 현재 사람보다 키가 큰 사람의 자리 → 왼쪽부터 살펴보며 지정되지 않은 자리가 나타날 때마다 현재 사람보다 키가 큰 사람의 수를 감소
    - 현재 사람보다 키가 큰 사람이 더 이상 없을 경우 빈 자리를 찾아 사람을 배치
  
  [주혜]
  
- 피드백

  [은상]
  - 실전에서 예외 Case가 있다는 사실을 확인할 가능성도 적겠지만, 만약 예외 Case가 있다는 사실을 알게 된다면, 그리고 그 예외 Case가 빠르게 떠오르지 않는다면 다른 풀이 방법을 떠올려야 한다
    - 무조건 다 풀고 남는 시간에!
  - 예외 Case?
    
    ```cpp
    #include <iostream>
    #include <string>
    using namespace std;
    #define MAX 12
    
    int N;
    int arr[MAX];
    string s;
    
    int main() {
    	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
    
    	cin >> N;
      for(int i=1; i<=N; ++i) {
        cin >> arr[i];
      }
    
      for(int i=N; i>=1; --i) {
        if(arr[i] == 0) {
          s = to_string(i) + s;
        }
    
        else if(arr[i] == s.length()) {
          s = s + to_string(i);
        }
    
        else {
          s = s.substr(0, arr[i]) + to_string(i) + s.substr(arr[i]);
        }
      }
    
      for(int i=0; i<s.length(); ++i) {
        cout << s[i] << ' ';
      }
    }
    ```
  
  [주혜]
  

  
