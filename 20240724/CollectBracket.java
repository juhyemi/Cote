import java.util.*;
class CollectBracket {
    boolean solution(String s) {
        boolean answer = true;
        Stack<Character> stack = new Stack<>();
        for(int i = 0; i< s.length(); i++){
            char k = s.charAt(i);
            if(k == '('){
                stack.push(k);
            }else if(k == ')'){
                if(!stack.isEmpty()){
                    stack.pop();
                }else{
                    answer = false;
                    break;
                }
            }

        }
        if(!stack.isEmpty()) {
            answer = false;
        }
        return answer;
    }
}