// 조이스틱
import java.util.*;
public class JoyStick {
    class joyStick {
        public int solution(String name) {
            int answer = 0;
            int index;
            int move = name.length()-1;
            for(int i=0; i<name.length(); i++){
                index=i+1;
                // A, Z중 더 가까운 값
                answer+=Math.min(name.charAt(i)-'A','Z'-name.charAt(i)+1);
                while(index < name.length() && name.charAt(index) == 'A'){
                    index++;
                }
                move = Math.min(move, i * 2 + name.length() - index);
                move = Math.min(move, (name.length() - index) * 2 + i);
            }
            return answer+move;
        }
    }
}
