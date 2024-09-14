// N번째 큰 수
import java.io.*;
import java.util.*;
public class Q2075 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int i=0; i<n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=0; j<n; j++){
                pq.add(Integer.parseInt(st.nextToken()));
            }
        }
        for(int i=1; i<n; i++){
            pq.poll();
        }
        System.out.print(pq.poll());
    }
}