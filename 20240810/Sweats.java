// 체육복
import java.util.*;
class Sweats {
    public int sweats(int n, int[] lost, int[] reserve) {
        Arrays.sort(lost);
        int answer = 0;
        boolean[] check=new boolean[n+2];
        Arrays.sort(reserve);
        // 체육복 여벌있는 학생 중 잃어버린 학생 확인
        for(int i=0; i<lost.length; i++){
            int k = Arrays.binarySearch(reserve,lost[i]);
            if(k>=0){
                reserve[k]=-1;
            }else{
                check[lost[i]]=true;
            }
        }
        // 잃어버린 학생 기준 왼쪽부터 여벌옷있는 학생있나 확인
        for(int i=0; i<reserve.length; i++){
            int k=reserve[i];
            if(k==-1) continue;
            if(check[k-1]){
                check[k-1] = false;
            }else if(check[k+1])
                check[k+1]=false;
        }
        // check배열로 체육복 있는 학생 수 확인
        for(int i=1; i<=n; i++){
            if(!check[i]) answer++;
        }
        return answer;
    }
}
// 6:45 ~ 7:01