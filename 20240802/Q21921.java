import java.util.*;
import java.io.*;
public class Q21921 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        boolean check = true;
        for(int i = 0; i < n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
            if(arr[i] > 0){check=false;}
        }
        if(check){
            System.out.print("SAD");
        }else{
            int max = 0;
            int period = 1;
            for(int i = 0; i < x; i++){
                max += arr[i];
            }
            int chk = max;
            for(int i=x; i<n; i++){
                chk-=arr[i-x];
                chk+=arr[i];
                if(chk>max){
                    period=1;
                    max=chk;
                }else if(chk==max) period++;
            }
            System.out.println(max);
            System.out.println(period);
        }
    }
}

//17:39-17:57
