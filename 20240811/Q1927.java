// 최소 힙
import java.util.*;
import java.io.*;
public class Q1927 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<n; i++){
            int k = Integer.parseInt(br.readLine());
            if(k==0) {
                if(pq.isEmpty()) sb.append(0).append("\n");
                else sb.append(pq.poll()).append("\n");
            }else pq.add(k);
        }
        System.out.println(sb);
    }
}
// 2:51~2:54
