import java.util.*; 

class Solution {
    static int[] dr = {-1,1,0,0};
    static int[] dc = {0,0,-1,1};
    static boolean[][] visited;
    static int n, m;
    public int solution(int[][] maps) {
        // 0으로는 지나갈 수 없음
        n = maps.length;
        m = maps[0].length;
        visited = new boolean[n][m];
        return bfs(0,0, maps);
        
    }
    
    int bfs(int r, int c, int[][] maps){
        Queue<int[]> que = new LinkedList<>();
        int cnt = 1;
        que.add(new int[] {r,c});
        visited[r][c] = true;
        boolean isOk = false;
        
        while(!que.isEmpty()){
            int size =que.size();
            for(int i=0; i<size; i++){
                int[] current = que.poll();
                int currR = current[0];
                int currC = current[1];
                if(currR == n-1 && currC == m-1) 
                    return cnt;


                for(int d = 0; d < 4; d++){
                    int nr = currR + dr[d];
                    int nc = currC + dc[d];

                    if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;

                    if(maps[nr][nc] == 0) continue;

                    if(visited[nr][nc]) continue;

                    que.add(new int[] {nr,nc});
                    visited[nr][nc] = true;
                }
            }
            cnt++;
        }
        return -1;
    }
}
