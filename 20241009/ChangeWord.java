//단어 변환
//3:35~3:48
class ChangeWord {
    static int answer=0;
    static boolean[] visit;
    public int changeWord(String begin, String target, String[] words) {
        boolean flag = false; // 같은 단어 있나 확인용
        for(int i=0; i<words.length; i++){
            if(target.equals(words[i])){
                flag = true;
                break;
            }
        }
        visit = new boolean[words.length];
        if(flag) DFS(begin, target, 0, words);

        return answer;
    }
    static void DFS(String begin, String target, int cnt, String[] words){
        if(begin.equals(target)){
            answer = cnt;
            return;
        }
        for(int i=0; i<words.length; i++){
            if(visit[i]) continue;
            int k = 0; //한개만 다른지 확인용
            for(int j=0; j<words[i].length(); j++){
                if(begin.charAt(j)!=words[i].charAt(j)) k++;
            }
            if(k==1){
                visit[i]=true;
                DFS(words[i], target, cnt+1, words);
                visit[i]=false;
            }
        }
    }
}