## 20241018 문제

### 백준 [1, 2, 3 더하기 4](https://www.acmicpc.net/problem/15989)

- 접근방식

  [은상]
  - 모든 수(`i`)에 대해 다음 정보를 저장할 2차원 dp 배열 선언
    - 1의 합으로 이루어진 식의 경우의 수 → dp[i][1]
        - 2와 3이 존재하면 X
    - 1과 2의 합으로 이루어진 식의 경우의 수 → dp[i][2]
        - 2는 필수, 1은 선택
        - 3이 존재하면 X
    - 1과 2와 3의 합으로 이루어진  식의 경우의 수 → dp[i][3]
        - 3은 필수, 1과 2는 선택
  - 구하고자 하는 수(`n`)를 1, 2, 3의 합으로 나타낼 수 있는 식의 경우의 수 = dp[n][1] + dp[n][2] + dp[n][3]
  - i ≥ 4에 대해
    - dp[i][1] = dp[i-1][1] = 1
    - dp[i][2] = dp[i-2][1] + dp[i-2][2]
    - dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3]

  [주혜]
  - dp 배열 선언
  - 1, 2, 3 의 조합으로 나타내야 하기 때문에 합이 3 이하인 경우 초기 선언
  - 중복이 아니어야 하기 때문에 오름차순 기준, 조합의 마지막으로 끝나는 수로 구분
  
- 피드백

  [은상]
  - 처음 문제를 보자마자 dp 유형임을 파악 → Good!
  - 하지만 모든 경우의 수를 구해보며 고민해봤지만 결국 점화식을 세우지 못하여 답지 참고
    - `1`로만 이루어진 식의 경우의 수, `1, 2`로 이루어진 식의 경우의 수, `1, 2, 3`으로 이루어진 식의 경우의 수를 나눠서 저장할 생각을 전혀 하지 못했다
    - dp 문제는 꼭 1차원 배열일 필요가 없다는 사실을 항상 기억하자
 
  [주혜]
  - 처음 DFS 풀이 시간초과
    ```java
      import java.util.*;
      import java.io.*;
      public class Q15989 {
          static int answer = 0;
          public static void main(String[] args) throws IOException{
              BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
              StringBuilder sb = new StringBuilder();
              int n = Integer.parseInt(br.readLine());
              for(int i=0; i<n; i++){
                  int target = Integer.parseInt(br.readLine());
                  answer=0;
                  DFS(target,0, 0);
                  sb.append(answer).append("\n");
              }
              System.out.print(sb);
          }
          static void DFS(int target, int sum, int now){
              if(sum==target){
                  answer++;
              }
              if(sum>target) return;
              // 중복 피하기 위한 조건 설정 (오름차순)
              if(now<=1) DFS(target, sum+1, 1);
              if(now<=2) DFS(target, sum+2, 2);
              if(now<=3) DFS(target, sum+3, 3);
          }
      }
    ```
  - 시간초과 후 dp임을 파악
    - (은상: 이틀 연속 잘못된 접근으로 시간초과랑 부쩍 친해진 모습. 코드 작성 전에 시간복잡도 빠르게 굴려보는 습관 들여보는 건 어떨까?)
  - 점화식 세우는 것에 어려움이 있어 답지 참고
  - 실전에 나오면 dfs 풀어서 냈을 듯 ㅠㅠ dp 점화식 세우기 어렵당~! 하지만 킵고잉~
