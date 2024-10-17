import java.util.*;
class EntryScreening {
    public long entryScreening(int n, int[] times) {
        long answer = 0;
        Arrays.sort(times);
        long left = 1; // 최소가 1이상이기 때문
        long right = times[times.length-1]*(long)n;
        while(left<=right){
            long mid = (left+right)/2;
            long done = 0;
            for(int i=0; i<times.length; i++) done += mid/times[i]; // 전체 입국심사관이 확인할 수 있는 사람 수
            if(done<n) left=mid+1; //시간 부족하니까 left 증가
            else{
                answer=mid;
                right=mid-1; // 더 적은 시간으로 할 수 있는지 확인하기 위해 right 감소
            }
        }
        return answer;
    }
}