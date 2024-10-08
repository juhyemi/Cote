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
            // 좌우 이동 횟수의 최소값을 계산
            // 1. 현재까지 이동한 거리(i) + 뒤로 돌아서 처음으로 가는 거리(name.length() - index)
            move = Math.min(move, i * 2 + name.length() - index);
            // 2. 반대로 뒤에서 앞으로 가는 경우의 거리((name.length() - index) * 2 + i)
            move = Math.min(move, (name.length() - index) * 2 + i);
            }
            return answer+move;
        }
    }
}
