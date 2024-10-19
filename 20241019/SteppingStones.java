// 징검다리
import java.util.*;
class SteppingStones {
    public int steppingStones(int distance, int[] rocks, int n) {
        int answer = 0;
        Arrays.sort(rocks);
        int min = 1;
        int max = distance;
        int[] range = new int[rocks.length+1]; // 돌 사이의 거리
        range[0]=rocks[0];
        range[rocks.length] = distance-rocks[rocks.length-1];
        for(int i=1; i<rocks.length; i++) range[i]=rocks[i]-rocks[i-1];

        while(min<=max){
            int mid = (min+max)/2;
            int stone = 0; // 없앨 돌 개수
            int sum = 0;
            for(int i=0; i<range.length; i++){
                sum+=range[i];
                if(sum<mid){
                    stone++;
                    continue;
                }
                sum = 0;
            }
            if(stone>n){
                max = mid-1;
            }else{
                min = mid+1;
                answer = Math.max(answer, mid);
            }
        }
        return answer;
    }
}