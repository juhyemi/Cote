## 20241023 문제

### 프로그래머스 [가장 먼 노드](https://school.programmers.co.kr/learn/courses/30/lessons/49189)

- 접근방식

  [은상]
  - 일반적인 최단 경로 탐색
  - 하지만 각 노드에서 1번 노드로부터 떨어진 거리를 확인하며, 그 거리값이 최대일 때 최대 거리값의 총 개수를 출력
  
  [주혜]
 - BFS 탐색으로 거리값 최대 갱신
  import java.util.*;
class Solution {
    static ArrayList<ArrayList<Integer>>  map = new ArrayList<>();
    static int max;
    static boolean[] visit;
    static int[] cnt;
    public int solution(int n, int[][] edge) {
        for(int i=0; i<=n; i++){
            map.add(new ArrayList<Integer>());
        }
        visit=new boolean[n+1];
        cnt=new int[n+1];
        int answer=0;
        max=0;
        for(int i=0; i<edge.length; i++){
            int a=edge[i][0];
            int b=edge[i][1];
            map.get(a).add(b);
            map.get(b).add(a);
        }
        BFS(n,1);
        for(int i=0; i<=n; i++){
            if(cnt[i]==max) answer++;
        }
        return answer;
    }
    static void BFS(int n, int start){
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        while(!q.isEmpty()){
            int st = q.poll();
            visit[st]=true;
            for(int i=0; i<map.get(st).size(); i++){
                int k = map.get(st).get(i);
                if(!visit[k]){
                    q.add(k);
                    visit[k]=true;
                    cnt[k] = cnt[st]+1;
                    if(max<cnt[k]) max=cnt[k];
                }
            }
        }
    }
}
  
- 피드백

  [은상]
  - 큰 고민없이 빠르게 접근 Idea 구상 → Good!
  - 삽질 포인트 (너 왜 그래?)
    - `q.first().front` (X) → `q.front().first`
    - `q.first().second` (X) → `q.frint().second`
    - `q.pop()` 빼먹으면 무한루프 시간초과
 
  [주혜]
  - 전에 풀었던 유형으로 쉽게 접근하고 풀이할 수 있었음
  
  
