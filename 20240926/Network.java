// 네트워크
//3:20-3:30
import java.util.*;
class Network {
    static boolean[] visit;
    public int network(int n, int[][] computers) {
        int answer = 0;
        visit = new boolean[n];
        for(int i=0; i<n; i++){
            if(visit[i]) continue;
            BFS(i, computers);
            answer++;
        }
        return answer;
    }
    static void BFS(int st, int[][] computers){
        Queue<Integer> q = new LinkedList<>();
        q.add(st);
        while(!q.isEmpty()){
            int start = q.poll();
            visit[start] = true;
            for(int i=0; i<computers[start].length; i++){
                if(computers[start][i]==1&&!visit[i]) q.add(i);
            }
        }
    }
}