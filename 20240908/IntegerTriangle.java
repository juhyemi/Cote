public class IntegerTriangle {
    public int integerTriangle(int[][] triangle) {
        int answer = 0;
        for(int i=0; i<triangle.length; i++){
            for(int j=0; j<triangle[i].length; j++){
                if(i==0&&j==0) continue;
                else{
                    if(j==0){ //양끝처리
                        triangle[i][j]+=triangle[i-1][0];
                    }else if(j==triangle[i].length-1){
                        triangle[i][j]+=triangle[i-1][triangle[i-1].length-1];
                    }else{
                        triangle[i][j]+=Math.max(triangle[i-1][j-1], triangle[i-1][j]);
                    }
                }
            }
        }
        for(int i:triangle[triangle.length-1]){
            answer = Math.max(answer, i);
        }
        return answer;
    }
}
