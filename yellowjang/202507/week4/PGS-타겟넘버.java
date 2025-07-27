class Solution {
    public int solution(int[] numbers, int target) {
        return dfs(numbers, target, 0, 0);
    }
    
    int dfs(int[] numbers, int target, int index, int currentSum){
        if(index == numbers.length){
            return currentSum ==target?1 : 0 ;
        }
        
        int add = dfs(numbers, target, index + 1, currentSum + numbers[index]);
        int substract = dfs(numbers, target, index+1, currentSum-numbers[index]);
        
        return add + substract;
    }
}
