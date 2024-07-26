//등수구하기
import java.util.*;
import java.io.*;
public class Q1205 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());
        int size = Integer.parseInt(st.nextToken());
        int answer = 1;
        if(n==0) {
            System.out.println(answer);
            return;
        }
        st = new StringTokenizer(br.readLine());
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int same = 0;
        for(int i=0; i<n; i++){
            int tmp = Integer.parseInt(st.nextToken());
            if(tmp==p) same++;
            pq.add(tmp);
        }
        while(true){
            if(answer>size){
                answer=-1;
                break;
            }
            if(pq.size()==0) break;
            int tmp = pq.poll();
            if(tmp>p) answer++;
            else if(tmp<p) break;
            else if(tmp==p){
                if(answer+same>size){
                    answer=-1;
                }
                break;
            }
        }
        System.out.println(answer);
    }
}
