import java.util.*;
public class FurthestNode {
    class furthestNode {
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
}
