// 뱀과 사다리 게임
import java.io.*;
import java.util.*;
public class Q16928 {
    static int[] arr = new int[101];
    static int[] visit = new int[101];
    static int answer = 99;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()); //사다리 수
        int m = Integer.parseInt(st.nextToken()); // 뱀 수
        for(int i=1; i<=100; i++){
            arr[i] = i;
        }
        for(int i=0; i<n+m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr[a]=b;
        }
        BFS(1);
        //return 주사위 최소 던지는 수
        System.out.print(answer);
    }
    static void BFS(int start){
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        while(!q.isEmpty()){
            int check = q.poll();
            for(int i=1; i<=6; i++){
                int now = check+i;
                //범위확인
                if(now>100) continue;
                //최단거리이기 때문에 방문안했을 경우만
                if(visit[arr[now]]==0){
                    q.add(arr[now]);
                    visit[arr[now]]=visit[check]+1;
                }
                if(arr[now]==100) {
                    answer=visit[100];
                    return;
                }
            }
        }
    }
}
