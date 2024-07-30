import java.util.*;
class DoublePriorityQueue {
    public int[] doublePriorityQueue(String[] operations) {
        PriorityQueue<Integer> pq1 = new PriorityQueue<>();
        PriorityQueue<Integer> pq2 = new PriorityQueue<>(Collections.reverseOrder());
        int[] answer = new int[2];
        for(int i=0; i<operations.length; i++){
            String str = operations[i];
            String[] s = str.split(" ");
            if(s[0].equals("I")){
                pq1.add(Integer.parseInt(s[1]));
                pq2.add(Integer.parseInt(s[1]));
            }else if(s[0].equals("D")){
                if(pq2.size()<=0) continue;
                if(s[1].equals("1")){
                    int tmp = pq2.poll();
                    pq1.remove(tmp);
                }else if(s[1].equals("-1")){
                    int tmp = pq1.poll();
                    pq2.remove(tmp);
                }
            }
        }
        if(pq2.size()>0){
            answer[0]=pq2.peek();
            answer[1]=pq1.peek();
        }
        return answer;
    }
}