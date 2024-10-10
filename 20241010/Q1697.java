// 숨바꼭질
//3:56~3:59 - 시간초과
//4:12
import java.util.*;
import java.io.*;
public class Q1697 {
    static int[] visit;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        visit = new int[100001];
        if(n==k) {
            System.out.println(0);
            return;
        }
        BFS(n,k);
        System.out.print(visit[k]);
    }
    static void BFS(int n, int k){
        Queue<Integer> q = new LinkedList<>();
        q.add(n);
        while(!q.isEmpty()){
            int now = q.poll();
            if(visit[k]!=0) break;
            if(now+1<=100000&&visit[now+1]==0){
                q.add(now+1);
                visit[now+1] = visit[now]+1;
            }
            if(now-1>=0&&visit[now-1]==0){
                q.add(now-1);
                visit[now-1] = visit[now]+1;
            }
            if(now*2<=100000&&visit[now*2]==0){
                q.add(now*2);
                visit[now*2] = visit[now]+1;
            }
        }
    }
}
