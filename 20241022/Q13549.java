import java.io.*;
import java.util.*;
// 숨바꼭질 3
public class Q13549 {
    static int answer = Integer.MAX_VALUE;
    static boolean[] visit = new boolean[100001];
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        BFS(n,k,0);
        System.out.print(answer);
    }
    static void BFS(int n,int k,int time){
        Queue<Route> q = new LinkedList<>();
        q.add(new Route(n,time));
        while(!q.isEmpty()){
            Route r = q.poll();
            visit[r.x] = true;
            if(r.x==k) {
                answer=r.t;
                break;
            }
            if(r.x*2<=100000&&!visit[r.x*2]) q.add(new Route(r.x*2, r.t));
            if(r.x-1>=0&&!visit[r.x-1]) q.add(new Route(r.x-1, r.t+1));
            if(r.x+1<=100000&&!visit[r.x+1]) q.add(new Route(r.x+1, r.t+1));
        }
    }
}
class Route{
    int x;
    int t;
    Route(int x, int t){
        this.x = x;
        this.t = t;
    }
}
