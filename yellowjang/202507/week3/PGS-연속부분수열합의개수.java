import java.util.*;

class Solution {
    public int solution(int[] elements) {
       //시작점을 정해놨다고 가정하고 -> 어디에서 시작하든 상관 없음 ! 
        // 뒤에 끝부분을 얼마나 늘릴 것인가 ? 해당하는 수열의 길이 -1 만큼 뒤를 더 붙여서 구함.
        int total = 0;
        Set<Integer> set = new HashSet<>();
        //더할 수열의 길이 for문
        for(int i=1; i<=elements.length;i++){
            //if 한 자리 짜리라면a
            for(int j=0;j<elements.length;j++){
                //  시작점을 다르게 할 for문  
                int sum =0; 
                for(int k=j;k<j+i;k++){
                    sum+= elements[k%elements.length];
                }
                set.add(sum);
            }
        }
        return set.size();
    }
}
