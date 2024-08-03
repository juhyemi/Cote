import java.util.*;
class HIndex {
    public int hIndex(int[] citations) {
        int answer = 0;
        Arrays.sort(citations);
        //h이상의 수기 때문에 배열 전체 길이와 배열에서 h수 뺀 곳의 값이 같으면 h-index
        for(int i=0; i<citations.length; i++){
            int h = citations.length-i;
            if(citations[i]>=h){
                answer = h;
                break;
            }
        }
        return answer;
    }
}
//18:28 ~ 18:41