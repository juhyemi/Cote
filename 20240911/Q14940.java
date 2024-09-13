//쉬운 최단거리
import java.util.*;
import java.io.*;
public class Q14940 {
    static int n,m;
    static int[][] map, visit;
    static Queue<pp> q = new LinkedList<>();
    static int[] dx = {0,0,1,-1};
    static int[] dy = {1,-1,0,0};
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][m];
        visit = new int[n][m];
        for(int i=0; i<n; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j]==2) {
                    q.add(new pp(i,j));
                }
            }
        }
        bfs();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(visit[i][j]==0&&map[i][j]==1) {
                    visit[i][j] = -1;
                }
                System.out.print(visit[i][j]+" ");
            }
            System.out.println();
        }
    }
    static void bfs() {
        while(!q.isEmpty()) {
            pp tmp = q.poll();
            int x = tmp.x;
            int y = tmp.y;
            for(int i =0;i<4;i++) {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && map[nx][ny]==1 && visit[nx][ny]==0) {
                    q.add(new pp(nx,ny));
                    visit[nx][ny] = visit[x][y]+1;
                }
            }
        }

    }
}
class pp{
    int x,y;
    pp(int x, int y){
        this.x = x;
        this.y = y;
    }
}