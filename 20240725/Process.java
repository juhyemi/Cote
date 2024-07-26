import java.util.*;
class Solution {
    public int solution(int[] priorities, int location) {
        int start = 0;
        int rank = 1;
        int[] arr = new int[priorities.length];
        for(int i=0; i<priorities.length; i++){
            arr[i] = priorities[i];
        }
        Arrays.sort(arr);
        loop:
        for(int i=9; i>0; i--){
            int idx = Arrays.binarySearch(arr, i);
            if(idx<0) continue;
            int k = start;
            for(int j=0; j<priorities.length; j++,k++){
                if(k==priorities.length) k=0;
                if(priorities[k]==i) {
                    if(k==location) {
                        break loop;
                    }
                    else {
                        rank++;
                        start=k;
                    }
                }
            }
        }
        return rank;
    }
}