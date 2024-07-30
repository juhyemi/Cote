import java.io.*;
import java.util.*;
public class Q13305 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        // 거리는 n-1이기 때문에 배열 크기 조정
        int[] distance = new int[n-1];
        int[] price = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n-1; i++) distance[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++) price[i] = Integer.parseInt(st.nextToken());
        // int로는 부족할 것 같아서 long으로 선언
        long total = 0;
        long minPrice = price[0];
        for(int i=0; i<n-1; i++){
            if(price[i]<minPrice) minPrice = price[i];
            total += distance[i]*minPrice;
        }
        System.out.println(total);
    }
}