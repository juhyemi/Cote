import java.util.*;
public class Rank {
    //내가 갈 수 있는 노드 + 나에게 방문하는 노드  == n-1이면 answer++
    static ArrayList<ArrayList<Integer>> graph=new ArrayList<>();
    static boolean[] visit;
    static int[] total;
    static int answer,n;
    public int solution(int n, int[][] results) {
        answer = 0;
        total = new int[n+1];
        this.n = n;
        for(int i=0; i<=n; i++){
            graph.add(new ArrayList<>());
        }
        for(int i=0; i<results.length; i++){
            int a = results[i][0];
            int b = results[i][1];
            graph.get(a).add(b);
        }
        for(int i=1; i<=n; i++){
            visit=new boolean[n+1];
            CHK(i,visit);
        }
        for(int i=1; i<=n; i++){
            if(total[i]==n-1) answer++;
        }

        return answer;
    }
    static void CHK(int idx, boolean[] visit){
        int cnt=0;
        Queue<Integer> q = new LinkedList<>();
        q.add(idx);
        visit[idx]=true;
        while(!q.isEmpty()){
            int st = q.poll();
            for(int i=0; i<graph.get(st).size(); i++){
                if(!visit[graph.get(st).get(i)]){
                    cnt++;
                    total[graph.get(st).get(i)]+=1;
                    visit[graph.get(st).get(i)]=true;
                    q.add(graph.get(st).get(i));
                }
            }
        }
        total[idx]+=cnt;
    }
}