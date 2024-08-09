// IF문 좀 대신 써줘
import java.util.*;
import java.io.*;
public class Q19637 {
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        Pair[] arr = new Pair[n];
        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            int k = Integer.parseInt(st.nextToken());
            arr[i] = new Pair(s, k);
        }
        for(int i=0; i<m; i++){
            int tmp = Integer.parseInt(br.readLine());
            FindName(arr, tmp);
        }
        System.out.println(sb);
    }
    // 이분탐색, sort 하면 안된다.
    static void FindName(Pair[] arr, int k){
        int st = 0;
        int end = arr.length-1;
        while(st<=end){
            int mid = (st+end)/2;
            if(arr[mid].score>=k) end=mid-1;
            else st=mid+1;
        }
        sb.append(arr[end+1].name).append("\n");
    }
}
class Pair{
    String name;
    int score;
    Pair(String name, int score){
        this.name = name;
        this.score = score;
    }
}
// 5:43 ~ 6:14