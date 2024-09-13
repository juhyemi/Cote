import java.util.*;
class OnTheWayToSchool {
        static boolean[][] map;
        static int m,n,answer;
        static int[] dx={0,-1};//좌 상
        static int[] dy={-1,0};
        static int[][] visit;
        public int solution(int m, int n, int[][] puddles) {
            answer = 0;
            this.m = m;
            this.n = n;
            map = new boolean[m][n];
            visit = new int[m][n];
            for(int i=0; i<puddles.length; i++){
                map[puddles[i][0]-1][puddles[i][1]-1]=true;
            }
            visit[0][0]=1;
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(map[i][j]) continue;
                    if(i==0&&j==0) continue;
                    for(int k=0; k<2; k++){
                        int nx=i+dx[k];
                        int ny=j+dy[k];
                        if(nx>=0&&ny>=0&&nx<m&&ny<n){
                            visit[i][j]+=visit[nx][ny];
                        }
                        visit[i][j]%= 1000000007;
                    }
                }
            }
            return visit[m-1][n-1];
        }
}
