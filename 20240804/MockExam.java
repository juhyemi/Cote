//모의고사
class MockExam {
    public int[] mockExam(int[] answers) {
        int[] answer1 = {1,2,3,4,5};
        int[] answer2 = {2,1,2,3,2,4,2,5};
        int[] answer3 = {3,3,1,1,2,2,4,4,5,5};
        int s1=0,s2=0,s3=0; //각 맞은개수
        int c1=0,c2=0,c3=0; //각 count
        for(int i=0; i<answers.length; i++){
            int a = answers[i];
            if(c1==answer1.length) c1=0;
            if(c2==answer2.length) c2=0;
            if(c3==answer3.length) c3=0;
            if(a==answer1[c1]) s1++;
            if(a==answer2[c2]) s2++;
            if(a==answer3[c3]) s3++;
            c1++;c2++;c3++;
        }
        //최대값
        int max = Math.max(s1,Math.max(s2,s3));
        String tmp = "";
        if(s1==max) tmp+="1";
        if(s2==max) tmp+="2";
        if(s3==max) tmp+="3";
        int[] answer = new int[tmp.length()];
        for(int i=0; i<tmp.length(); i++) answer[i] = tmp.charAt(i)-'0';
        return answer;
    }
}
//17:06~17:16