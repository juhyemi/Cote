//회전초밥
//4;40~5:35
import java.util.*;
import java.io.*;
public class Q2531 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()); //접시수
        int d = Integer.parseInt(st.nextToken()); //초밥가짓수
        int k = Integer.parseInt(st.nextToken()); //연속먹는접시수
        int c = Integer.parseInt(st.nextToken()); //쿠폰번호
        int[] arr = new int[n];
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < n; i++) arr[i]=Integer.parseInt(br.readLine());
        for(int i=0; i<k; i++){
            map.put(arr[i], map.getOrDefault(arr[i], 0)+1);
        }
        int answer = map.size();
        if(!map.containsKey(c)) answer++;
        int minus = 0;
        for(int i=k; i<n+k; i++){
            int idx = i;
            if(idx>=arr.length) idx-=arr.length;
            map.put(arr[idx], map.getOrDefault(arr[idx], 0)+1);
            map.put(arr[minus], map.get(arr[minus])-1);
            if(map.containsKey(arr[minus])&&map.get(arr[minus])==0) map.remove(arr[minus]);
            int cnt = map.size();
            if(!map.containsKey(c)) cnt++;
            answer = Math.max(cnt, answer);
            minus++;
            if(minus>=arr.length) minus=0;
        }
        System.out.print(answer);
    }
}
