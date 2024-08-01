## 20240801 문제

### 백준 [예산](https://www.acmicpc.net/problem/2512)

- 접근방식

  [은상]
  - 이분 탐색
    - 분배할 예산의 범위는 `0 ~ 요청 최대 금액` 사이의 값
    - 1원씩 증가하며 모든 경우의 수를 판단하면 시간초과
  
  [주혜]
  - 총액이 예산 내면 예산 요청 최대값
  - 예산 최대, 최소 기준 중앙값부터 탐색

- 피드백

  [은상]
  - 이분 탐색을 진행할 때 최소 예산 금액을 `0`이 아닌 `*min_element()`로 설정하여 약 20분 동안 삽질 → 이분 탐색 문제를 풀 때 처음 범위 설정에 신경 쓰자!
  - 처음 풀이 코드와 비교
    
    ```cpp
    // 처음 풀이 코드
    while((s + e) / 2 != limit) {
    	limit = (s + e) / 2;
    	price = getPrice();
    	if(price < M) {
    		s = limit;
    	} else if(price > M) {
    		e = limit;
    	}
    }
    
    // 리팩토링 코드
    while(s <= e) {
    	m = s + (e - s) / 2;
    	if(getPrice() <= M) {
    		limit = m;
    		s = m + 1;
    	} else {
    		e = m - 1;
    	}
    }
    ```
    
    - 틀린 코드는 아니지만 `틀`을 기억할 수 있도록 간결한 코드 선호
    - `mid` 값을 구할 땐 `int`형 범위를 초과하지 않도록 주의
  
  [주혜]
  - 처음에 while문이 도는 조건 설정을 잘못 설정 -> 결국 예산의 최소, 최대를 좁혀나가는 것이기 때문에 최소값과 최대값 비교교


### 프로그래머스 [가장 큰 수](https://school.programmers.co.kr/learn/courses/30/lessons/42746)

- 접근방식

  [은상]
  - 숫자를 문자열로 변환하여 정렬
    - “3” vs “30” → “330” vs “303”
  - 정렬된 순서대로 문자열에 이어 붙여 반환
  - 만약 반환할 문자열이 ‘0’으로만 구성되어 있으면 “0” 반환
  
  [주혜]
  - 절대 숫자값이 아니기 때문에 문자열로 변경
  - 정렬시 문자열 두개를 앞뒤로 붙여 비교
  - 0만 있다면 0반환환
  
- 피드백

  [은상]
  - 나름 예외 처리를 했지만
    
    ```cpp
    // 앞 숫자까지 동일하면
    // 뒤에 나오는 숫자가 큰 숫자를
    // 우선순위를 높게 설정하려는 의도..
    bool comp(const string& a, const string& b) {
    	int aLength = a.length();
    	int bLength = b.length();
        
    	if(a.substr(0, bLength) == b && a[bLength - 1] > a[bLength]) {
    		return a < b;
    	}
        
    	if(b.substr(0, aLength) == a && b[aLength - 1] > b[aLength]) {
    		return a > b;
    	}
        
    	return a > b;
    }
    ```
    
  - 오답이 발생하여 질문 게시판에서 Test Case 참고하여 처리되지 않는 예외 경우 확인
    - [1, 10, 100, 1000] → “1000100101” 출력
  - 해당 예외를 처리하는 방법을 “몰라서” 결국 답지 참고
  - 해결하지 못했던 부분 → 기억하자
    
    ```cpp
    bool comp(const string& a, const string& b) {
	    return a + b > b + a;
    }

    // 간단하게 생각하자
    bool comp(비교_요소_a, 비교_요소_b) {
	    return 최종_비교_A > 최종_비교_B;
	    // 비교연산자:
	    // '>': 내림차순 정렬
	    // '<': 오름차순 정렬
    }
    ```
  
  [주혜]
  - PriorityQueue에 정렬 조건을 int로 주려다 실패. int로 설정할 수 없음 (문자열의 길이를 탐색해야하고 return의 기준이 모호함)
  -> 문자열 앞뒤로 붙여 비교하는 방법 참고함
  
  
