//스위치 켜고 끄기
import java.io.*;
import java.util.*;
public class Q1244 {
    static boolean[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine()); //스위치 개수
        arr = new boolean[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            if(st.nextToken().equals("1")) arr[i] = true;
        }
        int sn = Integer.parseInt(br.readLine()); //주어지는 학생 수
        for(int i=0; i<sn; i++){
            st = new StringTokenizer(br.readLine());
            if(st.nextToken().equals("1")) BOY(Integer.parseInt(st.nextToken()));
            else GIRL(Integer.parseInt(st.nextToken()));
        }
        int k = 20;
        for(int i=0; i<arr.length; i++){
            boolean flag = false;
            if(i==k) {
                System.out.println();
                flag = true;
            }
            System.out.print(arr[i]?"1":"0");
            if(i!=k-1) System.out.print(" ");
            if(flag) k+=20;
        }
    }
    static void BOY(int num){
        for(int i=num; i<=arr.length; i+=num){
            arr[i-1] = !arr[i-1];
        }
    }
    static void GIRL(int num){
        arr[num-1] = !arr[num-1];
        int before = num-1;
        int after = num+1;
        while(true){
            if(before<1||after>arr.length) return;
            if(arr[before-1]==arr[after-1]){
                arr[before-1] = !arr[before-1];
                arr[after-1] = !arr[after-1];
                before--;
                after++;
            }else return;
        }
    }
}