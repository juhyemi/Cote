// 큰 수 만들기
import java.util.*;
public class MakeBigNum {
    class makeBigNum {
        public String solution(String number, int k) {
            Stack<Character> st = new Stack<>();
            for(int i=0; i<number.length(); i++){
                while(!st.isEmpty()&&k>0&&st.peek()<number.charAt(i)){
                    st.pop();
                    k--;
                }
                st.push(number.charAt(i));
            }
            if(k>0){
                while(k!=0){
                    st.pop();
                    k--;
                }
            }
            StringBuilder sb = new StringBuilder();
            for(char ch:st) sb.append(ch);
            return sb.toString();
        }
    }
}
