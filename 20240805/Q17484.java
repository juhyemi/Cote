import java.util.*;
import java.io.*;
public class Q17484 {
    //우주선 진행방향별 설정
    static int[] dx = {1,1,1};
    static int[] dy = {-1,0,1};
    //어떤 방향으로 갈지 알아야 하기 때문에 idx 배열 생성
    //0,1,2로 해도 괜찮지만 코드 구현시 더 편할거라 생각
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
        //진행 방향이 정해져 있기 때문에
        //각 출발칸 별로 모든 진행 방향 탐색 
        for(int i=0; i<m; i++){
            for(int j=0; j<3; j++){
                DFS(0,i,d[j], 1, 0);
            }
        }
        System.out.print(answer);
    }
    static void DFS(int x, int y, int idx, int cnt, int cost){
        // 해당 칸 연료값 더해줌
        cost+=arr[x][y];
        // 달 도착하면 최소비용 비교
        if(cnt==n){
            answer = Math.min(answer,cost);
            return;
        }
        // 이전 방향과 다른 방향일 때만 진행
        for(int i=0; i<3; i++){
            if(i==idx) continue;
            int nx = x+dx[i];
            int ny = y+dy[i];
            // map 벗어나는지 확인
            if(nx>=0 && nx<n && ny>=0 && ny<m) DFS(nx, ny, i, cnt+1, cost);
        }

    }
}
//1:24~1:41
