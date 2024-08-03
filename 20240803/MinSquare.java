class MinSquare {
    public int minSquare(int[][] sizes) {
        int w = 0;
        int h = 0;
        // [큰, 작] 정렬 -> 넓이 높이가 정해진게 아니고 눕혀도 되기 때문에
        // 한 쌍마다 큰 값 작은 값 정렬 후 h, w 간의 max값 넓이 구함
        for(int i=0; i<sizes.length; i++){
            int a = sizes[i][0];
            int b = sizes[i][1];
            if(a<b) {
                sizes[i][0] = b;
                sizes[i][1] = a;
            }
            w = Math.max(w,sizes[i][0]);
            h = Math.max(h,sizes[i][1]);
        }
        return w*h;
    }
}
//23:56-24:02