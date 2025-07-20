class Solution {
    public int solution(int[] citations) {
      //  해당하는 숫자(x)를 citations 를 순회하면서 x 이상의 값이 x개 이상이어야 함. -> 최댓값 갱신
        int maxAns = 0;
        int current = 0;
        int cnt=0;
        while(true){
            if(current==citations.length-1) break;
            
            for(int i=0; i<citations.length;i++){ 
                if(citations[current] <= citations[i]){
                    cnt++;
                }
            } // 배열 탐색했음 . 
            
            if(cnt<=citations[current]) maxAns = Math.max(maxAns,cnt);
            cnt=0;
            current++;
           
        }
       return maxAns;
    }
}
