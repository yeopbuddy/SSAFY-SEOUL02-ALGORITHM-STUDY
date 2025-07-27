import java.util.*; 
class Solution {
    public int solution(int n, int[][] wires) {
       int minDiff = Integer.MAX_VALUE;
        for(int i=0; i<wires.length; i++){
             Map<Integer,List<Integer>> graph = new HashMap<>();
            //하나 없앨 간선 뽑기 ..
            
            for(int j=0; j<wires.length; j++){
                if(j==i) continue;
                int a = wires[j][0];
                int b = wires[j][1];
                graph.putIfAbsent(a, new ArrayList<>());
                graph.putIfAbsent(b, new ArrayList<>());
                
                graph.get(a).add(b);
                graph.get(b).add(a);
            }
            boolean[] visited = new boolean[n+1];
            
            int count = dfs(1, graph, visited);
            
            int other = n - count;
            int diff = Math.abs(count-other);
            minDiff = Math.min(minDiff, diff);
        }
        return minDiff;
    }
    
    int dfs(int node, Map<Integer,List<Integer>> graph, boolean[] visited){
        visited[node] = true;
        int count = 1;
        
        if(!graph.containsKey(node)) return count;
        
        for(int next : graph.get(node)){
            if(!visited[next]){
                count += dfs(next,graph, visited);
            }
        }
        return count;
    }
}
