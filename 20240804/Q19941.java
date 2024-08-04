//햄버거 분배
import java.util.*;
import java.io.*;
public class Q19941 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()); //식탁길이
        int k = Integer.parseInt(st.nextToken());//햄버거 선택가능 거리
        boolean[] check = new boolean[n];
        int answer = 0;
        String s = br.readLine();
        for(int i=0; i<n; i++){
            // 사람이면
            if(s.charAt(i)=='P'){
                // 허용 가능한 곳 중 앞에서부터 가장 먼저 있는 햄버거 탐색
                for(int j=i-k; j<=i+k; j++){
                    if(j>=0&&j<n){
                        //check로 해당 햄버거 먹었는지 확인
                        if(s.charAt(j)=='H'&&!check[j]){
                            check[j] = true;
                            answer++;
                            break;
                        }
                    }
                }
            }
        }
        System.out.print(answer);
    }
}
//16:53~17:03