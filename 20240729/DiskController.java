import java.util.*;
class DiskController {
    public int diskController(int[][] jobs) {
        int answer = 0;
        Arrays.sort(jobs,new Comparator<int[]>(){
            @Override
            public int compare(int[] o1, int[] o2){
                if(o1[0]==o2[0]) return o1[1]-o2[1];
                return o1[0]-o2[0];
            }
        });
        //요청시간, 수행시간 순 정렬
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1,o2)->o1[1]-o2[1]);
        // jobs가 요청시간으로 정렬되어 있는 상태기 때문에 여기서는 끝나는 시간으로 정렬
        int cnt =0, idx=0, end=0;
        while(cnt<jobs.length){
            // 요청 pq에 넣음
            while(idx<jobs.length&&jobs[idx][0]<=end){
                pq.add(jobs[idx]);
                idx++;
                if(idx==jobs.length) break;
            }
            // 대기가 없는데 아직 job이 남은 경우
            if(pq.isEmpty()&&idx<jobs.length){
                pq.add(jobs[idx]);
                // 아직 작업을 하기 전이기 때문에 요청시간을 end로 바꿔줌
                end=jobs[idx][0];
                idx++;
            }
            // 대기가 있을 때 수행
            if(!pq.isEmpty()){
                int[] now = pq.poll();
                answer+=end+now[1]-now[0]; //대기시간+수행시간
                end+=now[1];
                cnt++;
            }
        }
        return answer/jobs.length;
    }
}
