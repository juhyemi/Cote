import java.util.*;
class GameMapShortestDistance {
    static int[][] maps;
    static int[] dx = {1,-1,0,0};
    static int[] dy = {0,0,1,-1};
    static int n,m;
    static int[][] visit;
    public int gameMapShortestDistance(int[][] maps) {
        this.maps = maps;
        n = maps.length;
        m = maps[0].length;
        visit = new int[n][m];
        visit[0][0] = 1;
        BFS(0,0);
        if(visit[n-1][m-1]==0) visit[n-1][m-1]--;
        return visit[n-1][m-1];
    }
    static void BFS(int x, int y){
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(x, y));
        while(!q.isEmpty()){
            Point p = q.poll();
            x = p.x;
            y = p.y;
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&visit[nx][ny]==0&&maps[nx][ny]==1){
                    visit[nx][ny] = visit[x][y]+1;
                    q.add(new Point(nx, ny));
                }
            }
        }
    }
}
class Point{
    int x,y;
    Point(int x, int y){
        this.x = x;
        this.y = y;
    }
}