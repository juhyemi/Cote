// 소수 찾기
import java.util.*;
class FindDecimal {
    static int answer, n;
    static String numbers;
    static boolean[] visit; // 한 번 사용한 숫자는 다시 사용 x 위해 visit배열 선언
    static Set<Integer> set = new HashSet<>(); //중복 숫자 걸러내야함
    public int findDecimal(String numbers) {
        this.numbers = numbers;
        answer = 0;
        n = numbers.length();
        // 모든 경우의 수를 따져야 하기 때문에
        // 1자리수~numbers.length자리수 탐색하기 위해 글자 개수만 보냄
        for(int i=0; i<numbers.length(); i++){
            visit = new boolean[n];
            DFS(0, 0, i+1, visit);
        }
        return answer;
    }
    // 만들어진 수, 만들어진 수의 자리수, 목표 자리수, 방문 배열
    static void DFS(int num, int cnt, int target, boolean[] visit){
        // 목표자리수와 만들어진 자리수가 같으면 소수인지 확인
        if(cnt==target){
            // 같은 수 탐색하지 않기 위해 set이용
            if(!set.contains(num)){
                set.add(num);
                CHK(num);
            }
            return;
        }
        // 숫자 무작위로 붙이기 위한 로직
        for(int i=0; i<n; i++){
            // 이미 사용한 숫자면 넘김
            if(visit[i]) continue;
            String next = String.valueOf(num)+String.valueOf(numbers.charAt(i));
            visit[i] = true;
            DFS(Integer.parseInt(next), cnt+1, target, visit);
            visit[i] = false;
        }
    }
    // 소수인지 확인하는 로직
    static void CHK(int number){
        // 0과 1은 소수가 될 수 없음
        if(number==0||number==1) return;
        // 2를 제외한 짝수는 소수가 될 수 없음
        if(number!=2&&number%2==0) return;
        // 3~루트값 까지만 확인하면 된다.
        // 약수개념 이용
        for(int i=3; i<=Math.sqrt(number); i++){
            if(number%i==0) return;
        }
        answer++;
    }
}
// 1:50 ~ 2:20