## 20241105 문제

### 백준 [뱀과 사다리 게임](https://www.acmicpc.net/problem/16928)

- 접근방식

  [은상]
  - 최단 경로 탐색 → BFS
  - `map` 자료 구조를 사용하여 사다리 또는 뱀을 통해 이동하는 조건 추가

  [주혜]
  - BFS 구현
  - 최단 거리 구현이기 때문에 arr, visit 배열 이용하여 방문하지 않았을 경우만 q 추가!
  - 다른 자료구조 사용없이 arr에 각 숫자를 입력해놓고, 뱀과 사다리 존재하는 경우 해당 인덱스에 이동해야하는 곳 값 넣어서 BFS로 구현
  
- 피드백

  [은상]
  - 최대한 복잡하게 문제를 설명해놨지만, 결국 목적지까지 최소 이동 횟수를 구하는 문제임을 파악 → 빠른 문제 유형 파악 Good
  - 사다리 또는 뱀을 통해 이동하는 조건을 처리할 방법을 빠르게 구상 → Good!
 
  [주혜]
  - 냅다 dfs 구현했다가 시간초과 ㅎ
```java
import java.io.*;
import java.util.*;
public class Main {
    static int[] arr = new int[101];
    static boolean[] visit = new boolean[101];
    static Map<Integer, Integer> map = new HashMap<>();
    static int answer = 99;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for(int i=0; i<n+m; i++) {
            st = new StringTokenizer(br.readLine());
            map.put(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        DFS(1,0);
        System.out.print(answer);
    }
    static void DFS(int now, int cnt){
        if(now==100) {
            answer = Math.min(answer, cnt);
            return;
        }
        if(map.containsKey(now)) {
            visit[map.get(now)] = true;
            DFS(map.get(now), cnt);
            return;
        }
        if(cnt>99) return;
        if(answer<=cnt) return;
        for(int i=1; i<=6; i++){
            if(now+i>100) continue;
            if(visit[now+i]&&now+i!=100) continue;
            visit[now+i]=true;
            DFS(now+i, cnt+1);
            visit[now+i]=false;
        }
    }
}
```
- BFS 방식 바꿈 -> 성공!
- 최단거리인데 굳이 DFS 사용하려하지 말자
