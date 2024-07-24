import java.util.*;
import java.io.*;
public class Q20125 {
    static int[] dx = {0,0,1,-1};//왼, 오, 아래, 위
    static int[] dy = {-1,1,0,0};
    static StringBuilder sb = new StringBuilder();
    static int hx,hy,mx,my;
    static boolean head=false;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st;
        char[][] map = new char[n][n];
        for(int i=0; i<n; i++){
            String s = br.readLine();
            for(int j=0; j<n; j++){
                map[i][j] = s.charAt(j);
            }
        }
        loop:
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(map[i][j]=='*'){
                    FINDHEART(i,j,map,n);
                }
                if(head) break loop;
            }
        }
        FINDARM(map, n);
        FINDTWIN(map, n);
        System.out.print(sb);


    }
    static void FINDHEART(int x, int y, char[][] map,int n){
        for(int i =0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=n||map[nx][ny]=='_'){
                return;
            }
        }
        hx=x;
        hy=y;
        sb.append((x+1)+" "+(y+1)+"\n");
        head=true;
    }
    static void FINDARM(char[][] map, int n){
        int x=hx; int y=hy; int cnt = 0;
        while(true){
            int nx=x+dx[0];
            int ny=y+dy[0];
            if(nx>=0&&ny>=0&&nx<n&&ny<n&&map[nx][ny]=='*') {
                cnt++;
                x=nx;
                y=ny;
            }
            else{
                sb.append(cnt+" ");
                break;
            }
        }
        x=hx; y=hy; cnt=0;
        while(true){
            int nx=x+dx[1];
            int ny=y+dy[1];
            if(nx>=0&&ny>=0&&nx<n&&ny<n&&map[nx][ny]=='*'){
                cnt++;
                x=nx;
                y=ny;
            }
            else{
                sb.append(cnt+" ");
                break;
            }
        }
    }
    static void FINDTWIN(char[][] map, int n){
        int x=hx; int y=hy; int cnt=0;
        while(true){
            int nx=x+dx[2];
            int ny=y+dy[2];
            if(nx>=0&&ny>=0&&nx<n&&ny<n&&map[nx][ny]=='*'){
                cnt++;
                x=nx;
                y=ny;
            }else {
                sb.append(cnt+" ");
                mx=x;
                my=y;
                break;
            }
        }
        FINDLAG(map,n);
    }
    static void FINDLAG(char[][] map, int n){
        int x = mx+1;
        int y = my-1;
        int cnt=1;
        while(true) {
            int nx = x + dx[2];
            int ny = y + dy[2];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && map[nx][ny] == '*') {
                cnt++;
                x = nx;
                y = ny;
            } else {
                sb.append(cnt + " ");
                break;
            }
        }
        x=mx+1;
        y=my+1;
        cnt=1;
        while(true){
            int nx=x+dx[2];
            int ny=y+dy[2];
            if(nx>=0&&ny>=0&&nx<n&&ny<n&&map[nx][ny]=='*'){
                cnt++;
                x=nx;
                y=ny;
            }else{
                sb.append(cnt+" ");
                break;
            }
        }
    }
}
