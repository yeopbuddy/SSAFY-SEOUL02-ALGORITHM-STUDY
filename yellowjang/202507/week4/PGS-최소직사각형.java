class Solution {
    public int solution(int[][] sizes) {
        //일단 가로를 탐색하면서 , 가장 큰 값을 찾고,
        // 세로를 탐색하면서 큰 값을 찾음. 
        // int minW = 1001;
        // int minH = 1001;
        int maxW = 0; 
        int maxH = 0;
        for(int i=0; i<sizes.length; i++){
            int w = Math.max(sizes[i][0], sizes[i][1]);
            int h = Math.min(sizes[i][0], sizes[i][1]);
            
            maxW = Math.max(maxW, w);
            maxH = Math.max(maxH, h);
        }
        

        return maxW*maxH;
    }
}
