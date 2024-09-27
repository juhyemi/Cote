class TargetNumber {
    static int answer = 0;
    static int target = 0;
    static int[] numbers;
    public int targetNumber(int[] numbers, int target) {
        this.target = target;
        this.numbers = numbers;
        DFS(0,0);
        return answer;
    }
    static void DFS(int sum, int cnt){
        if(cnt==numbers.length){
            if(sum==target) answer++;
            return;
        }
        DFS(sum+numbers[cnt], cnt+1);
        DFS(sum-numbers[cnt], cnt+1);
    }
}