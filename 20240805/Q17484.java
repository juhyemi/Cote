import java.util.*;
import java.io.*;
public class Q17484 {
    static int[] dx = {1,1,1};
    static int[] dy = {-1,0,1};
    static int[] d = {0,1,2};
    static int[][] arr;
    static int n,m,answer;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n][m];
        answer = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < m; j++){
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<3; j++){
                DFS(0,i,d[j], 1, 0);
            }
        }
        System.out.print(answer);
    }
    static void DFS(int x, int y, int idx, int cnt, int cost){
        cost+=arr[x][y];
        if(cnt==n){
            answer = Math.min(answer,cost);
            return;
        }
        for(int i=0; i<3; i++){
            if(i==idx) continue;
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m) DFS(nx, ny, i, cnt+1, cost);
        }

    }
}
//1:24~1:41