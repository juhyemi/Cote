import java.util.*;
class Scoville {
    public int scoville(int[] scoville, int K) {
        PriorityQueue<Integer> q = new PriorityQueue<>();
        int answer = 0;
        for(int i:scoville) q.offer(i);
        while(q.peek()<K){
            if(q.size()==1){
                answer=-1;
                break;
            }
            int a = q.poll();
            int b = q.poll();
            q.add(a+2*b);
            answer++;
        }
        return answer;
    }
}