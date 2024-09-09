//DFS와 BFS
import java.util.*;
import java.io.*;
public class Q1260 {
    static int n,m,v;
    static int[][] map;
    static boolean[] visit;
    static StringBuilder sb;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());//정점개수
        m = Integer.parseInt(st.nextToken());//간선개수
        v = Integer.parseInt(st.nextToken());//시작점
        sb = new StringBuilder();
        visit = new boolean[n+1];
        map = new int[n+1][n+1];
        for(int i=0; i<m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            map[a][b] = 1;
            map[b][a] = 1;
        }
        dfs(v);
        sb.append("\n");
        visit = new boolean[n+1];
        bfs(v);
        System.out.print(sb);
    }
    static void dfs(int v) {
        sb.append(v).append(" ");
        visit[v] = true;
        for(int i=1;i<=n; i++) {
            if(map[v][i]==1 && !visit[i]) {
                dfs(i);
            }
        }
    }
    static void bfs(int v) {
        Queue<Integer> q = new LinkedList<>();
        q.add(v);
        while(!q.isEmpty()) {
            int poll = q.poll();
            visit[poll] = true;
            sb.append(poll).append(" ");
            for(int i=1; i<=n; i++) {
                if(map[poll][i]==1 && !visit[i]) {
                    q.add(i);
                    visit[i] = true;
                }
            }
        }
    }
}
