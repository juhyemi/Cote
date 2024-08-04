// 수 이어쓰기
import java.io.*;
public class Q1515 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String number = br.readLine();
        // 1부터 완전탐색 해야함
        String answer = "1";
        // idx는 number이랑 같으면 증가해야하기 때문에 따로 빼고 for문이 아닌 while문을 돌림
        int idx = 0;
        loop:
        while(true){
            for(int j=0; j<answer.length(); j++){
                // 기준 숫자와 주어진 number의 수가 하나라도 같으면 다음 수를 비교해야하기 때문에 idx증가
                if(number.charAt(idx)==answer.charAt(j)) idx++;
                if(idx==number.length()) break loop;
            }
            // number 수와 맞던 아니던 기준 숫자는 증가 시켜줘야함.
            answer = String.valueOf(Integer.parseInt(answer)+1);
        }
        System.out.println(answer);
    }
}
// 1:30~1:42